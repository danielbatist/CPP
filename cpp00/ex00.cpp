# include <iostream>
# include <string>
int main (int argc, char **argv) {
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    if (argc > 1)
    {
        for (int i = 1; i < argc; i++)
        {
            std::string str = argv[i];
            for (size_t j = 0; j < str.length(); j++)
                std::cout << (char)toupper(argv[i][j]);
        }
        std::cout << "\n";
    }
    return 0;
}