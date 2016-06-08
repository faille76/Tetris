/*
** piece_add.c for piece_add in /src/Pieces/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Dec 13 12:06:26 2015 Frederic ODDOU
** Last update Sun Feb 28 13:47:39 2016 antoine
*/

#include <stdlib.h>
#include "piece.h"

void		piece_add(t_control_piece	*control)
{
  t_piece	*new;

  if ((new = malloc(sizeof(*new))) != NULL)
    {
      if (control->last == NULL || control->first == NULL)
	{
	  control->last = new;
	  control->first = new;
	}
      new->prev = control->last;
      new->next = control->first;
      new->tab = NULL;
      new->name = NULL;
      new->error = 0;
      control->last->next = new;
      control->first->prev = new;
      if (control->last == control->first)
	control->first->next = new;
      control->last = new;
      control->count += 1;
    }
}
