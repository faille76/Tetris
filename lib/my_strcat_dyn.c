/*
** my_strcat_dyn.c for my strcat dyn in /lib
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Nov  7 19:34:52 2015 Frederic ODDOU
** Last update Fri Feb 26 18:23:06 2016 antoine
*/

#include <stdlib.h>
#include "my.h"

char		*my_strcat_fusion(char *dest, char *src)
{
  unsigned int	id;
  unsigned int	is;
  char		*new;

  id = 0;
  is = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  if ((new = malloc(my_strlen(dest) + my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (dest[id] != '\0')
    {
      new[id] = dest[id];
      id++;
    }
  while (src[is] != '\0')
    {
      new[id] = src[is];
      id++;
      is++;
    }
  new[id] = '\0';
  return (new);
}

char		*my_strcat_dyn(char *dest, char *src)
{
  unsigned int	id;
  unsigned int	is;
  char		*new;

  id = 0;
  is = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  if ((new = malloc(my_strlen(dest) + my_strlen(src) + 1)) == NULL)
    return (NULL);
  while (dest[id] != '\0')
    {
      new[id] = dest[id];
      id++;
    }
  while (src[is] != '\0')
    {
      new[id] = src[is];
      id++;
      is++;
    }
  new[id] = '\0';
  free(dest);
  return (new);
}

char		*my_strcat_dyn_char(char *dest, char src)
{
  unsigned int	id;
  char		*new;

  id = 0;
  if (dest == NULL)
    return (NULL);
  if ((new = malloc(my_strlen(dest) * sizeof(char) + 2)) == NULL)
    return (NULL);
  while (dest[id] != '\0')
    {
      new[id] = dest[id];
      id++;
    }
  new[id++] = src;
  new[id] = '\0';
  free(dest);
  return (new);
}
