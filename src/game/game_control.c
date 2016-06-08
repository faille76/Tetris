/*
** game_control.c for PSU_2015_tetris in /src/game/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 02 18:42:59 2016 antoine
** Last update	Fri Mar 18 23:56:51 2016 antoine GANNAT
*/

#include <unistd.h>
#include <ncurses.h>
#include "my.h"
#include "tetris.h"
#include "keyboard.h"
#include "game.h"
#include "piece.h"

int		get_input(int			**pos,
			  t_tetris		*tetris,
			  t_piece		*piece,
			  char			*keys)
{
  game_pause(tetris, keys);
  if (!my_strcmp(keys, tetris->keys->ghost))
    tetris->use_ghost = (tetris->use_ghost == 0) ? 1: 0;
  else if (!my_strcmp(keys, tetris->keys->left)
	   && *pos[0] - 1 >= 0
	   && game_collision_left(piece, tetris->map, *pos[0], *pos[1]) == 0)
    (*pos[0])--;
  else if (!my_strcmp(keys, tetris->keys->right)
	   && *pos[0] + 1 < tetris->nb_col - (piece->col + 1)
	   && game_collision_right(piece, tetris->map, *pos[0], *pos[1]) == 0)
    (*pos[0])++;
  else if (!my_strcmp(keys, tetris->keys->drop))
    {
      while (*pos[1] + piece->lines <= tetris->nb_line
	     && game_collision(piece, tetris->map, *pos[0], *pos[1]) == 0)
	(*pos[1])++;
    }
  else if (!my_strcmp(keys, tetris->keys->quit))
    return (-2);
  else if (!my_strcmp(keys, tetris->keys->turn)
	   && piece_rotate(piece, *pos[0], *pos[1], tetris) == 1)
    return (-2);
  return (0);
}

void		my_getstr(char *key)
{
  int		nb;

  nb = read(0, key, 3);
  if (nb < 0)
    nb = 0;
  key[nb] = '\0';
}

int		set_nb_loop(t_tetris	*tetris)
{
  int		res;

  res = 1000 - (tetris->level * 50);
  if (res <= 0)
    res = 200;
  return (res);
}

int		game_control(int 		*x,
			     int 		*y,
			     t_tetris		*tetris,
			     t_piece 		*piece)
{
  static int	nb_loop;
  int		i;
  int		*pos[2];
  char		key[4];

  i = 0;
  if (nb_loop == set_nb_loop(tetris))
    {
      (*y)++;
      nb_loop = 0;
    }
  pos[0] = x;
  pos[1] = y;
  while (i <= 800)
    {
      my_getstr(key);
      if (get_input(pos, tetris, piece, key) == -2)
	{
	  nb_loop = 0;
	  return (-2);
	}
      i++;
    }
  nb_loop++;
  return (0);
}
