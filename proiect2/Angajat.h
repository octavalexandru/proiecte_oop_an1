//
// Created by octav on 17/04/2024.
//

#ifndef PROIECT2_ANGAJAT_H
#define PROIECT2_ANGAJAT_H

#include <string>
#include "Data.h"

using namespace std;

class Angajat {
private:
    string nume, prenume;
    float salariu;
protected:
    Data data_angajare;

public:
    Angajat();
    Angajat(const string&, const string&, float, const Data&);
    Angajat(const Angajat&);
    virtual ~Angajat();
    friend std::ostream& operator<<(std::ostream&, const Angajat&);
    friend std::istream& operator>>(std::istream& is, Angajat&);
    Angajat& operator=(const Angajat&);

};


#endif //PROIECT2_ANGAJAT_H
