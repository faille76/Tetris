/*
** piece_free.c for list free in /src/Piece/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Dec 13 13:45:58 2015 Frederic ODDOU
** Last update Mon Dec 14 22:44:37 2015 Frederic ODDOU
*/

#include <stdlib.h>
#include "piece.h"

void		piece_free(t_control_piece	*control)
{
  t_piece	*next;

  if (control->first != NULL && control->last != NULL)
    {
      while (control->count > 0)
	{
	  next = control->first;
	  control->first = control->first->next;
	  if (next->tab != NULL)
	    piece_free_tab(next->tab);
	  if (next->name != NULL)
	    free(next->name);
	  free(next);
	  control->count -= 1;
	}
    }
  free(control);
}
