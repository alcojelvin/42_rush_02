# **************************************************************************** #
#                                 Makefile for 42_rush_02                      #
# **************************************************************************** #

NAME = rush-02

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
       convert.c \
       convert_utils.c \
       dict_get.c \
       dict_io.c \
       dict_parse.c \
       ft_str_utils.c \
       num_utils.c \
       parse_args.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
