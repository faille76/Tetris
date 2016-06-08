/*
** my_strcat.c for my str cat in /lib
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Nov  7 19:33:40 2015 Frederic ODDOU
** Last update Sat Nov  7 19:33:54 2015 Frederic ODDOU
*/

#include <stdlib.h>
#include "my.h"

char		*my_strcat(char *dest, char *src)
{
  unsigned int	id;
  unsigned int	is;

  is = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  id = my_strlen(dest);
  while (src[is] != '\0')
    {
      dest[id] = src[is];
      id++;
      is++;
    }
  dest[id] = '\0';
  return (dest);
}
