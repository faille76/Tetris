/*
** my_name_compare.c for name compare in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Mar  2 10:37:02 2016 Frederic ODDOU
** Last update Wed Mar  2 10:37:02 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include "my.h"

int		my_name_compare(char *la, char *lb)
{
  unsigned int	i;

  if (la == NULL || lb == NULL)
    return (1);
  i = 0;
  while (la[i] != '\0' && lb[i] != '\0')
    {
      if (la[i] > lb[i])
	return (1);
      else if (la[i] == lb[i])
	i++;
      else
	return (0);
    }
  if (my_strlen(la) > my_strlen(lb))
    return (1);
  return (0);
}
