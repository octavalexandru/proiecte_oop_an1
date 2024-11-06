//
// Created by octav on 28/05/2024.
//

#ifndef PROIECT3_INGREDIENT_H
#define PROIECT3_INGREDIENT_H

#include <string>
#include <iostream>

using namespace std;



class Ingredient {
private:
    string nume;
    double cantitate{};
    double pret{};

public:
    Ingredient()= default;
    Ingredient(const Ingredient& i) {cantitate = i.cantitate;
    pret = i.pret;
    nume = i.nume;};
    Ingredient(const string& nume, double cantitate, double pret)
            : nume(nume), cantitate(cantitate), pret(pret) {}
    ~Ingredient() = default;
    friend istream& operator>>(istream& is, Ingredient& ing);
    friend ostream& operator<<(ostream& os, const Ingredient& ing);
    Ingredient& operator=(const Ingredient&);
    double calc_pret() const;


};


#endif //PROIECT3_INGREDIENT_H
