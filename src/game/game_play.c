/*
** game_play.c for PSU_2015_tetris in /src/game/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 02 13:22:35 2016 antoine
** Last update	Fri Mar 18 17:13:34 2016 antoine GANNAT
*/

#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "display.h"
#include "tetris.h"
#include "game.h"

t_piece		*game_change_piece(t_piece	*piece,
				   int		nbr)
{
  int		i;

  i = 0;
  while (i < nbr)
    {
      piece = piece->next;
      i++;
    }
  return (piece);
}

int		game_loop(t_tetris		*tetris,
			  int 			*x,
			  int 			*y,
			  t_piece 		*piece)
{
  int		end;

  end = 0;
  while (*y < tetris->nb_line - (piece->lines - 1)
         && (end = game_collision(piece, tetris->map, *x, *y)) == 0)
    {
      game_aff(piece, *x, *y, tetris);
      end = game_control(x, y, tetris, piece);
      if (end == -2)
	return (2);
    }
  return (end);
}

int		game_main_loop(t_tetris		*tetris)
{
  t_piece	*piece;
  int		end;
  int		x;
  int		y;

  x = 0;
  end = 0;
  tetris->next_piece = rand() % tetris->list_piece->count;
  while (1)
    {
      piece = game_change_piece(tetris->list_piece->first, tetris->next_piece);
      tetris->next_piece = rand() % tetris->list_piece->count;
      x = ((tetris->nb_col / 2) - 1) - piece->col / 2;
      y = 0;
      end = game_loop(tetris, &x, &y, piece);
      if (end == 2)
	return (1);
      game_save_map(piece, tetris, x, --y);
      game_check_line(tetris);
      display_interface(tetris);
    }
  return (0);
}

int		game_play(t_tetris		*tetris)
{
  if (tetris->list_piece->count == 0)
    return (0);
  init_ioctl(2);
  if (game_init_map(tetris) == 1)
    return (1);
  game_main_loop(tetris);
  game_end_screen(tetris);
  return (0);
}
