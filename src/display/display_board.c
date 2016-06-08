/*
** display_board.c for PSU_2015_tetris in /src/display/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Tue Mar 01 14:26:26 2016 antoine
** Last update Fri Mar 18 12:05:34 2016 Frederic ODDOU
*/

#include <ncurses.h>
#include "tetris.h"

void		display_board_line(int 		height,
				   t_tetris	*tetris)
{
  int		width;
  int		widthstart;

  width = 0;
  widthstart = COLS / 2 - (tetris->nb_col / 2);
  while (width < tetris->nb_col)
    {
      mvprintw(height, width + widthstart, "=");
      width++;
    }
}

void		display_inside_line(int 	width,
				    int 	height,
				    t_tetris	*tetris)
{
  int		length;
  int		x;

  x = 0;
  width++;
  length = width + tetris->nb_col - 1;
  while (width < length)
    {
      if (tetris->map[height - 1][x] != -1)
	{
	  attron(COLOR_PAIR(tetris->map[height - 1][x]) | A_REVERSE);
	  mvprintw(height, width, " ");
          attroff(COLOR_PAIR(tetris->map[height - 1][x]) | A_REVERSE);
	}
      else
	mvprintw(height, width, " ");
      width++;
      x++;
    }
}

void		display_board(t_tetris		*tetris)
{
  int		height;
  int		width;

  height = 1;
  display_board_line(0, tetris);
  while (height <= tetris->nb_line)
    {
      width = COLS / 2 - (tetris->nb_col / 2);
      mvprintw(height, width, "|");
      display_inside_line(width, height, tetris);
      width += tetris->nb_col - 1;
      mvprintw(height, width, "|");
      height++;
    }
  display_board_line(height, tetris);
}
