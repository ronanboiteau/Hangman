NAME	= hangman

RM	= rm -f

CC	= gcc
CFLAGS	+= -I include/
CFLAGS	+= -W -Wall -Wextra -Werror

TOOLS_DIR	= tools/
TOOLS_FILES	= get_next_line.c		\
		  my_realloc.c			\
		  my_putnbr.c			\
		  puts.c
TOOLS		= $(addprefix $(TOOLS_DIR), $(TOOLS_FILES))

SRCS_DIR	= src/
SRCS_FILES	= get_file.c		\
		  main.c		\
		  run_game.c		\
		  word.c		\
		  $(TOOLS)
SRCS		= $(addprefix $(SRCS_DIR), $(SRCS_FILES))

OBJS	= $(SRCS:.c=.o)


all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
