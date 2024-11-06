#include <iostream>
#include <cstring>
#include <string>
#include "Data.h"
#include "Angajat.h"
#include "Part_Time.h"
#include "Permanent.h"

using namespace std;

int main() {
    int n;
    cout << "********calculare sporuri angajati*********\n\n";

    cout << "Introduceti numarul de angajati: ";
    cin >> n;
    cout << endl;

    Angajat** angajati = new Angajat*[n];

    for (int i = 0; i < n; ++i) {
        int tipAngajat;
        cout << "Selectati tipul de angajat pentru angajatul " << i + 1 << ". Pentru angajat part-time, selectati 1, pentru permanent, selectati 2: ";
        cin >> tipAngajat;

        string nume, prenume;
        float salariu;
        Data dataAngajare;

        cout << "Introduceti nume: ";
        cin >> nume;
        cout << "Introduceti prenume: ";
        cin >> prenume;
        cout << "Introduceti salariu: ";
        cin >> salariu;
        cout << "Introduceti data angajarii (zi luna an): ";
        cin >> dataAngajare;

        // tipuri de angajat
        if (tipAngajat == 1) {
            int nrOreZi;
            Data finalContract;

            cout << "Introduceti numarul de ore pe zi: ";
            cin >> nrOreZi;
            cout << "Introduceti data finalului contractului (zi luna an): ";
            cin >> finalContract;

            angajati[i] = new Part_Time(nume, prenume, salariu, dataAngajare, nrOreZi, finalContract);
        } else if (tipAngajat == 2) {
            int nrMinori;

            cout << "Introduceti numarul de minori: ";
            cin >> nrMinori;

            angajati[i] = new Permanent(nume, prenume, salariu, dataAngajare, nrMinori);
        } else {
            cout << "Tip de angajat invalid. Selectati 1 pentru part-time sau 2 pentru permanent.\n";
            --i;
        }
    }

    // Main menu loop
    while (true) {
        int option;
        cout << "Introduceti numarul corespunzator pentru actiunea dorita.\n"
                "1: Afisare angajati;\n"
                "2: Adaugare angajati;\n"
                "3: Calculare sporuri;\n"
                "4: Inchidere program.\n";
        cin >> option;

        switch (option) {
            case 1: {
                for (int i = 0; i < n; ++i) {
                    cout << "Angajat " << i + 1 << ": " << *(angajati[i]) << endl;
                }                break;
            }
            case 2: {
                int tipAngajat;
                cout << "Selectati tipul de angajat pentru noul angajat. Pentru angajat part-time, selectati 1, pentru permanent, selectati 2: ";
                cin >> tipAngajat;

                string nume, prenume;
                float salariu;
                Data dataAngajare;

                cout << "Introduceti nume: ";
                cin >> nume;
                cout << "Introduceti prenume: ";
                cin >> prenume;
                cout << "Introduceti salariu: ";
                cin >> salariu;
                cout << "Introduceti data angajarii (zi luna an): ";
                cin >> dataAngajare;

                if (tipAngajat == 1) {
                    int nrOreZi;
                    Data finalContract;

                    cout << "Introduceti numarul de ore pe zi: ";
                    cin >> nrOreZi;
                    cout << "Introduceti data finalului contractului (zi luna an): ";
                    cin >> finalContract;

                    angajati[n++] = new Part_Time(nume, prenume, salariu, dataAngajare, nrOreZi, finalContract);
                } else if (tipAngajat == 2) {
                    int nrMinori;

                    cout << "Introduceti numarul de minori: ";
                    cin >> nrMinori;

                    angajati[n++] = new Permanent(nume, prenume, salariu, dataAngajare, nrMinori);
                } else {
                    cout << "Tip de angajat invalid. Selectati 1 pentru part-time sau 2 pentru permanent.\n";
                }
                break;
            }
            case 3: {
                // spor_sarbatori pentru angajat
                for (int i = 0; i < n; ++i) {
                    if (angajati[i] != NULL) {
                        Part_Time *partTimeAngajat = dynamic_cast<Part_Time *>(angajati[i]);
                        if (partTimeAngajat != NULL) {
                            // Angajat is Part_Time
                            cout << "Spor pentru angajatul " << i + 1 << " (Part-Time): "
                                 << spor_sarbatori(*partTimeAngajat, 1000) << endl;
                        } else {
                            Permanent *permanentAngajat = dynamic_cast<Permanent *>(angajati[i]);
                            if (permanentAngajat != NULL) {
                                // Angajat is Permanent
                                cout << "Spor pentru angajatul " << i + 1 << " (Permanent): "
                                     << spor_sarbatori(*permanentAngajat, 2000) << endl;
                            } else {
                                // eroare
                                cout << "Error: Unrecognized type for angajatul " << i + 1 << endl;
                            }
                        }
                    }
                }
                break;
            }

            case 4: {
                // Exit
                break;
            }
            default: {
                cout << "Ati introdus un numar invalid. Va rugam sa introduceti un numar intre 1 si 4.\n";
                // prompt pentru numar corect
                while (!(cin >> option) || option < 1 || option > 4) {
                    cout << "Numar invalid. Va rugam sa introduceti un numar intre 1 si 4.\n";
                    // clear buffer
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                break;
            }

        }

        if (option == 4) {
            break;
        }
    }

    // stergere angajati
    for (int i = 0; i < n; ++i) {
        delete angajati[i];
    }
    delete[] angajati;

    return 0;
}
