/*
** piece_delete_error.c for delete error in /src/piece/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Mar 10 00:02:54 2016 Frederic ODDOU
** Last update	Sun Mar 20 16:58:29 2016 antoine GANNAT
*/

#include <stdlib.h>
#include "piece.h"

void		piece_delete_error(t_control_piece	*control)
{
  t_piece	*tmp;
  t_piece	*delete;
  int		i;
  int		max;

  tmp = control->first;
  delete = NULL;
  i = 0;
  max = control->count;
  while (i < max)
    {
      if (tmp->error)
	delete = tmp;
      tmp = tmp->next;
      if (delete != NULL)
	{
	  piece_delete(control, delete);
	  delete = NULL;
	}
      i++;
    }
}
