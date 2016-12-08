##
## Makefile for  in 
## 
## Made by Jean PLANCHER
## Login   <planch_j@epitech.net>
## 
## Started on  Thu Dec  3 14:49:04 2015 Jean PLANCHER
## Last update Tue Dec  8 02:12:54 2015 Jean PLANCHER
##

CC	= cc

RM     	= rm -f

CFLAGS 	+= -W -Wall -Werror -ansi -pedantic
CFLAGS 	+= -I./include/

LIBFLAG	=

LIBFLAG	= -L./lib/ -lncurses

NAME  	= my_select

SRCS   	= list.c \
	  operation_list.c \
	  my_select.c \
	  functions.c \
	  stuffs.c \
	  bonus.c

OBJS   	= $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(LDFLAGS) -o $(NAME) $(OBJS) $(LIBFLAG)

clean:
	$(RM) $(OBJS)

fclean:   clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
