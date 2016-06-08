/*
** game_pause.c for PSU_2015_tetris
**
** Made by	antoine GANNAT
** Login	gannat_a
**
** Started on	Tue Mar 15 20:22:35 2016 antoine GANNAT
** Last update	Wed Mar 16 15:51:55 2016 antoine GANNAT
*/

#include <stdlib.h>
#include <time.h>
#include <ncurses.h>
#include "tetris.h"
#include "my.h"

void	game_pause(t_tetris	*tetris,
		   char		*keys)
{
  int	current_time;
  char	str[4];

  if (!my_strcmp(keys, tetris->keys->pause))
    {
      current_time = time(NULL);
      attron(COLOR_PAIR(1));
      mvprintw(15, 19, "PAUSE", 1);
      attroff(COLOR_PAIR(1));
      str[0] = '\0';
      while (!my_strcmp(str, tetris->keys->pause))
	my_getstr(str);
      tetris->timer += time(NULL) - current_time;
    }
}
