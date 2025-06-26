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
    std::vector<Cellule> table;
};

#endif //HASHMAP_H
