#include "PmergeMe.hpp"

void PmergeMe::error()
{
    std::cerr << "Error" << std::endl;
    throw std::exception();
}

int PmergeMe::check_number(char *av)
{
    int i = 0;
    while (av[i])
    {
        if (!std::isdigit(av[i]))
            return 1;
        i++;
    }
    return 0;
}

void PmergeMe::check_store(char **av, int j)
{
    long long value;
    int i = 1;
    while (av[i])
    {
        if (check_number(av[i]) == 1)
            error();
        std::stringstream s(av[i]);
        s >> value;
        if (value > INT_MAX)
            error();
        size_t y = 0;
        if (j == 0)
        {
            while (y < container.size())
            {
                if (value == container[y])
                    error();
                y++;
            }
            container.push_back(value);
        }
        else
        {
            std::list<int>::iterator it = list_container.begin();
            while (it != list_container.end())
            {
                if (value == *it)
                    error();
                it++;
            }
            list_container.push_back(value);
        }
        i++;
    }
}

void PmergeMe::store_pairs(int j)
{
    size_t i = 0;
    int f, s;
    while (i < container.size())
    {
        if (i + 1 != container.size())
        {
            f = container[i];
            s = container[i + 1];
            if (f > s)
            {
                if (j == 0)
                    pairs.push_back(std::make_pair(container[i], container[i + 1]));
                else
                    list_pairs.push_back(std::make_pair(container[i], container[i + 1]));
            }
            else
            {
                if (j == 0)
                    pairs.push_back(std::make_pair(container[i + 1], container[i]));
                else
                    list_pairs.push_back(std::make_pair(container[i + 1], container[i]));
            }
            i++;
        }
        else if (i + 1 == container.size())
            break;
        i++;
    }
    if (i + 1 == container.size())
    {
        if (j == 0)
            leftover = container[i];
        else
            list_leftover = container[i];
    }
}

int PmergeMe::found_big_num()
{
    size_t i = 0;
    int store = -1;
    while (i < pairs.size())
    {
        if (pairs[i].first != -1)
        {
            store = pairs[i].first;
            pairs[i].first = -1;
            break;
        }
        i++;
    }
    return store;
}

int PmergeMe::found_small_num()
{
    size_t i = 0;
    int store = -1;
    while (i < pairs.size())
    {
        if (pairs[i].second != -1)
        {
            store = pairs[i].second;
            pairs[i].second = -1;
            break;
        }
        i++;
    }
    if (store == -1)
    {
        store = leftover;
        leftover = -1;
    }
    return store;
}

int PmergeMe::check_allBigNumber()
{
    size_t i = 0;
    while (i < pairs.size())
    {
        if (pairs[i].first != -1)
            return 0;
        i++;
    }
    return 1;
}

int PmergeMe::check_allSmallNumber()
{
    size_t i = 0;
    while (i < pairs.size())
    {
        if (pairs[i].second != -1)
            return 0;
        i++;
    }
    return 1;
}

std::deque<int>::iterator PmergeMe::exact_position(int &num)
{
    int low = 0, mid = 0;
    int high = chain.size();
    while (low < high)
    {
        mid = (low + high) / 2;
        if (chain[mid] > num)
            high = mid;
        else
            low = mid + 1;
    }
    std::deque<int>::iterator it = chain.begin() + low;
    return it;
}

