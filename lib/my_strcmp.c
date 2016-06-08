/*
** my_strcmp.c for my strcmp in /lib
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Nov  7 19:36:50 2015 Frederic ODDOU
** Last update Sat Nov  7 19:37:16 2015 Frederic ODDOU
*/

#include <stdlib.h>

int		my_strcmp(char *s1, char *s2)
{
  unsigned int	i;

  i = 0;
  if (s1[i] != s2[i] || s1 == NULL || s2 == NULL)
    return (-1);
  while (s1[i] != '\0' || s2[i] != '\0')
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  return (0);
}
