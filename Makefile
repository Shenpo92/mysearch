##
## Makefile for  in /home/bob/sw_programming
## 
## Made by Bob
## Login   <robert.ta@epitech.eu>
## 
## Started on  Tue Nov 21 07:02:59 2017 Bob
## Last update Tue Nov 21 09:59:00 2017 Bob


NAME	=	mysearch

CC	=	gcc

RM	=	rm -f

SRCS	=	./src/mysearch.c \
		./src/linkedlist.c

OBJS	=	$(SRCS:.c=.o)

CFLAGS	+=	-W -Wall -Werror -Wextra
CFLAGS	+=	-I./include

all	:	$(NAME)

$(NAME)	:	$(OBJS)
		$(CC) -o $(NAME) $(OBJS)

clean	:
		$(RM) $(OBJS)

fclean	:	clean
		$(RM) $(NAME)

re	:	fclean all

.PHONY	:	all clean fclean re
