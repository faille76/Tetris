/*
** piece_delete.c for list delete in /src/Piece/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Dec 13 13:41:47 2015 Frederic ODDOU
** Last update	Fri Mar 18 17:57:37 2016 antoine GANNAT
*/

#include <stdlib.h>
#include "piece.h"

void		piece_free_tab(char		**tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    {
      free(tab[i]);
      i++;
    }
  free(tab);
}

void		piece_delete(t_control_piece	*control,
			     t_piece		*elem)
{
  if (elem != NULL)
    {
      elem->next->prev = elem->prev;
      elem->prev->next = elem->next;
      if (control->first == elem)
	control->first = elem->next;
      if (control->last == elem)
	control->last = elem->prev;
      if (elem->tab != NULL)
	piece_free_tab(elem->tab);
      if (elem->name != NULL)
	free(elem->name);
      free(elem);
      control->count -= 1;
    }
  if (control->count == 0)
    {
      control->first = NULL;
      control->last = NULL;
    }
}
