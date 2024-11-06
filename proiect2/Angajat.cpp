//
// Created by octav on 17/04/2024.
//

#include "Angajat.h"
#include <iostream>
#include "Data.h"
#include <cstring>
#include <string>

using namespace std;

// Default constructor
Angajat::Angajat() : salariu(0) {}

// Parameterized constructor
Angajat::Angajat(const string& nume, const string& prenume, float salariu, const Data& data_angajare)
        : nume(nume), prenume(prenume), salariu(salariu), data_angajare(data_angajare) {}

// Copy constructor
Angajat::Angajat(const Angajat& other)
        : nume(other.nume), prenume(other.prenume), salariu(other.salariu), data_angajare(other.data_angajare) {}

Angajat::~Angajat() {}

std::ostream& operator<<(std::ostream& os, const Angajat& angajat) {
    os << "Nume: " << angajat.nume << ", Prenume: " << angajat.prenume
       << ", Salariu: " << angajat.salariu << ", Data angajare: " << angajat.data_angajare;
    return os;
}

std::istream& operator>>(std::istream& is, Angajat& angajat) {
    is >> angajat.nume >> angajat.prenume >> angajat.salariu >> angajat.data_angajare;
    return is;
}

Angajat& Angajat::operator=(const Angajat& other) {
    if (this != &other) {
        nume = other.nume;
        prenume = other.prenume;
        salariu = other.salariu;
        data_angajare = other.data_angajare;
    }
    return *this;
}