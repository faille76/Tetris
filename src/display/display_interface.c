/*
** affscore.c for PSU_2015_tetris in /src/display/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 12:11:30 2016 antoine
** Last update	Tue Mar 15 16:22:26 2016 antoine GANNAT
*/

#include <time.h>
#include <ncurses.h>
#include "tetris.h"
#include "display.h"
#include "game.h"
#include "piece.h"
#include "my.h"

void	display_write(int 		y,
		      int 		x,
		      char 		*str,
		      short 		color)
{
  attron(COLOR_PAIR(color));
  mvprintw(y, x, str);
  attroff(COLOR_PAIR(color));
}

void	display_header()
{
  display_write(1, 1, " _______ _______ _______ ______  _  ______", 1);
  display_write(2, 1, "(_______|_______|_______|_____ \\| |/ _____)", 2);
  display_write(3, 1, "    _    _____      _    _____) ) ( (____", 3);
  display_write(4, 1, "   | |  |  ___)    | |  |  __  /| |\\____ \\", 4);
  display_write(5, 1, "   | |  | |_____   | |  | |  \\ \\| |_____) )", 5);
  display_write(6, 1, "   |_|  |_______)  |_|  |_|   |_|_(______/", 6);
}

void	display_tab(t_tetris		*tetris)
{
  display_write(8, 7, "/---------------------------\\", 2);
  display_write(9, 9, "Highscore :", 6);
  display_write(10, 9, "Score :", 6);
  display_write(11, 9, "Lines :", 6);
  display_write(12, 9, "Level :", 6);
  display_write(13, 9, "Timer :", 6);
  display_write(14, 7, "\\---------------------------/", 2);
  display_write(9, 7, "|", 2);
  display_write(10, 7, "|", 2);
  display_write(11, 7, "|", 2);
  display_write(12, 7, "|", 2);
  display_write(13, 7, "|", 2);
  display_write(9, 35, "|", 2);
  display_write(10, 35, "|", 2);
  display_write(11, 35, "|", 2);
  display_write(12, 35, "|", 2);
  display_write(13, 35, "|", 2);
  attron(COLOR_PAIR(1));
  mvprintw(9, 25, "%d", tetris->high_score);
  mvprintw(10, 25, "%d", tetris->score);
  mvprintw(11, 25, "%d", tetris->line);
  mvprintw(12, 25, "%d", tetris->level);
  mvprintw(13, 25, "%d:%d", (time(NULL) - tetris->timer) / 60,
	   (time(NULL) - tetris->timer) % 60);
  attroff(COLOR_PAIR(1));
}

void		display_next(t_tetris	*tetris)
{
  t_piece	*piece;
  int		i;

  i = 0;
  piece = game_change_piece(tetris->list_piece->first, tetris->next_piece);
  display_write(17, 12, "/  <-- Next -->  \\", 2);
  while (piece->tab[i] != NULL)
    {
      attron(COLOR_PAIR(piece->color));
      mvprintw(18 + i, 20, piece->tab[i]);
      attroff(COLOR_PAIR(piece->color));
      i++;
    }
  display_write(18 + i, 12, "\\                /", 2);
}

void	display_interface(t_tetris	*tetris)
{
  display_header();
  display_tab(tetris);
  if (tetris->hide_next)
    display_next(tetris);
  display_board(tetris);
}
