/*
** piece_load_first_line.c for PSU_2015_tetris
**
** Made by	Full Name
** Login	Full Name
**
** Started on	Tue Mar 08 15:34:22 2016 Full Name
** Last update	Fri Mar 18 17:27:21 2016 antoine GANNAT
*/

#include <stdio.h>
#include <stdlib.h>
#include "my.h"
#include "tetris.h"
#include "piece.h"

char	*getelemnbr(char		*str,
		    int 		nbr)
{
  int	i;
  int	count;

  i = 0;
  count = 0;
  if (str[0] == ' ' || str[0] == '\0')
    return (NULL);
  while (count < nbr && str[i] != '\0')
    {
      if (str[i] == ' ')
	count++;
      i++;
    }
  return (&str[i]);
}

int	loadfirstline(t_control_piece 	*piece,
		      char 		*str)
{
  char	*out;

  if ((out = getelemnbr(str, 0)) == NULL)
    return (1);
  piece->last->col = my_getnbr(out);
  if ((out = getelemnbr(str, 1)) == NULL)
    return (1);
  piece->last->lines = my_getnbr(out);
  if (piece->last->col < 0 || piece->last->lines < 0)
    return (1);
  if ((out = getelemnbr(str, 2)) == NULL)
    return (1);
  piece->last->color = my_getnbr(out);
  piece->last->rotate = 0;
  if (piece->last->color <= 0 || piece->last->color > 7)
    return (1);
  return (0);
}
