#include "Fixed.hpp"
#include <cmath>

Fixed::Fixed() : value(0) {
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src) {
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::Fixed(const int n) {
    std::cout << "Int constructor called" << std::endl;
    value = n << Bits;
}

Fixed::Fixed(const float f) {
    std::cout << "Float constructor called" << std::endl;
    value = roundf(f * (1 << Bits));
}

Fixed::~Fixed() {
    std::cout << "Destructor called" << std::endl;
}

Fixed&  Fixed::operator=(Fixed const &rSym) {
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rSym) {
        value = rSym.getRawBits();
    }
    return *this;
}

int     Fixed::getRawBits() const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->value;
}

void    Fixed::setRawBits(int const raw) {
    this->value = raw;
}

float   Fixed::toFloat() const {
    return (float)this->value / (float)(1 << this->Bits);
}

int     Fixed::toInt() const {
    return this->value >> this->Bits;
}

std::ostream& operator<<(std::ostream &o, Fixed const &rSym) {
    o << rSym.toFloat();
    return o;
}