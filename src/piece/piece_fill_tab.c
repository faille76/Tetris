/*
** piece_fill_tab.c for PSU_2015_tetris
**
** Made by	antoine GANNAT
** Login	gannat_a
**
** Started on	Wed Mar 16 22:31:02 2016 antoine GANNAT
** Last update	Fri Mar 18 17:43:58 2016 antoine GANNAT
*/
#include <stdio.h>
#include <stdlib.h>
#include "tetris.h"
#include "piece.h"

void	fill_tab(char			*tab,
		 int			size)
{
  int	i;

  i = 0;
  tab[size] = '\0';
  while ((tab[i] == '*' || tab[i] == ' ') && tab[i] != '\0')
    i++;
  while (i < size)
    {
      tab[i] = ' ';
      i++;
    }
}

void		piece_fill_tab(t_tetris	*tetris)
{
  int		i;
  int		j;
  t_piece	*piece;

  j = 0;
  piece = tetris->list_piece->first;
  while (piece != NULL && j != tetris->list_piece->count)
    {
      i = 0;
      if (piece->error == 0)
	while (piece->tab[i] != NULL)
	    {
	      fill_tab(piece->tab[i], piece_find_higher(piece));
	      i++;
	    }
      j++;
      piece = piece->next;
    }
}
