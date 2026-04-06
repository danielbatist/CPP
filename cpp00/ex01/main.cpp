#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "repository.hpp"

int main(){
    
    PhoneBook   PhoneBook;
    str         line;

    system("clear");
    std::cout << "Hello! Welcome to your new contact manager." <<std::endl;
    while (1)
    {
        std::cout << "Type ADD, SEARCH, or EXIT: ";
        if (!std::getline(std::cin, line))
        {
            std::cout << std::endl << "Goodbye!" << std::endl;
            break;
        }
        if(line == "ADD")
            PhoneBook.add_contact();
        else if(line == "SEARCH")
            PhoneBook.search_contact();
        else if (line == "EXIT")
        {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
        system("clear");
    }
    sleep(1);
    return 0;
}