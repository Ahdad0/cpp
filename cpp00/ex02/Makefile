NAME = Phonebook

SRCS = tests.cpp Account.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98 #-Wno-deprecated-declarations

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

fclean: clean
	rm -f $(NAME)

clean:

re: fclean all