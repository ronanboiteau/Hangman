##
## Makefile for pendu in /home/boitea_r/CPE_colle_semaine8
## 
## Made by Ronan Boiteau
## Login   <boitea_r@epitech.net>
## 
## Started on  Tue Jun 14 18:57:34 2016 Ronan Boiteau
## Last update Tue Jun 14 21:35:23 2016 Ronan Boiteau
##

NAME	= pendu

RM	= rm -f

CC	= gcc
CFLAGS	+= -I include
CFLAGS	+= -W -Wall -Wextra
CFLAGS	+= -Werror
CFLAGS	+= -g3

SDIR	= src/
TOOLS	= $(SDIR)tools/
SRCS	= $(SDIR)get_file.c				\
	  $(SDIR)main.c					\
	  $(SDIR)run_game.c				\
	  $(SDIR)word.c					\
	  $(TOOLS)get_next_line.c			\
	  $(TOOLS)my_realloc.c				\
	  $(TOOLS)my_putnbr.c				\
	  $(TOOLS)puts.c

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
