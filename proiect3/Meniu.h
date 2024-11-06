#ifndef MENIU_H
#define MENIU_H

#include <unordered_map>
#include <iostream>
using namespace std;
template<typename T>
class Meniu {
private:
    unordered_map<int, T*> produse;
    static int index;

public:
    Meniu() {}

    ~Meniu() {
        for (auto& [id, produs] : produse) {
            delete produs;
        }
    }

    void adaugaProdus(T* produs) {
        produse[index++] = produs;
    }

    T* obtineProdus(int id) const {
        auto it = produse.find(id);
        if (it != produse.end()) {
            return it->second;
        }
        return nullptr;
    }

    void vindeProdus(int id) {
        produse.erase(id);
    }

    friend ostream& operator<<(ostream& os, const Meniu& meniu) {
        for (const auto& [id, produs] : meniu.produse) {
            if (produs) {
                os << "ID: " << id << "\n";
                os << *produs << "\n";
            }
        }
        return os;
    }

    Meniu& operator+=(T* produs) {
        adaugaProdus(produs);
        return *this;
    }
};

template<typename T>
int Meniu<T>::index = 1;

#endif // MENIU_H
