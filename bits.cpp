//
// Created by magom on 14.09.2019.
//

#include "bits.h"

int Count(unsigned long long m) {
    int i = 0;
    while (m > 0) {
        i += m % 2;
        m = m / 2;
    }
    return i;
}

void bit::Read(std::istream &is) {
    std::string s;
    is >> s;
    int n = s.size();
    std::string t(n, '0');
    std::vector<int> v;
    while (s != t) {
        int d = 0;
        for (int i = 0; i < s.size(); i++) {
            d *= 10;
            d += (s[i] - 48);
            s[i] = char(48 + d / 2);
            d %= 2;
        }
        v.push_back(d);
    }

    unsigned int b_step = 1;
    for (int i = 0; i < 32 && i < v.size(); i++) {
        b += v[i] * b_step;
        b_step *= 2;
    }
    unsigned long long a_step = 1;
    for (int i = 32; i < v.size(); i++) {
        a += v[i] * a_step;
        a_step *= 2;
    }
}

void to2(unsigned long long a, std::ostream &os) {
    if (a == 0)
        return;
    to2(a / 2, os);
    std::cout << a % 2;
}

void bit::Write10(std::ostream &os) {
    os << a << " " << b << std::endl;
}

void bit::Write2(std::ostream &os) {
    if (a != 0)
        to2(a, os);
    else
        std::cout << 0;
    std::cout << " ";
    if (b != 0)
        to2(b, os);
    else
        for (int i = 0; i < 32; ++i) {
            std::cout << 0;
        }
    os << std::endl;
}

bit bit::And(const bit &lel) const {
    unsigned long long temp_a = a & lel.Hight();
    unsigned int temp_b = b & lel.Low();
    bit temp(temp_a, temp_b);
    return temp;
}

bit bit::Or(const bit &lel) const {
    unsigned long long temp_a = a | lel.Hight();
    unsigned int temp_b = b | lel.Low();
    bit temp(temp_a, temp_b);
    return temp;
}

bit bit::Xor(const bit &lel) const {
    unsigned long long temp_a = a ^lel.Hight();
    unsigned int temp_b = b ^lel.Low();
    bit temp(temp_a, temp_b);
    return temp;
}

bit bit::Not() const {
    unsigned long long temp_a = ~a;
    unsigned int temp_b = ~b;
    bit temp(temp_a, temp_b);
    return temp;
}

void bit::ShiftLeft(int i) {
    int k = 0;
    while (k < i) {
        if (b >= (1u<<31u)) {
            a = a << 1;
            ++a;
            b = b << 1;
            ++k;
        } else {
            a = a << 1;
            b = b << 1;
            ++k;
        }
    }
}

void bit::ShiftRight(int i) {
    unsigned int k = 0, f = (1u<<31u);
    while (k < i) {
        if (a % 2 == 1) {
            a = a >> 1;
            b = b >> 1;
            b = b | f;
            ++k;
        } else {
            a = a >> 1;
            b = b >> 1;
            ++k;
        }
    }
}


void bit::Get(unsigned long long i, unsigned int j) {
    a = i;
    b = j;
}

unsigned long long bit::Hight() const {
    return a;
}

unsigned int bit::Low() const {
    return b;
}

int bit::Count_of_units() const {
    return Count(a) + Count(b);

}

int bit::Comparsion(const bit &lel) const {
    int i1 = Count(a) + Count(b);
    int i2 = lel.Count_of_units();
    if (i1 == i2)
        return 1;
    else
        return 0;
}

int bit::Inclusion(const bit &lel) const {
    if ( (a&lel.a)==a && (b&lel.b)==b  )
        return 1;
    else
        return 0;

}

bit::bit() {
    a = 0;
    b = 0;
}