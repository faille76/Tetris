/*
** game_aff.c for PSU_2015_tetris in /src/game/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 02 13:58:23 2016 antoine
** Last update	Thu Mar 17 13:33:47 2016 antoine GANNAT
*/

#include <ncurses.h>
#include "game.h"
#include "tetris.h"
#include "display.h"
#include "piece.h"

void	aff_piece(t_piece		*piece,
		  int 			i,
		  int 			y,
		  int 			pos_board)
{
  int	j;

  j = 0;
  while (piece->tab[i][j] != '\0')
    {
      if (piece->tab[i][j] == '*')
	mvprintw(y + i + 1, pos_board, " ");
      j++;
      pos_board++;
    }
}

int	get_y_gost(t_piece		*piece,
		   t_tetris		*tetris,
		   int 			x,
		   int 			y)
{
  while (y < tetris->nb_line - (piece->lines - 1) &&
	 game_collision(piece, tetris->map, x, y) == 0)
    y++;
  return (y - 1);
}

void	game_aff(t_piece		*piece,
		 int 			x,
		 int 			y,
		 t_tetris		*tetris)
{
  int	i;
  int	pos_board;
  int	y_ghost;

  i = 0;
  erase();
  y_ghost = get_y_gost(piece, tetris, x, y);
  display_interface(tetris);
  pos_board = COLS / 2 - (tetris->nb_col / 2) + 1;
  while (i < piece->lines)
    {
      attron(COLOR_PAIR(piece->color) | A_REVERSE);
      aff_piece(piece, i, y, x + pos_board);
      attroff(COLOR_PAIR(piece->color) | A_REVERSE);
      attron(A_REVERSE);
      if (y != y_ghost && tetris->use_ghost == 1)
	aff_piece(piece, i, y_ghost, x + pos_board);
      attroff(A_REVERSE);
      i++;
    }
  refresh();
}
