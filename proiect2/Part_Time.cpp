//
// Created by octav on 17/04/2024.
//

#include "Part_Time.h"
#include "Angajat.h"
#include <iostream>
#include <string>
#include <cstring>
#include <ctime>
#include <typeinfo>

using namespace std;

Part_Time::Part_Time() : Angajat(), nr_ore_zi(0) {}

Part_Time::Part_Time(const std::string& nume, const std::string& prenume, float salariu, const Data& data_angajare,
                     int nr_ore_zi, const Data& final_contract)
        : Angajat(nume, prenume, salariu, data_angajare), nr_ore_zi(nr_ore_zi), final_contract(final_contract) {}

Part_Time::Part_Time(const Part_Time& other)
        : Angajat(other), nr_ore_zi(other.nr_ore_zi), final_contract(other.final_contract) {}

Part_Time::~Part_Time() {}

std::ostream& operator<<(std::ostream& os, const Part_Time& part_time) {
    os << static_cast<const Angajat&>(part_time) << ", Nr ore/zi: " << part_time.nr_ore_zi
       << ", Final contract: " << part_time.final_contract;
    return os;
}

std::istream& operator>>(std::istream& is, Part_Time& part_time) {
    is >> static_cast<Angajat&>(part_time) >> part_time.nr_ore_zi >> part_time.final_contract;
    return is;
}

Part_Time& Part_Time::operator=(const Part_Time& other) {
    if (this != &other) {
        *this = other;
        nr_ore_zi = other.nr_ore_zi;
        final_contract = other.final_contract;
    }
    return *this;
}

float spor_sarbatori(Part_Time& ang, float standard){
    float spor = 0.0;
    time_t now = time(NULL);
    tm* localTime = localtime(&now);

    if (localTime == NULL) {
        cout << "Error: Unable to get local time." << endl;
        return spor;
    }

    int year = localTime->tm_year + 1900; // Year since 1900

    int month = localTime->tm_mon + 1; // Month (0-based index, so add 1)

    int day = 31; // Start with the maximum possible day in the month

    // Reduce the day until it represents a valid day in the current month
    while (true) {
        if (day < 28) break; // If day is already less than 28, it's valid
        // Check if the day is valid for the current month and year
        if (day <= 28 || (day == 29 && month != 2) || (day == 30 && (month == 4 || month == 6 || month == 9 || month == 11)) || (day == 31)) {
            break;
        }
        day--;
    }


    // Convert the month number to a three-letter format
    char* months[] = {"ian", "feb", "mar", "apr", "mai", "iun", "iul", "aug", "sep", "oct", "noi", "dec"};
    char monthStr[4]; // Change the declaration
    strcpy(monthStr, months[month - 1]);

    // Create a Data object representing the end of the current month
    Data final_luna(day, months[month - 1], year);


    if(diferenta_data(ang.final_contract, final_luna) < 0)
        return (float)3/4*standard;
    else
        return standard;
}


