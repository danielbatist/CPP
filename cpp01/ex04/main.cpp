#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

void    getNewLine(std::string &line, const std::string &first, const std::string &second)
{
    size_t pos = 0;
    while ((pos = line.find(first, pos)) != std::string::npos)
    {
        line = line.substr(0, pos) + second + line.substr(pos + first.length());
        pos += second.length();
    }
}
int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: " << argv[0] << " <filename> <string_to_replace> <replacement_string>" << std::endl;
        return 1;
    }
    std::string filename = argv[1];
    std::string first = argv[2];
    std::string second = argv[3];
    std::string line;
    std::string out_file = filename + ".replace";

    if (first.empty())
    {
        std::cerr << "Error: string to replace cannot be empty" << std::endl;
        return 1;
    }
    std::ifstream input(filename.c_str());
    std::ofstream output(out_file.c_str());
    if (!output.is_open())
    {
        std::cerr << "Error: Could not create file " << out_file << std::endl;
        return 1;
    }
    if (input.is_open()){
        while (std::getline(input, line)) {
            getNewLine(line, first, second);
            output << line;
            if (!input.eof())
                output << std::endl;
        }
        input.close();
        output.close();
    }
    else
        std::cerr << "Error: Could not open file " << filename << std::endl;
}