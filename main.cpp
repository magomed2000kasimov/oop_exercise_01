#include <iostream>
#include "bits.h"

int main() {

    bit a;

    a.read(std::cin);
    a.write_10(std::cout);
    a.write_2(std::cout);
    a.shiftLeft(std::cin);
    a.write_10(std::cout);
    a.write_2(std::cout);
    std::cout<<a.number_of_units()<<std::endl;

    bit c;
    c.read(std::cin);
    c.write_10(std::cout);
    c.write_2(std::cout);

    bit f;
    f=a.AND(c);
    f.write_10(std::cout);
    f.write_2(std::cout);
    f=a.OR(c);
    f.write_10(std::cout);
    f.write_2(std::cout);
    f=a.NOT();
    f.write_10(std::cout);
    f.write_2(std::cout);
    f=a.XOR(c);
    f.write_10(std::cout);
    f.write_2(std::cout);
    std::cout<<c.inclusion(a)<<std::endl<<c.comparsion(a);
    return 0;
}