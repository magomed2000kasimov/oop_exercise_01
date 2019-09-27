#include <iostream>
#include "bits.h"

int main() {

    bit a;

    a.Read(std::cin);
    a.Write10(std::cout);
    a.Write2(std::cout);
    int n;
    std::cin>>n;
    a.ShiftLeft(n);
    a.Write10(std::cout);
    a.Write2(std::cout);
    std::cout<<a.Count_of_units()<<std::endl;

    bit c;
    c.Read(std::cin);
    c.Write10(std::cout);
    c.Write2(std::cout);

    bit f;
    f=a.And(c);
    f.Write10(std::cout);
    f.Write2(std::cout);
    f=a.Or(c);
    f.Write10(std::cout);
    f.Write2(std::cout);
    f=a.Not();
    f.Write10(std::cout);
    f.Write2(std::cout);
    f=a.Xor(c);
    f.Write10(std::cout);
    f.Write2(std::cout);
    std::cout<<c.Inclusion(a)<<std::endl<<c.Comparsion(a);
    return 0;
}