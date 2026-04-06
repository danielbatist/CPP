#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>
#include <string>

typedef std::string str;

class Zombie {
    public:
        Zombie(str name);
        ~Zombie();
        void announce();

    private:
        str name;
};

#endif