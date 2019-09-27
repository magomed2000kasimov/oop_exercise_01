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
    void Read(std::istream &is);

    void Write10(std::ostream &os);

    void Write2(std::ostream &os);

    bit();

    bit(int a1,int b1){
        a=a1;
        b=b1;
    };

    bit And(const bit &lel) const;

    bit Or(const bit &lel) const;

    bit Xor(const bit &lel) const;

    bit Not() const;

    void ShiftLeft(int k);

    void ShiftRight(int k);

    int Count_of_units() const;

    int Comparsion(const bit &lel) const;

    int Inclusion(const bit &lel) const;

    void Get(unsigned long long i, unsigned int j);

    unsigned long long Hight() const;

    unsigned int Low() const;
};


#endif //OOP_EXERCISE_01_BITS_H
