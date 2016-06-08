/*
** my_strncmp.c for my strncmp in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Nov 29 13:57:17 2015 Frederic ODDOU
** Last update Sun Nov 29 13:59:41 2015 Frederic ODDOU
*/

#include <stdlib.h>

int		my_strncmp(char *str, char *search, unsigned int nb)
{
  unsigned int	i;

  i = 0;
  if (str == NULL || search == NULL || str[i] != search[i])
    return (1);
  while (i < nb && str[i] != '\0' && search[i] != '\0')
    {
      if (str[i] != search[i])
	return (1);
      i++;
    }
  return (0);
}
