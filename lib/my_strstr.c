/*
** my_strstr.c for str str in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Mar  1 13:37:33 2016 Frederic ODDOU
** Last update Tue Mar  1 13:37:33 2016 Frederic ODDOU
*/

#include "my.h"

int	my_strstr(char *str, char *end)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (my_strncmp(&str[i], end, my_strlen(end)) == 0)
	return (i);
      i++;
    }
  return (-1);
}

int		my_strstr_end(char	*str,
			      char	*end)
{
  int	i;
  int	last;

  i = 0;
  last = -1;
  while (str[i] != '\0')
    {
      if (my_strncmp(&str[i], end, my_strlen(end)) == 0)
	last = i;
      i++;
    }
  return (last);
}
