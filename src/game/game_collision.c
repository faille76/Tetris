/*
** game_collision.c for PSU_2015_tetris in /src/game/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 02 13:28:03 2016 antoine
** Last update Thu Mar 17 09:11:57 2016 Frederic ODDOU
*/

#include "piece.h"
#include "tetris.h"

int	game_collision_right(t_piece 	*piece,
			     char 	**map,
			     int 	x,
			     int 	y)
{
  int	i;
  int	j;

  j = 0;
  while (j < piece->lines)
    {
      i = 0;
      while (i <= 1)
	{
	  if (y != 0 && piece->tab[j][i] == '*' && map[j + y][i + x + 1] != -1)
	    return (1);
	  i++;
	}
      j++;
    }
  return (0);
}

int	game_collision_left(t_piece 	*piece,
			    char 	**map,
			    int 	x,
			    int 	y)
{
  int	i;
  int	j;

  j = 0;
  while (j < piece->lines)
    {
      i = 0;
      while (i <= 1)
	{
	  if (y != 0 && piece->tab[j][i] == '*' && map[j + y][i + x - 1] != -1)
	    return (1);
	  i++;
	}
      j++;
    }
  return (0);
}

int	game_collision(t_piece		*piece,
		       char 		**map,
		       int 		x,
		       int 		y)
{
  int	i;
  int	j;

  j = 0;
  while (j < piece->lines)
    {
      i = 0;
      while (i < piece->col)
	{
	  if (y == 0 && piece->tab[j][i] == '*' && map[j + y][i + x] != -1)
	    return (2);
	  else if (y != 0 && piece->tab[j][i] == '*' && map[j + y][i + x] != -1)
	    return (1);
	  i++;
	}
      j++;
    }
  return (0);
}
