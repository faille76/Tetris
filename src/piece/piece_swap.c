/*
** piece_swap.c for piece swap in /src/piece/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Mar  2 10:33:41 2016 Frederic ODDOU
** Last update Wed Mar  2 10:33:41 2016 Frederic ODDOU
*/

#include "piece.h"

void		piece_swap_beside(t_piece 	*elem1,
				  t_piece 	*elem2)
{
  t_piece	*prev;

  prev = elem1->prev;
  elem1->prev->next = elem2;
  elem1->next = elem2->next;
  elem1->prev = elem2;
  elem2->next->prev = elem1;
  elem2->next = elem1;
  elem2->prev = prev;
}

void		piece_swap(t_control_piece	*control,
			   t_piece 		*elem1,
			   t_piece 		*elem2)
{
  if (elem1 != elem2)
    {
      if (elem1->next == elem2 || elem2->next == elem1)
	piece_swap_beside(elem1, elem2);
      if (control->first == elem1)
	control->first = elem2;
      else if (control->first == elem2)
	control->first = elem1;
      if (control->last == elem1)
	control->last = elem2;
      else if (control->last == elem1)
	control->last = elem1;
    }
}
