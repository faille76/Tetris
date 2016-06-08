/*
** my_revstr.c for my Rev str in /lib
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Nov  7 19:32:28 2015 Frederic ODDOU
** Last update Sat Nov  7 19:33:00 2015 Frederic ODDOU
*/

#include <stdlib.h>
#include "my.h"

char		*my_revstr(char *str)
{
  unsigned int	count;
  unsigned int	nb;
  char		rev;

  nb = 0;
  if (str == NULL)
    return (NULL);
  count = my_strlen(str) - 1;
  while (count > nb)
    {
      rev = str[nb];
      str[nb] = str[count];
      str[count] = rev;
      count--;
      nb++;
    }
  return (str);
}
