# include "Zombie.hpp"

Zombie *newZombie(str name);
void randomChump(str name);

int main(){
    Zombie  *z = newZombie("Foo");
    z->announce();
    delete z;
    randomChump("Fow");
    return 0;
}