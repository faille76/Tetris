/*
** piece_sort_in_name.c for sort in name in /src/piece/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Mar  2 10:32:03 2016 Frederic ODDOU
** Last update Wed Mar  2 10:32:03 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include "my.h"
#include "piece.h"

void		piece_sort_in_name(t_control_piece	*control)
{
  t_piece	*list;
  int		swap;

  if (control->first != NULL && control->last != NULL)
    {
      swap = 0;
      list = control->first;
      while (list->next != control->first)
	{
	  if (my_name_compare(list->name, list->next->name) == 1)
	    {
	      piece_swap(control, list, list->next);
	      swap++;
	    }
	  list = list->next;
	}
      if (swap > 0)
	piece_sort_in_name(control);
    }
}
