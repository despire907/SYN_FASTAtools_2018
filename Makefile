##
## EPITECH PROJECT, 2018
## makefile
## File description:
## makefile
##

CC	= gcc -g

RM	= rm -f

NAME	= FASTAtools

SRC	=   main.c  \
        utils/get_line.c    \
        utils/my_strtoword_tab.c    \
        utils/init_info.c   \
        option/first_option_and_second.c   \
        option/third_option.c   \
        option/fourth_option.c  \
        option/qsort_fourth_option.c    \
        free_info_and_tab.c

OBJ	= $(addprefix src/,$(SRC:.c=.o))

CFLAGS	= -W -Wextra -Wall -I include/

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

all:	$(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: all clean fclean re
