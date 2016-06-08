/*
** piece_parser.c for PSU_2015_tetris in /src/piece/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 02 11:32:40 2016 antoine
** Last update	Sun Mar 20 14:32:54 2016 antoine GANNAT
*/

#include <stdlib.h>
#include <stdio.h>
#include "piece.h"
#include "struct.h"

void	rm_space(char			*str)
{
  int	i;
  int	last;

  i = 0;
  last = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '*')
	last = i;
      i++;
    }
  i = last;
  while (str[i] != '\0' && str[i] != ' ')
    i++;
  str[i] = '\0';
}

int	check_piece_size(t_piece	*piece,
			 t_tetris	*tetris)
{
  int	i;
  int	j;

  i = 0;
  if (piece->lines > tetris->nb_line - 2 || piece->col > tetris->nb_col - 2)
    return (1);
  while (piece->tab[i] != '\0')
    {
      j = 0;
      while (piece->tab[i][j] != '\0')
	{
	  if (piece->tab[i][j] == '*')
	    return (0);
	  j++;
        }
      i++;
    }
  return (1);
}

int	piece_parser(t_piece		*piece,
		     t_tetris		*tetris)
{
  int	i;
  int	j;
  int	isok;

  j = 0;
  isok = 0;
  while (piece->tab[j] != NULL)
    {
      i = 0;
      while (piece->tab[j][i] != '\0')
	{
	  if (i >= piece->col && piece->tab[j][i] == '*')
	    return (1);
	  if (piece->tab[j][i] != '*' && piece->tab[j][i] != ' ')
	    return (1);
	  i++;
	}
      if (i == piece->col)
	isok = 1;
      rm_space(piece->tab[j]);
      j++;
    }
  if (j != piece->lines || isok == 0 || check_piece_size(piece, tetris) == 1)
    return (1);
  return (0);
}
