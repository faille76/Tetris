/*
** my_strdup.c for my strdup in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Nov 26 12:03:51 2015 Frederic ODDOU
** Last update Thu Nov 26 12:04:49 2015 Frederic ODDOU
*/

#include <stdlib.h>
#include "my.h"

char		*my_strdup(char *str)
{
  char		*new;
  unsigned int	nb;

  nb = 0;
  if (str == NULL)
    return (NULL);
  if ((new = malloc((my_strlen(str) + 1) * sizeof(char))) == NULL)
    return (NULL);
  nb = 0;
  while (str[nb] != '\0')
    {
      new[nb] = str[nb];
      nb++;
    }
  new[nb] = '\0';
  return (new);
}
