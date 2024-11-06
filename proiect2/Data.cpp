//
// Created by octav on 17/04/2024.
//

#include "Data.h"
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <ctime>
#include <cmath>

using namespace std;

Data::Data() {zi = 0; an = 0; luna = NULL;}


Data::Data(int zi, char* luna, int an) : zi(zi), an(an), luna(NULL) {
    if (luna != NULL) {
        this->luna = new char[strlen(luna) + 1];
        strcpy(this->luna, luna);
    }
}


Data::Data(const Data & d) {
    this->zi = d.zi;
    this->an = d.an;
    if (this->luna != NULL)
        delete[] this->luna;
    this->luna = new char[strlen(d.luna) + 1];
    strcpy(this->luna, d.luna);
}


Data::~Data() {
    zi = 0;
    an = 0;
    delete[] luna;
}
//var ctime
int diferenta_data(const Data& data1, const Data& data2) {
    struct tm time1 = {0};
    time1.tm_mday = data1.get_zi();
    time1.tm_mon = -1;
    const char* months[] = {"ian", "feb", "mar", "apr", "mai", "iun", "iul", "aug", "sep", "oct", "noi", "dec"};
    for (int i = 0; i < 12; ++i) {
        if (strcmp(data1.get_luna(), months[i]) == 0) {
            time1.tm_mon = i;
            break;
        }
    }
    time1.tm_year = data1.get_an() - 1900;

    struct tm time2 = {0};
    time2.tm_mday = data2.get_zi();
    time2.tm_mon = -1;
    for (int i = 0; i < 12; ++i) {
        if (strcmp(data2.get_luna(), months[i]) == 0) {
            time2.tm_mon = i;
            break;
        }
    }
    time2.tm_year = data2.get_an() - 1900;

    // struct tm to time_t
    time_t time1_t = mktime(&time1);
    time_t time2_t = mktime(&time2);

    // diferenta in secunde
    double difference = difftime(time1_t, time2_t);

    return abs(difference / (60 * 60 * 24));
}



Data& Data::operator=(const Data & d) {
    an = d.an;
    zi = d.zi;
    delete[] luna;
    luna = new char[strlen(d.luna) + 1];
    strcpy(luna, d.luna);
    return *this;
}

std::ostream& operator<<(std::ostream & os, const Data& d) {
    os << d.get_zi() << " " << d.get_luna() << " " << d.get_an();
    return os;
}

std::istream& operator>>(std::istream& is, Data& d){
    char temp[100];
    is >> d.zi >> temp >> d.an;
    delete[] d.luna;
    d.luna = new char[strlen(temp) + 1];
    strcpy(d.luna, temp);
    return is;
}


