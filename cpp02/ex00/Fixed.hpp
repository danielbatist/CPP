#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
    public:
        Fixed();
        Fixed(Fixed const &src);
        ~Fixed();

        Fixed&  operator=(Fixed const &rSym);
        int     getRawBits() const;
        void    setRawBits(int const raw);

    private:
        int                 value;
        static const int    Bits = 8;
};

#endif