int Jacobsthal(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

template <typename T>
T jacobsthalOrder(int N)
{
    T order;
    int prev = 0;
    int i = 1;
    while (i)
    {
        int curr = Jacobsthal(i);
        if (curr > N)
            curr = N;

        int k = curr;
        while (k > prev)
        {
            order.push_back(k);
            k--;
        }

        prev = curr;
        if (curr == N)
            break;
        i++;
    }
    return order;
}

void PmergeMe::sort_deque()
{
    int first_num;
    int seconde_num;
    
    size_t i = 0;
    while (i < pairs.size())
    {
        first_num = pairs[i].first;
        if (chain.size() == 0)
            chain.push_back(first_num);
        else
            chain.insert(exact_position(first_num), first_num);
        i++;
    }
    std::deque<int> tmp = jacobsthalOrder<std::deque<int> >(chain.size());
    i = 0;
    while (i < tmp.size())
    {
        seconde_num = pairs[tmp[i] - 1].second;
        chain.insert(exact_position(seconde_num), seconde_num);
        i++;
    }
    if (leftover != -1)
    {
        seconde_num = leftover;
        chain.insert(exact_position(seconde_num), seconde_num);
    }
}

int PmergeMe::found_num(int index)
{
    int i = 0;
    std::list<std::pair<int, int> >::iterator it = list_pairs.begin();
    while (it != list_pairs.end())
    {
        if (i == index)
            break;
        i++;
        it++;
    }
    return it->second;
}

int PmergeMe::found_num_chain(int index)
{
    int i = 0;
    std::list<int>::iterator it = list_chain.begin();
    while (it != list_chain.end())
    {
        if (i == index)
            break;
        i++;
        it++;
    }
    return *it;
}

std::list<int>::iterator PmergeMe::list_exact_position(int &num)
{
    int low = 0, mid = 0;
    int high = list_chain.size();
    while (low < high)
    {
        mid = (low + high) / 2;
        if (found_num_chain(mid) > num)
            high = mid;
        else
            low = mid + 1;
    }
    std::list<int>::iterator it = list_chain.begin();
    std::advance(it, low);
    return it;
}

void PmergeMe::sort_list()
{
    int first_num;
    int seconde_num;
    
    std::list<std::pair<int, int> >::iterator it = list_pairs.begin();
    while (it != list_pairs.end())
    {
        first_num = it->first;
        if (list_chain.size() == 0)
            list_chain.push_back(first_num);
        else
            list_chain.insert(list_exact_position(first_num), first_num);
        it++;
    }
    std::list<int> tmp = jacobsthalOrder<std::list<int> >(list_chain.size());
    std::list<int>::iterator i = tmp.begin();
    while (i != tmp.end())
    {
        seconde_num = found_num(*i - 1);
        list_chain.insert(list_exact_position(seconde_num), seconde_num);
        i++;
    }
    if (list_leftover != -1)
    {
        seconde_num = list_leftover;
        list_chain.insert(list_exact_position(seconde_num), seconde_num);
    }
}

void PmergeMe::deque(char **av)
{
    gettimeofday(&deque_start_time, NULL);
    check_store(av, 0);
    store_pairs(0);
    sort_deque();
    gettimeofday(&deque_end_time, NULL);
}

void PmergeMe::list(char **av)
{
    gettimeofday(&list_start_time, NULL);
    check_store(av, 1);
    store_pairs(1);
    sort_list();
    gettimeofday(&list_end_time, NULL);
}

void PmergeMe::print_before_after()
{
    if (container.size() != list_container.size())
        error();
    std::cout << "Before: ";
    std::deque<int>::iterator it = container.begin();
    std::list<int>::iterator lit = list_container.begin();
    while (it != container.end())
    {
        if (*it == *lit)
            std::cout << *it << " ";
        else
            error();
        it++;
        lit++;
    }
    std::cout << std::endl;
    if (chain.size() != list_chain.size())
        error();
    std::cout << "After: ";
    it = chain.begin();
    lit = list_chain.begin();
    while (it != chain.end())
    {
        if (*it == *lit)
            std::cout << *it << " ";
        else
            error();
        lit++;
        it++;
    }
    std::cout << std::endl;
}

void PmergeMe::print_time()
{
    double elapsed = (deque_end_time.tv_sec - deque_start_time.tv_sec) * 1e6
                   + (deque_end_time.tv_usec - deque_start_time.tv_usec);
    elapsed /= 1e6;
    std::cout << "Time to process a range of " << chain.size()
          << " elements with std::deque : "
          << std::fixed << std::setprecision(5)
          << elapsed << " us" << std::endl;

    elapsed = (list_end_time.tv_sec - list_start_time.tv_sec) * 1e6
                   + (list_end_time.tv_usec - list_start_time.tv_usec);
    elapsed /= 1e6;
    std::cout << "Time to process a range of " << chain.size()
          << " elements with std::list : "
          << std::fixed << std::setprecision(5)
          << elapsed << " us" << std::endl;
}

PmergeMe::PmergeMe() : leftover(-1), list_leftover(-1)
{}

size_t PmergeMe::get_deque_size()
{
    return chain.size();
}