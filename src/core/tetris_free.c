/*
** tetris_free.c for free in /src/core/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Feb 26 16:36:00 2016 Frederic ODDOU
** Last update Fri Feb 26 16:36:00 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include "tetris.h"
#include "piece.h"

void		tetris_free(t_tetris	*tetris)
{
  int		i;

  i = 0;
  if (tetris != NULL)
    {
      if (tetris->map != NULL)
	{
	  while (tetris->map[i] != NULL)
	    {
	      free(tetris->map[i]);
	      i++;
	    }
	  free(tetris->map);
	}
      piece_free(tetris->list_piece);
      if (tetris->keys != NULL)
	free(tetris->keys);
      free(tetris);
    }
}
