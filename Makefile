NAME  = server
NAME_C  = client

SRCS  = server.c
SRCS_C  = client.c
SRCS_U  = utils.c

HEADER  = minitalk.h

CC = gcc

RM = rm -f

FLAGS = -Wall -Wextra -Werror

all: $(NAME) $(NAME_C)

$(NAME) : $(SRCS) $(SRCS_U)
	@$(CC) $(FLAGS) $(SRCS) $(SRCS_U) -o $(NAME)

$(NAME_C) : $(SRCS_C) $(SRCS_U)
	@$(CC) $(FLAGS) $(SRCS_C) $(SRCS_U) -o $(NAME_C)

clean:
	$(RM) $(NAME) $(NAME_C)

fclean: clean

re: fclean all

rebonus: fclean bonus

.PHONY : all clean fclean re bonus rebonus