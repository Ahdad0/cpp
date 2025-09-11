#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

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
}

int BitcoinExchange::compare_date(std::string data_date, std::string input_date)
{
    remove_whitespaces(data_date, '-');
    remove_whitespaces(input_date, '-');

    double first_date = 0;
    double seconde_date = 0;

    std::stringstream s(data_date);
    s >> first_date;

    std::stringstream ss(input_date);
    ss >> seconde_date;

    if (seconde_date > first_date)
    {
        return 0;
    }
    return 1;
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
        {
            double v;
            std::vector<std::string> tmp = parse_string(str, '|');
            try
            {
                v = data.at(tmp[0]);
                std::cout << date << " => " << input_value << " = " << v * input_value << std::endl;
            }
            catch(const std::exception& e)
            {
                std::map<std::string, double>::iterator it = data.end();
                it--;
                while (it != data.begin())
                {
                    if (compare_date(it->first, date) == 0)
                    {
                        std::cout << date << " => " << input_value << " = " << it->second * input_value << std::endl;
                        break;
                    }
                    it--;
                }
            }
        }
        i++;
    }
}

void BitcoinExchange::remove_whitespaces(std::string &str, char c)
{
    size_t i = 0;
    while (i < str.size())
    {
        if (std::isspace(str[i]) || str[i] == c)
            str.erase(i, 1);
        else
            i++;
    }
}

std::vector<std::string> BitcoinExchange::parse_string(std::string str, char del)
{
    remove_whitespaces(str, ' ');

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

int BitcoinExchange::check_numbers(std::string &str, int i)
{
    size_t ii = 0;
    int cout = 0;
    // std::cout << "first is: " << str[ii] << "\n";
    while (str[ii])
    {
        if (!std::isdigit(str[ii]) && (str[ii] != '.'))
        {
            if (i == 1 && (str[ii] == '-' || str[ii] == '+'))
            {
                if (!std::isdigit(str[ii + 1]) || std::isdigit(str[ii - 1]))
                    return 1;
                ii++;
                continue;
            }
            return 1;
        }
        if (str[ii] == '.' && str[ii + 1] == '.')
            return 1;
        if (ii == 0 && str[ii] == '.')
            return 1;
        if (ii + 1 == str.size() && str[ii] == '.')
            return 1;
        if (str[ii] == '.')
            cout++;
        ii++;
    }
    if (cout > 1)
        return 1;
    return 0;
}

int BitcoinExchange::check_line(std::string str, int i)
{
    std::vector<std::string> tmp_str = parse_string(str, '|');
    if (tmp_str.size() != 2)
        return error_bad_input(str);

    if (i == 0)
    {
        if (tmp_str[0] != "date" || tmp_str[1] != "value")
            return error_bad_input(str);
    }
    else
    {
        // year-month-day
        date = tmp_str[0];
        std::vector<std::string> year = parse_string(tmp_str[0], '-');
        if (year.size() != 3 || check_numbers(year[0], 0) == 1
            || check_numbers(year[1], 0) == 1 || check_numbers(year[2], 0) == 1)
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
        
        if (check_numbers(tmp_str[1], 1) == 1)
            return error_bad_input(str);
        double v;
        std::stringstream vv(tmp_str[1]);
        vv >> v;
        if (v < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            return 1;
        }
        if (v > INT_MAX)
        {
            std::cout << "Error: too large a number." << std::endl;
            return 1;
        }
        input_value = v;
        // if ()
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