//
// Created by octav on 17/04/2024.
//

#include "Permanent.h"
#include "Data.h"
#include <iostream>

using namespace std;

Permanent::Permanent() : Angajat(), minori(0) {}

Permanent::Permanent(const std::string& nume, const std::string& prenume, float salariu, const Data& data_angajare, int minori)
        : Angajat(nume, prenume, salariu, data_angajare), minori(minori) {}

Permanent::Permanent(const Permanent& other) : Angajat(other), minori(other.minori) {}

Permanent::~Permanent() {}

std::ostream& operator<<(std::ostream& os, const Permanent& perm) {
    os << static_cast<const Angajat&>(perm) << ", Nr. minori: " << perm.minori;
    return os;
}

std::istream& operator>>(std::istream& is, Permanent& perm) {
    is >> static_cast<Angajat&>(perm);
    is >> perm.minori;
    return is;
}

Permanent& Permanent::operator=(const Permanent& other) {
    if (this != &other) {
        Angajat::operator=((Angajat &) other);
        minori = other.minori;
    }
    return *this;
}

int Permanent::get_minori() const {
    return this->minori;
}

float spor_sarbatori(Permanent& ang, float standard){
    float spor = 0.0;
//    Data* diff;
    Data current(31, "dec", 2020);
//    diff = new Data;
    int diff;
//    current = new Data(31, "dec", 2020);
    diff = diferenta_data(ang.data_angajare, current);
//    cout << diff << endl;
    spor = (float)(diff/365) *(float)(ang.minori) * 12.0/100.0 * standard + standard;
    return spor;
}