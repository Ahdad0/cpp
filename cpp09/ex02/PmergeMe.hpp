#pragma once

#include <iostream>
#include <deque>
#include <sstream>
#include <limits.h>
#include <ctime>
#include <iomanip> 
#include <sys/time.h>
#include <list>

class PmergeMe
{
    private:
        timeval deque_start_time;
        timeval deque_end_time;

        timeval list_start_time;
        timeval list_end_time;

        std::deque<int> container;
        std::deque<std::pair<int, int> > pairs;
        std::deque<int> chain;

        std::list<int> list_container;
        std::list<std::pair<int, int> > list_pairs;
        std::list<int> list_chain;

        int leftover;
        int list_leftover;

    public:
        int found_num(int index);
        int found_num_chain(int index);
        void check_store(char **av, int i);
        int check_number(char *av);
        void store_pairs(int i);
        void error();
        
        int check_allBigNumber();
        int check_allSmallNumber();
        int found_big_num();
        int found_small_num();
        std::deque<int>::iterator exact_position(int &num);
        std::list<int>::iterator list_exact_position(int &num);
        void sort_deque();
        void sort_list();
        size_t get_deque_size();

        void deque(char **av);
        void list(char **av);

        void print_before_after();
        void print_time();
        PmergeMe();
};
