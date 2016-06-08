/*
** piece_rotate.c for list_rotate_left in /src/Piece/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Dec 13 12:20:17 2015 Frederic ODDOU
** Last update	Sun Mar 20 22:45:25 2016 antoine GANNAT
*/

#include <stdio.h>
#include <stdlib.h>
#include "piece.h"
#include "tetris.h"
#include "game.h"

char		*col_to_line(t_piece		*piece,
			     int 		col,
			     char 		*newtab)
{
  int		i;
  int		j;

  i = 0;
  j = piece->lines - 1;
  while (i < piece->lines)
    {
      newtab[j] = piece->tab[i][col];
      j--;
      i++;
    }
  newtab[i] = '\0';
  return (newtab);
}

char		**piece_rotate_core(char 	**newtab,
				    t_piece 	*piece)
{
  int		col;

  col = 0;
  while (col < piece->col)
    {
      if ((newtab[col] =
	   malloc(sizeof(char) * piece_find_higher(piece) + 1)) == NULL)
	return (NULL);
      newtab[col] = col_to_line(piece, col, newtab[col]);
      col++;
    }
  newtab[col] = NULL;
  return (newtab);
}

int		piece_check_rotate(t_piece		*piece,
				   int 			*pos,
				   t_tetris		*tetris,
				   char			**newtab)
{
  t_piece	newpiece;
  int		i;
  int		j;

  i = 0;
  newpiece.tab = newtab;
  newpiece.lines = piece->col;
  newpiece.col = piece->lines;
  while (i < newpiece.lines)
    {
      j = 0;
      while (j < newpiece.col)
	{
	  if (pos[1] + i >= tetris->nb_line)
	    return (1);
	  if (pos[0] + j >= tetris->nb_col)
	    return (1);
	  j++;
	}
      i++;
    }
  return (0);
}

int		piece_rotate(t_piece		*piece,
			     int 		x,
			     int 		y,
			     t_tetris		*tetris)
{
  char		**newtab;
  int		tmp;
  int		pos[1];

  if (x + piece->lines > tetris->nb_col - 2)
    return (0);
  if ((newtab = malloc(sizeof(char *)
		       * (piece_find_higher(piece) + 1))) == NULL)
    return (1);
  if ((newtab = piece_rotate_core(newtab, piece)) == NULL)
    return (1);
  pos[0] = x;
  pos[1] = y;
  if (piece_check_rotate(piece, (int *)pos, tetris, newtab) == 1)
    {
      piece_free_tab(newtab);
      return (0);
    }
  piece_free_tab(piece->tab);
  piece->tab = newtab;
  tmp = piece->lines;
  piece->lines = piece->col;
  piece->rotate++;
  piece->col = tmp;
  return (0);
}
