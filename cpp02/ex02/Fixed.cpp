#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(Fixed const &src) {
    *this = src;
}

Fixed::Fixed(const int n) {
    this->value = n << bits;
}

Fixed::Fixed(const float f){
    this->value = roundf(f * (1 << bits));
}

Fixed::~Fixed() {}

Fixed &Fixed::operator=(Fixed const &rSym) {
    if (this != &rSym)
        this->value = rSym.getRawBits();
    return *this;
}

Fixed Fixed::operator+(const Fixed &rSym) const {
    Fixed result;
    result.setRawBits(this->value + rSym.value);
    return result;
}

Fixed Fixed::operator-(const Fixed &rSym) const {
    Fixed result;
    result.setRawBits(this->value - rSym.value);
    return result;
}

Fixed Fixed::operator*(const Fixed &rSym) const {
    Fixed result;
    result.setRawBits((this->value * rSym.value) >> bits);
    return result;
}

Fixed Fixed::operator/(const Fixed &rSym) const {
    Fixed result;
    result.setRawBits((this->value << bits) / rSym.value);
    return result;
}

bool Fixed::operator<(const Fixed &rSym) const {
    if (this->getRawBits() < rSym.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>(const Fixed &rSym) const {
    if (this->getRawBits() > rSym.getRawBits())
        return true;
    return false;
}

bool Fixed::operator<=(const Fixed &rSym) const {
    if (this->getRawBits() <= rSym.getRawBits())
        return true;
    return false;
}

bool Fixed::operator>=(const Fixed &rSym) const {
    if (this->getRawBits() >= rSym.getRawBits())
        return true;
    return false;
}

bool Fixed::operator==(const Fixed &rSym) const {
    if (this->getRawBits() == rSym.getRawBits())
        return true;
    return false;
}

bool Fixed::operator!=(const Fixed &rSym) const {
    if (this->getRawBits() != rSym.getRawBits())
        return true;
    return false;
}

Fixed &Fixed::operator++() {
    this->value++;
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed tmp(*this);
    operator++();
    return tmp;
}

Fixed &Fixed::operator--() {
    this->value--;
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed tmp(*this);
    operator--();
    return tmp;
}

int Fixed::getRawBits() const {
    return this->value;
}

void Fixed::setRawBits(int const raw) {
    this->value = raw;
}

float Fixed::toFloat() const {
    return (float)this->value / (float)(1 << bits);
}

int Fixed::toInt() const {
    return this->value >> bits;
}

Fixed &Fixed::min(Fixed &a, Fixed &b) {
    if (a < b)
        return a;
    return b;
}

Fixed const &Fixed::min(const Fixed &a, const Fixed &b) {
    if (a < b)
        return a;
    return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {
    if (a > b)
        return a;
    return b;
}

Fixed const &Fixed::max(const Fixed &a, const Fixed &b) {
    if (a > b)
        return a;
    return b;
}

std::ostream &operator<<(std::ostream &out, const Fixed &rSym) {
    out << rSym.toFloat();
    return out;
}
