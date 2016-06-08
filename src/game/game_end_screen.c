/*
** game_end_screen.c for PSU_2015_tetris
**
** Made by	antoine GANNAT
** Login	gannat_a
**
** Started on	Thu Mar 17 00:17:33 2016 antoine GANNAT
** Last update	Fri Mar 18 16:27:51 2016 antoine GANNAT
*/

#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "tetris.h"
#include "my.h"

int	get_score_postion(int		position,
			  int		high_score)
{
  int	fd;
  char	*str;
  int	res;
  int	old;
  int	i;

  i = 0;
  old = high_score;
  if ((fd = open("save.tet", O_RDONLY)) == -1)
    return (0);
  while (i < position)
    {
      res = 0;
      while ((str = get_next_read(fd)) != NULL)
	{
	  if (res < my_getnbr(str) && my_getnbr(str) != old
	      && my_getnbr(str) != high_score)
	    res = my_getnbr(str);
	  free(str);
	}
      lseek(fd, 0, SEEK_SET);
      old = res;
      i++;
    }
  return (res);
}

void	aff_high_score(t_tetris		*tetris)
{
  attron(COLOR_PAIR(1));
  mvprintw(8, (COLS / 2) - 4, "HIGH SCORES");
  attroff(COLOR_PAIR(1));
  mvprintw(9, (COLS / 2) - 5, "-------------");
  mvprintw(10, (COLS / 2) - 4, "1ST:  %d", tetris->high_score);
  mvprintw(11, (COLS / 2) - 4, "2ND:  %d",
	   get_score_postion(1, tetris->high_score));
  mvprintw(12, (COLS / 2) - 4, "3RD:  %d",
	   get_score_postion(2, tetris->high_score));
  mvprintw(13, (COLS / 2) - 5, "-------------");
}

int	get_classment_position(int	score)
{
  int	fd;
  char	*str;
  int	res;

  res = 0;
  if ((fd = open("save.tet", O_RDONLY)) == -1)
    return (0);
  while ((str = get_next_read(fd)) != NULL)
    {
      if (my_getnbr(str) > score)
	res++;
      free(str);
    }
  return (res);
}

void	close_game(t_tetris	*tetris)
{
  int	key;

  key = -1;
  mvprintw(6, (COLS / 2) + 9, "%d:%d",
	   (time(NULL) - tetris->timer) / 60, (time(NULL) - tetris->timer) % 60);
  mvprintw(15, (COLS / 2) - 10, "Press any key to continue");
  while (key == -1)
    key = getch();
}

void	game_end_screen(t_tetris	*tetris)
{
  erase();
  aff_high_score(tetris);
  mvprintw(1, (COLS / 2) - 5, "GAME OVER !");
  if (tetris->score > tetris->high_score)
    {
      attron(COLOR_PAIR(1));
      mvprintw(3, (COLS / 2) - 8, "NEW HIGH SCORE !");
      attroff(COLOR_PAIR(1));
    }
  else
    {
      attron(COLOR_PAIR(2));
      mvprintw(3, (COLS / 2) - 6, "POSITION : %d",
	       get_classment_position(tetris->score));
      attroff(COLOR_PAIR(2));
    }
  attron(COLOR_PAIR(3));
  mvprintw(5, (COLS / 2) - 8, "SCORE");
  mvprintw(5, (COLS / 2), "ROUND");
  mvprintw(5, (COLS / 2) + 8, "TIME");
  attroff(COLOR_PAIR(3));
  mvprintw(6, (COLS / 2) - 8, "%d", tetris->score);
  mvprintw(6, (COLS / 2), "%d", tetris->level);
  close_game(tetris);
}
