//
// Created by Hugo Desjardins on 2025-06-26.
//

#ifndef HASHMAP_H
#define HASHMAP_H
#include <functional>

template <typename K, typename V, typename Hash = std::hash<K>>
class HashMap {
    enum Etat {
        Libre,
        Occupe,
        Efface
    };
    struct Cellule {
        K cle;
        V valeur;
        Etat etat;

        Cellule() : etat(Etat::Libre) {}
        //1:01:02 HEURE TD
    };
public:
    HashMap();
    void inserer(const K& cle, const V& valeur);
    const V& lire(const K& cle) const;
    void supprimer(const K& cle);
private:
    size_t index(const K& cle) const;

private:
    size_t capacite;
    size_t cardinal;
    Hash fonctionHash;
    std::vector<Cellule> table;
};

template<typename K, typename V, typename Hash>
HashMap<K, V, Hash>::HashMap() : capacite(13), cardinal(0), fonctionHash(), table(capacite) {
}

template<typename K, typename V, typename Hash>
void HashMap<K, V, Hash>::inserer(const K &cle, const V &valeur) {
    size_t idx = index(cle);
    if (table.at(idx).etat == Etat::Libre) {
        table.at(idx).cle = cle;
        table.at(idx).valeur = valeur;
        table.at(idx).etat = Etat::Occupe;
        ++cardinal;
    }
}

template<typename K, typename V, typename Hash>
const V & HashMap<K, V, Hash>::lire(const K &cle) const {
    size_t idx = index(cle);
    if (table.at(index).etat == Etat::Occupe) return table.at(index).valeur;
    else throw std::invalid_argument("Lire: clé absente");
}

template<typename K, typename V, typename Hash>
void HashMap<K, V, Hash>::supprimer(const K &cle) {
    size_t idx = index(cle);
    if (table.at(idx).etat == Etat::Occupe) {
        table.at(idx).etat = Etat::Efface;
        -- cardinal;
    }
}

template<typename K, typename V, typename Hash>
size_t HashMap<K, V, Hash>::index(const K &cle) const {
    size_t index = fonctionHash(cle)%capacite;
    size_t collision = 1;
    while (table.at(index).etat != Etat::Libre && table.at(index).cle != cle) {
        index = (index + (collision * collision)) % capacite;
        ++collision;
    }
    return index;
}

#endif //HASHMAP_H
