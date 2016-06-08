##
## Makefile for make in /
##
## Made by Frederic ODDOU
## Login oddou_f <frederic.oddou@epitech.eu>
##
## Started on  Fri Feb 26 11:36:05 2016 Frederic ODDOU
## Last update Fri Feb 26 11:36:05 2016 Frederic ODDOU
##

ECHO		=	/bin/echo -e
DEFAULT	=	"\033[00m"
GREEN		=	"\033[0;32m"
TEAL		=	"\033[1;36m"
RED			=	"\033[0;31m"

DIRINC	= ./include/

NCURSES = ./src/ncurses/
PIECE = ./src/piece/
CORE = ./src/core/
DISPLAY	=	./src/display/
KEYBOARD	=	./src/keyboard/
PARSER	=	./src/parser/
GAME	=	./src/game/

DIR	= ./src/

LIBMY	= ./lib/

SRC	= $(DIR)main.c \
			$(DIR)debug/tetris_debug.c \
			$(DIR)debug/tetris_debug_char.c \
			$(DISPLAY)display_board.c \
			$(DISPLAY)display_interface.c \
			$(NCURSES)windowsparam.c \
			$(GAME)game_aff.c \
			$(GAME)game_pause.c \
			$(GAME)game_save.c \
			$(GAME)game_play.c \
			$(GAME)game_check_line.c \
			$(GAME)game_control.c \
			$(GAME)game_init_map.c \
			$(GAME)game_end_screen.c \
			$(GAME)game_save_map.c \
			$(GAME)game_collision.c \
			$(PIECE)piece_add_value.c \
			$(PIECE)piece_fill_tab.c \
			$(PIECE)piece_load_first_line.c \
			$(PIECE)piece_load.c \
			$(PIECE)piece_add.c \
			$(PIECE)piece_delete.c \
			$(PIECE)piece_free.c \
			$(PIECE)piece_init.c \
			$(PIECE)piece_rotate.c \
			$(PIECE)piece_sort_in_name.c \
			$(PIECE)piece_swap.c \
			$(PIECE)piece_parser.c \
			$(PIECE)piece_delete_error.c \
			$(CORE)tetris_help.c \
			$(CORE)tetris_init.c \
			$(CORE)tetris_free.c \
			$(KEYBOARD)keyboard_init.c \
			$(KEYBOARD)keyboard_init_keys.c \
			$(PARSER)tetris_parser.c \
			$(PARSER)tetris_parser_final.c \
			$(PARSER)tetris_parser_debug.c \
			$(PARSER)tetris_parser_drop.c \
			$(PARSER)tetris_parser_left.c \
			$(PARSER)tetris_parser_level.c \
			$(PARSER)tetris_parser_map.c \
			$(PARSER)tetris_parser_pause.c \
			$(PARSER)tetris_parser_quit.c \
			$(PARSER)tetris_parser_right.c \
			$(PARSER)tetris_parser_turn.c \
			$(PARSER)tetris_parser_without.c

OBJS	= $(SRC:.c=.o)

CC	= gcc

RM	= rm -f

CFLAGS	+= -c -Wextra -Wall -Werror -I$(DIRINC)

LDFLAGS = -L$(LIBMY)

NAME	= tetris

EXEC	= execfile

all:	$(EXEC) $(NAME)

$(EXEC):
	make -C $(LIBMY) -f Makefile
	@$(ECHO) $(GREEN)"-> Compilation de $(NAME) :"$(DEFAULT)

$(NAME):	$(OBJS)
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME) -lmy -lncurses
	@$(ECHO) $(GREEN)"-> Done\nUsage : ./$(NAME)\033[00m" $(DEFAULT)

clean:
	make clean -C $(LIBMY) -f Makefile
	@$(RM) $(OBJS)
	@$(ECHO) $(GREEN)"-> Clean $(NAME) effectué." $(DEFAULT)

fclean:	clean
	make fclean -C $(LIBMY) -f Makefile
	@$(RM) ./$(NAME)
	@$(ECHO) $(GREEN)"-> L'executable $(NAME) a été supprimé avec succès."$(DEFAULT)

re: fclean all

.c.o:
		@gcc $(CFLAGS) $(LDFLAGS) -c $< -o $@ && \
		 $(ECHO) $(GREEN) "[OK]" $(TEAL) $< $(DEFAULT) || \
		 $(ECHO) $(RED) "[XX]" $(TEAL) $< $(DEFAULT)

.PHONY: all clean fclean re
