#include "BitcoinExchange.hpp"

void BitcoinExchange::store_data(const char *file)
{
    std::string str;
    std::ifstream ifile(file);
    if (!ifile.is_open())
    {
        std::cerr << "Error: could not open data file." << std::endl;
        throw std::exception();
    }
    while (getline(ifile, str))
    {
        std::stringstream ss(str);
        std::string date;
        double value;
        if (std::getline(ss, date, ',') && ss >> value)
            data[date] = value;
    }
    // for (std::map<std::string, double>::iterator it = data.begin(); it != data.end(); it++)
    // {
    //     std::cout << "first: " << it->first << " seconde: " << it->second << std::endl;
    // }
}

void BitcoinExchange::print_data(const char *file)
{
    int i = 0;
    std::string str;
    std::ifstream ifile(file);
    if (!ifile.is_open())
    {
        std::cerr << "Error: could not open input file." << std::endl;
        throw std::exception();
    }
    while (getline(ifile, str))
    {
        if (check_line(str, i) == 0)
        {}
        i++;
    }
}

void BitcoinExchange::remove_whitespaces(std::string &str)
{
    size_t i = 0;
    while (i < str.size())
    {
        if (std::isspace(str[i]))
            str.erase(i, 1);
        else
            i++;
    }
}

std::vector<std::string> BitcoinExchange::parse_string(std::string str, char del)
{
    remove_whitespaces(str);

    std::vector<std::string> tmp;
    size_t f = 0;
    size_t npos;
    npos = str.find(del);
    
    while (npos != std::string::npos)
    {
        tmp.push_back(str.substr(f, npos - f));
        f = npos + 1;
        npos = str.find(del, f);
    }
    if (f != std::string::npos)
      tmp.push_back(str.substr(f));
    return tmp;
}

int BitcoinExchange::check_numbers(std::string &str)
{
    int i = 0;
    while (str[i])
    {
        if (!std::isdigit(str[i]))
            return 1;
        i++;
    }
    return 0;
}

int BitcoinExchange::check_line(std::string str, int i)
{
    std::vector<std::string> tmp_str = parse_string(str, '|');
    if (tmp_str.size() == 0)
        return error_bad_input(str);

    if (i == 0)
    {
        if (tmp_str[0] != "date" || tmp_str[1] != "value")
            return error_bad_input(str);
    }
    else
    {
        std::vector<std::string> year = parse_string(tmp_str[0], '-');
        if (year.size() != 3 || check_numbers(year[0]) == 1
            || check_numbers(year[1]) == 1 || check_numbers(year[2]) == 1)
            return error_bad_input(str);
        
        int y;
        std::stringstream s(year[0]);
        s >> y;
        if (y < 2009 || y > 2022)
            return error_bad_input(str);

        if (year[1].size() == 1 || year[2].size() == 1)
            return error_bad_input(str);
        
        int m;
        std::stringstream ss(year[1]);
        ss >> m;
        if (m < 1 || m > 12)
            return error_bad_input(str);

        
        int d;
        std::stringstream sss(year[2]);
        sss >> d;
        if (d < 1 || d > 31)
            return error_bad_input(str);
        
        if (m == 4 && d == 31)
            return error_bad_input(str);
        if (m == 2 && d > 29)
            return error_bad_input(str);

        // year
    }
    // size_t i = 0;
    // while (i < tmp_str.size())
    // {
    //     std::cout << tmp_str[i];
    //     i++;
    // }
    // std::cout << "." << std::endl;
    return 0;
}

int BitcoinExchange::error_bad_input(std::string &str)
{
    std::cout << "Error: bad input => " << str << std::endl;
    return 1;
}