NAME  = server
NAME_C  = client

SRCS  = server.c
SRCS_C  = client.c
SRCS_S  = utils.c

HEADER  = minitalk.h

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME_C)

$(NAME) : $(SRCS) $(SRCS_S)
	$(CC) $(SRCS) $(SRCS_S) -o $(NAME)

$(NAME_C) : $(SRCS_C) $(SRCS_S)
	$(CC) $(SRCS_C) $(SRCS_S) -o $(NAME_C)

bonus: $(NAME) $(NAME_C)

%.o: %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(NAME) $(NAME_C)

fclean: clean

re: fclean all

rebonus: fclean bonus

.PHONY : all clean fclean re bonus rebonus