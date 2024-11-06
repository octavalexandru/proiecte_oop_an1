//
// Created by octav on 28/05/2024.
//

#include "Comanda_Online.h"

Comanda_Online::Comanda_Online(const std::unordered_map<int, std::vector<Ingredient>>& ingrediente, double distanta)
        : Pizza(ingrediente), distanta(distanta) {}

double Comanda_Online::calc_pret() const {
    double pret = Pizza::calc_pret();
    if (distanta < 0) {
        throw std::runtime_error("Distanta nu poate fi negativa");
    }
    pret += (distanta / 10) * 0.05 * pret;
    return pret;
}

void Comanda_Online::afisare(std::ostream& os) const {
    Pizza::afisare(os);
    os << "Distanta: " << distanta << " km\n";
    os << "Pret total cu livrare: " << calc_pret() << "\n";
}