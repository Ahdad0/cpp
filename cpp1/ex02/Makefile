NAME = BRAIN

SRCS = main.cpp

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

fclean: clean
	rm -f $(NAME)

clean:

re: fclean all