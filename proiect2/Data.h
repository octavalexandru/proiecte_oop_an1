//
// Created by octav on 17/04/2024.
//

#ifndef PROIECT2_DATA_H
#define PROIECT2_DATA_H

//using namespace std;


#include <iosfwd>
#include <iostream>
#include <cstring>

class Data {
private:
    int zi, an;
    char* luna;
public:
    Data();
    Data(int, char*, int);
    Data(const Data&);
    ~Data();
    friend int diferenta_data(const Data&, const Data&);
    int get_zi ()const{return zi;}
    int get_an() const{return an;}
    const char* get_luna() const {
        if (luna != NULL) {
            return luna;
        } else {
            return NULL;
        }
    }
    Data& operator=(const Data&);
    friend std::ostream& operator<<(std::ostream&, const Data&);
    friend std::istream& operator>>(std::istream&, Data&);


};


#endif //PROIECT2_DATA_H
