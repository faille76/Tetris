/*
** windowsparam.c for PSU_2015_tetris in /src/ncurses/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 13:55:40 2016 antoine
** Last update	Fri Mar 18 18:46:38 2016 antoine GANNAT
*/

#include <ncurses.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include "display.h"
#include "tetris.h"
#include "my.h"
#include "game.h"
#include "piece.h"

void		window_color()
{
  start_color();
  init_pair(0, COLOR_WHITE, COLOR_RED);
  init_pair(1, COLOR_RED, COLOR_BLACK);
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  init_pair(7, COLOR_WHITE, COLOR_BLACK);
}

SCREEN		*window_start(t_tetris		*tetris)
{
  SCREEN	*win;

  if ((win = newterm(NULL, stderr, stdin)) == NULL)
    {
      init_ioctl(0);
      return (NULL);
    }
  if (COLS < 100 + tetris->nb_col || LINES < 5 + tetris->nb_line)
    {
      window_stop(win, tetris);
      init_ioctl(0);
      my_putstr("Window is too small\n");
      return (NULL);
    }
  piece_fill_tab(tetris);
  nodelay(stdscr, TRUE);
  window_color();
  curs_set(0);
  noecho();
  keypad(stdscr, TRUE);
  return (win);
}

void	window_stop(SCREEN			*win,
		    t_tetris			*tetris)
{
  endwin();
  delscreen(win);
  game_save(tetris);
}
