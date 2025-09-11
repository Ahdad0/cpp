#include "RPN.hpp"

std::string RPN::remove_spaces(std::string str)
{
    std::string tmp;
    int i = 0;
    while (str[i])
    {
        if (str[i] == ' ' && str[i + 1] != ' ')
            tmp.push_back(str[i]);
        else if (str[i] != ' ')
        {
            if (std::isdigit(str[i]) && (str[i + 1] != ' ' && str[i + 1]))
                error();
            else if (!std::isdigit(str[i]) && str[i] != '-' 
                    && str[i] != '*' && str[i] != '/' && str[i] != '+')
                error();
            else if ((str[i] == '-' || str[i] == '+' || str[i] == '/' || str[i] == '*')
                    && std::isdigit(str[i + 1]))
                error();
            tmp.push_back(str[i]);
        }
        i++;
    }
    return tmp;
}

void RPN::check_add(std::string str)
{
    if (str.size() == 0)
        error();
    str = remove_spaces(str);
    size_t i = str.size() - 1;
    if (i < 0)
        error();

    while (i > 0)
    {
        if (str[i] != ' ')
            stak.push(std::string(1, str[i]));
        i--;
    }
    if (str[i] != ' ')
        stak.push(std::string(1, str[i]));
}

int RPN::check_type(std::string &str)
{
    if (str == "-" || str == "+" || str == "*" || str == "/")
        return 0;

    if (std::isdigit(str[0]))
        return 1;
    return -1;
}
int RPN::calculate_operator(int first, int seconde, std::string op)
{
    int n;
    if (op == "*")
        n = first * seconde;
    if (op == "-")
        n = first - seconde;
    if (op == "/")
    {
        if (seconde == 0)
            error();
        n = first / seconde;
    }
    if (op == "+")
        n = first + seconde;
    return n;
}
void RPN::calculate()
{
    while (!stak.empty())
    {
        if (check_type(stak.top()) == 1)
        {
            if (first_num.size() == 0)
                first_num = stak.top();
            else if (seconde_num.size() == 0)
                seconde_num = stak.top();
            else
                error();
            stak.pop();
        }
        else if (check_type(stak.top()) == 0)
        {
            if (first_num.size() != 0 && seconde_num.size() != 0)
            {
                int f = 0, s = 0;
                std::stringstream s0(first_num);
                s0 >> f;
                std::stringstream ss(seconde_num);
                ss >> s;

                int num = calculate_operator(f, s, stak.top());

                std::ostringstream oss;
                oss << num;
                std::string tmp_str = oss.str();
                first_num = tmp_str;
                seconde_num = "";
            }
            else
                error();
            stak.pop();
        }
        if (stak.size() == 0 && seconde_num.size() != 0)
            error();
    }
    std::cout << first_num << std::endl;
}

RPN::RPN() : first_num(""), seconde_num("")
{}

void RPN::error()
{
    std::cerr << "Error" << std::endl;
    throw std::exception();
}