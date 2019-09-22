//
// Created by magom on 14.09.2019.
//

#ifndef OOP_EXERCISE_01_BITS_H
#define OOP_EXERCISE_01_BITS_H

#include <iostream>
#include <string>
#include <vector>


class bit {
private:
    unsigned long long a;
    unsigned int b;
public:
    void read(std::istream & is );
    void write_10(std::ostream& os);
    void write_2(std::ostream& os);
    bit();
    bit AND (const bit & lel) const ;
    bit OR (const bit & lel) const ;
    bit XOR (const bit & lel) const ;
    bit NOT () const ;
    void shiftLeft(std::istream& is);
    void shiftRight(std:: istream& is);
    int number_of_units() const ;
    int comparsion(const bit & lel) const;
    int inclusion(const bit & lel) const;
    void vvod(unsigned long long i, unsigned int j);
    unsigned long long vivod_star() const ;
    unsigned int vivod_mlad() const ;
};




#endif //OOP_EXERCISE_01_BITS_H
