#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
//#include <iomanip>
#include <cmath>

class Fixed {
public:
    Fixed();
    Fixed(Fixed const &src);
    Fixed(const int n);
    Fixed(const float f);
    ~Fixed();

    Fixed &operator=(Fixed const &rSym);
    Fixed operator+(const Fixed &rSym) const;
    Fixed operator-(const Fixed &rSym) const;
    Fixed operator*(const Fixed &rSym) const;
    Fixed operator/(const Fixed &rSym) const;

    bool operator<(const Fixed &rSym) const;
    bool operator>(const Fixed &rSym) const;
    bool operator<=(const Fixed &rSym) const;
    bool operator>=(const Fixed &rSym) const;
    bool operator==(const Fixed &rSym) const;
    bool operator!=(const Fixed &rSym) const;

    Fixed &operator++();
    Fixed operator++(int);
    Fixed &operator--();
    Fixed operator--(int);

    int getRawBits() const;
    void setRawBits(int const raw);
    float toFloat() const;
    int toInt() const;

    static Fixed &min(Fixed &a, Fixed &b);
    static const Fixed &min(const Fixed &a, const Fixed &b);
    static Fixed &max(Fixed &a, Fixed &b);
    static const Fixed &max(const Fixed &a, const Fixed &b);
private:
    int value;
    static const int bits = 8;
};

std::ostream &operator<<(std::ostream &out, const Fixed &rSym);

#endif