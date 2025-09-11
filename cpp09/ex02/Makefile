NAME = PmergeMe

SRCS = main.cpp PmergeMe.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 -g

all: $(NAME)

$(NAME): $(SRCS) PmergeMe.hpp
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

fclean: clean
	rm -f $(NAME)

clean:

re: fclean all