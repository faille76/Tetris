/*
** game_save_map.c for PSU_2015_tetris in /src/game/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 02 14:22:48 2016 antoine
** Last update	Thu Mar 17 15:49:38 2016 antoine GANNAT
*/

#include "game.h"
#include "tetris.h"
#include "piece.h"

void	game_save_map(t_piece 		*piece,
		      t_tetris 		*tetris,
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
	  if (piece->tab[j][i] == '*')
	    tetris->map[y + j][x + i] = piece->color;
	  i++;
	}
      j++;
    }
  piece->rotate %= 4;
  if (piece->rotate == 0)
    return;
  while (piece->rotate < 4)
    piece_rotate(piece, 0, 0, tetris);
  piece->rotate = 0;
}
