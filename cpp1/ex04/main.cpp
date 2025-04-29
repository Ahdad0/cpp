#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>

std::string all_been_replaced(std::string old, std::string neew, std::string line)
{
    int size_str = old.length();
    int pos = 0;

    pos = line.find(old, pos);
    while (pos != -1)
    {
        line.erase(pos, size_str);
        line.insert(pos, neew);
        pos = line.find(old, pos + 1);
    }
    return (line);
}

int main(int ac, char **av)
{
    if (ac != 4)
    {
        std::cerr << "Error: Please provide exactly 3 arguments.\n";
        exit(1);
    }
    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];
    std::string line;

    std::ifstream infile(filename.c_str());
    if (!infile)
    {
        std::cerr << "Error in the file!\n";
        exit(1);
    }
    std::ofstream outfile((filename + ".replace").c_str());
    if (!outfile)
    {
        std::cerr << "Error in the file!\n";
        exit(1);
    }
    while (std::getline(infile, line))
    {
        line = all_been_replaced(s1, s2, line);
        outfile << line;
    }
    infile.close();
    outfile.close();
}
