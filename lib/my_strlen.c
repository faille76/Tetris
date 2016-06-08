/*
** my_strlen.c for Strlen in /lib
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Nov  4 21:00:19 2015 Frederic ODDOU
** Last update Wed Nov  4 21:00:20 2015 Frederic ODDOU
*/

#include <stdlib.h>

unsigned int	my_strlen(char *str)
{
  unsigned int	i;

  i = 0;
  if (str == NULL)
    return (0);
  while (str[i] != '\0')
    i++;
  return (i);
}
