//
// Created by octav on 27/05/2024.
//

#ifndef PROIECT3_PIZZA_H
#define PROIECT3_PIZZA_H

#include <string>
#include <map>
#include <vector>
#include <unordered_map>
#include "Ingredient.h"
#include "Produs.h"

using namespace std;

class Pizza: public Produs {
private:
    unordered_map<int, vector<Ingredient>> ingrediente;
    static const double manopera;
public:
    Pizza() = default;
    Pizza(const unordered_map<int, vector<Ingredient>>& ingrediente)
            : ingrediente(ingrediente) {}
    double calc_pret() const override;
    friend istream& operator>>(istream& is, Pizza& pizza);
    friend ostream& operator<<(ostream& os, const Pizza& pizza);
    virtual void afisare(ostream& os) const;
    static double get_manopera() {return manopera;}


};


#endif //PROIECT3_PIZZA_H
