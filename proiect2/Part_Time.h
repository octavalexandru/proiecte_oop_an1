//
// Created by octav on 17/04/2024.
//

#ifndef PROIECT2_PART_TIME_H
#define PROIECT2_PART_TIME_H

#include "Angajat.h"

class Part_Time: public Angajat{
private:
    int nr_ore_zi;
protected:
    Data final_contract;
public:
    Part_Time();
    Part_Time(const std::string& nume, const std::string& prenume, float salariu, const Data& data_angajare,
              int nr_ore_zi, const Data& final_contract);
    Part_Time(const Part_Time& other);
    ~Part_Time();
    friend std::ostream& operator<<(std::ostream& os, const Part_Time& part_time);
    friend std::istream& operator>>(std::istream& is, Part_Time& part_time);
    Part_Time& operator=(const Part_Time& other);
    // Add other member functions as needed
    friend float spor_sarbatori(Part_Time&, float);

};


#endif //PROIECT2_PART_TIME_H
