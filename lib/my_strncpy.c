/*
** my_strcpy.c for my str cpy in /lib
**
** Made by Frederic ODDOU
** Login   <oddou_f@frederic.oddou@epitech.eu>
**
** Started on  Sat Nov  7 19:38:50 2015 Frederic ODDOU
** Last update	Thu Mar 17 18:38:47 2016 antoine GANNAT
*/

#include <stdlib.h>

char		*my_strncpy(char *dest, char *src, int len)
{
  unsigned int	nb;

  nb = 0;
  if (src == NULL)
    return (NULL);
  while (src[nb] != '\0' && nb < (unsigned int)len)
    {
      dest[nb] = src[nb];
      nb++;
    }
  dest[nb] = '\0';
  return (dest);
}
