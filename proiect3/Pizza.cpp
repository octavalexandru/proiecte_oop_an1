//
// Created by octav on 27/05/2024.
//

#include "Pizza.h"

const double Pizza::manopera = 10.0;


double Pizza::calc_pret() const {
    double pret = 0.0;
    for (const auto& [id, listaIngrediente] : ingrediente) {
        for (const auto& ingredient : listaIngrediente) {
            pret += ingredient.calc_pret();
        }
    }
    return pret + get_manopera();
}

void Pizza::afisare(std::ostream& os) const {
    os << "Pizza: \n";
    for (const auto& [id, listaIngrediente] : ingrediente) {
        os << "ID: " << id << "\n";
        for (const auto& ingredient : listaIngrediente) {
            os << ingredient << "\n";
        }
    }
    os << "Pret: " << calc_pret() << "\n";
}

istream& operator>>(istream& is, Pizza& pizza) {
    int numarIngrediente;
    is >> numarIngrediente;
    for (int i = 0; i < numarIngrediente; ++i) {
        int id;
        is >> id;
        int numar;
        is >> numar;
        vector<Ingredient> listaIngrediente;
        for (int j = 0; j < numar; ++j) {
            Ingredient ingredient("", 0, 0);
            is >> ingredient;
            listaIngrediente.push_back(ingredient);
        }
        pizza.ingrediente[id] = listaIngrediente;
    }
    return is;
}

ostream& operator<<(ostream& os, const Pizza& pizza) {
    pizza.afisare(os);
    return os;
}