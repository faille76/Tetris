/*
** piece_init.c for list_init in /src/Piece/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Dec 13 12:03:06 2015 Frederic ODDOU
** Last update Mon Dec 14 22:33:00 2015 Frederic ODDOU
*/

#include <stdlib.h>
#include "piece.h"

t_control_piece		*piece_init()
{
  t_control_piece	*control;

  if ((control = malloc(sizeof(*control))) == NULL)
    return (NULL);
  control->count = 0;
  control->first = NULL;
  control->last = NULL;
  return (control);
}
