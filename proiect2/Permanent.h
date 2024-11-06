//
// Created by octav on 17/04/2024.
//

#ifndef PROIECT2_PERMANENT_H
#define PROIECT2_PERMANENT_H

#include "Angajat.h"

class Permanent: public Angajat{
private:
    int minori;
public:
    Permanent();
    Permanent(const std::string& nume, const std::string& prenume, float salariu, const Data& data_angajare, int nr_minori);
    Permanent(const Permanent& other);
    ~Permanent();
    friend std::ostream& operator<<(std::ostream& os, const Permanent& perm);
    friend std::istream& operator>>(std::istream& is, Permanent& perm);
    Permanent& operator=(const Permanent& other);
    friend float spor_sarbatori(Permanent&, float);
    int get_minori() const;

};


#endif //PROIECT2_PERMANENT_H
