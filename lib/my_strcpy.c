/*
** my_strcpy.c for my str cpy in /lib
**
** Made by Frederic ODDOU
** Login   <oddou_f@frederic.oddou@epitech.eu>
**
** Started on  Sat Nov  7 19:38:50 2015 Frederic ODDOU
** Last update Wed Mar 16 12:46:51 2016 Frederic ODDOU
*/

#include <stdlib.h>

char		*my_strcpy(char *dest, char *src)
{
  unsigned int	nb;

  nb = 0;
  if (dest == NULL || src == NULL)
    return (NULL);
  while (src[nb] != '\0')
    {
      dest[nb] = src[nb];
      nb++;
    }
  dest[nb] = '\0';
  return (dest);
}
