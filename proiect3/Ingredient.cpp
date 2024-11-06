//
// Created by octav on 28/05/2024.
//

#include "Ingredient.h"
#include <iostream>

using namespace std;

Ingredient& Ingredient::operator=(const Ingredient & i) {
    cantitate = i.cantitate;
    pret = i.pret;
    nume = i.nume;
    return *this;
}

istream& operator>>(istream& is, Ingredient& ing)
{
    is >> ing.nume >>ing.cantitate >> ing.pret;
    return is;
}

ostream& operator<<(ostream& os, const Ingredient& ing)
{
    os << ing.nume << " " << ing.cantitate << " " << ing.pret;
    return os;
}

double Ingredient::calc_pret() const
{
    return cantitate*pret;
}
