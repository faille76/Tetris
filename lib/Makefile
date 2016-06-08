##
## Makefile for Make lib in /
##
## Made by Frederic ODDOU
## Login oddou_f <frederic.oddou@epitech.eu>
##
## Started on  Wed Nov  4 11:10:53 2015 Frederic ODDOU
## Last update Sun Dec 13 21:20:51 2015 Frederic ODDOU
##

ECHO		=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED			=	"\033[0;31m"

DIRINC	= ../include/

SRC	= my_putchar.c \
	  my_putstr.c \
		my_putstr_e.c \
		my_putnbr.c \
		my_getnbr.c \
		my_strlen.c \
		my_revstr.c \
		my_strcat.c \
		my_strcat_dyn.c \
		my_strcmp.c \
		my_strncmp.c \
		my_strcpy.c \
		my_strdup.c \
		my_strncpy.c \
		my_strstr.c \
		printf/sources/char.c \
		printf/sources/my_printf.c \
		printf/sources/nbaff.c \
		printf/sources/string.c \
		my_name_compare.c \
		get_next_read.c

CC	= gcc -c

RM	= rm -f

LIB		=

FLAG		=	-W -Wall -ansi -pedantic \
	-I ../include/ -g

NAME	= libmy.a

OBJS	= $(SRC:.c=.o)

EXEC = exec

all:	$(EXEC) $(NAME)

exec:
	@$(ECHO) $(GREEN)"-> Compilation de la librairie :"$(DEFAULT)

$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS) && \
	 $(ECHO) $(GREEN) "[AR]" $(TEAL) $(NAME) $(DEFAULT) || \
	 $(ECHO) $(RED) "[XX]" $(TEAL) $(NAME)
	@ranlib $(NAME) && \
	 $(ECHO) $(GREEN) "[OK]" $(TEAL) $(NAME) $(DEFAULT) || \
	 $(ECHO) $(RED) "[XX]" $(TEAL) $(NAME)
	@$(ECHO) $(GREEN)"-> La compilation de la librairie vient d'être effectuée avec succès."$(DEFAULT)
	@$(ECHO) $(GREEN)"-> La librairie porte le nom de $(NAME)."$(DEFAULT)

clean:
	@$(RM) $(OBJS)
	@$(ECHO) $(GREEN)"Les fichiers tmp de la librairie ont été supprimés avec succès."$(DEFAULT)

fclean:	clean
	@$(RM) $(NAME)
	@$(ECHO) $(GREEN)"mLa librairie a été supprimée avec succès."$(DEFAULT)

re: fclean all

.c.o:
	@gcc $(LIB) $(FLAG) -c $< -o $@ && \
	 $(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
	 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

.PHONY: all clean fclean re
