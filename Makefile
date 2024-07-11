NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -rf

SRCS = main.c utils.c initializing.c check_exit.c life.c threads.c

OBJS = ${SRCS:.c=.o}

all: $(NAME)

$(NAME): ${OBJS}
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re