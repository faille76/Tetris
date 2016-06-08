/*
** game_check_line.c for PSU_2015_tetris in /src/game/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 02 18:57:20 2016 antoine
** Last update Sun Mar 20 18:11:23 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include <unistd.h>
#include "tetris.h"
#include "my.h"

void	game_refill_line(t_tetris 	*tetris,
			 int		line)
{
  int	i;

  i = 0;
  while (i < tetris->nb_col - 2)
    {
      tetris->map[line][i] = -1;
      i++;
    }
}

int	check_full_line(t_tetris	*tetris,
			int		line)
{
  int	i;

  i = 0;
  while (i < tetris->nb_col - 2)
    {
      if (tetris->map[line][i] == -1)
	return (1);
      i++;
    }
  return (0);
}

void	game_cpy_line(t_tetris		*tetris,
		      int		line)
{
  int	i;

  i = 0;
  while (i < tetris->nb_col - 2)
    {
      if (line - 1 < 0)
	return;
      tetris->map[line][i] = tetris->map[line - 1][i];
      i++;
    }
}

void	game_drop_lines(t_tetris	*tetris,
			int		line)
{
  while (line > 0)
    {
      game_cpy_line(tetris, line);
      game_refill_line(tetris, line - 1);
      line--;
    }
}

void	game_check_line(t_tetris	*tetris)
{
  int	i;

  i = 0;
  while (i < tetris->nb_line)
    {
      if (check_full_line(tetris, i) == 0)
	{
	  game_refill_line(tetris, i);
	  game_drop_lines(tetris, i);
	  tetris->score += 100;
	  tetris->line++;
	  if (tetris->line % 10 == 0)
	    tetris->level++;
	}
      i++;
    }
}
