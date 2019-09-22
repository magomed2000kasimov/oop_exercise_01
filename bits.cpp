//
// Created by magom on 14.09.2019.
//

#include "bits.h"

int number(unsigned long long m) {
    int i = 0;
    while (m > 0) {
        i += m % 2;
        m = m / 2;
    }
    return i;
}

void bit::read(std::istream &is) {
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
    //   for (auto st : v)
    //     std::cout << st << ' ';
    //std::cout << std::endl;

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

void bit::write_10(std::ostream &os) {
    os << a << " " << b << std::endl;
}

void bit::write_2(std::ostream &os) {
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

bit bit::AND(const bit &lel) const {
    bit temp;
    unsigned long long temp_a = a & lel.vivod_star();
    unsigned int temp_b = b & lel.vivod_mlad();
    temp.vvod(temp_a, temp_b);
    return temp;
}

bit bit::OR(const bit &lel) const {
    bit temp;
    unsigned long long temp_a = a | lel.vivod_star();
    unsigned int temp_b = b | lel.vivod_mlad();
    temp.vvod(temp_a, temp_b);
    return temp;
}

bit bit::XOR(const bit &lel) const {
    bit temp;
    unsigned long long temp_a = a ^lel.vivod_star();
    unsigned int temp_b = b ^lel.vivod_mlad();
    temp.vvod(temp_a, temp_b);
    return temp;
}

bit bit::NOT() const {
    bit temp;
    unsigned long long temp_a = ~a;
    unsigned int temp_b = ~b;
    temp.vvod(temp_a, temp_b);
    return temp;
}

void bit::shiftLeft(std::istream &is) {
    int k = 0, i = 0;
    is >> i;
    while (k < i) {
        if (b >= 2147483648) {
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

void bit::shiftRight(std::istream &is) {
    unsigned int k = 0, f = 2147483648, i = 0;
    is >> i;
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


void bit::vvod(unsigned long long i, unsigned int j) {
    a = i;
    b = j;
}

unsigned long long bit::vivod_star() const {
    return a;
}

unsigned int bit::vivod_mlad() const {
    return b;
}

int bit::number_of_units() const {
    return number(a) + number(b);

}

int bit::comparsion(const bit &lel) const {
    int i1 = number(a) + number(b);
    int i2 = lel.number_of_units();
    if (i1 == i2)
        return 1;
    else
        return 0;
}

int bit::inclusion(const bit &lel) const {
    std::vector<int> v1, v2;
    int result = 1;
    int min_size;
    unsigned int b1 = b;
    while (b1 > 0) {
        v1.push_back(b1 % 2);
        b1 = b1 / 2;
    }
    unsigned long long a1 = a;
    while (a1 > 0) {
        v1.push_back(a1 % 2);
        a1 = a1 / 2;
    }
    b1 = lel.vivod_mlad();
    while (b1 > 0) {
        v2.push_back(b1 % 2);
        b1 = b1 / 2;
    }
    a1 = lel.vivod_star();
    while (a1 > 0) {
        v2.push_back(a1 % 2);
        a1 = a1 / 2;
    }
    if (v1.size() >= v2.size()) {
        min_size = v2.size();
    } else
        return 0;
    for (int i = 0; i < min_size; ++i) {
        if (v1[i] != v2[i]) {
            result = 0;
            break;
        }
    }
    return result;
}

bit::bit() {
    a = 0;
    b = 0;
}