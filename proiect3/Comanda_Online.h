//
// Created by octav on 28/05/2024.
//

#ifndef PROIECT3_COMANDA_ONLINE_H
#define PROIECT3_COMANDA_ONLINE_H

#include "Pizza.h"

using namespace std;

class Comanda_Online: public Pizza {
private:
    double distanta;
public:
    Comanda_Online(const unordered_map<int, vector<Ingredient>>& ingrediente, double distanta);

    double calc_pret() const override;

    void afisare(ostream& os) const override;

};


#endif //PROIECT3_COMANDA_ONLINE_H
