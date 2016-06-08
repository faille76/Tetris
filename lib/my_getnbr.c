/*
** my_getnbr.c for Getnbr in /lib
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Nov  4 11:34:05 2015 Frederic ODDOU
** Last update Sun Nov 15 17:07:26 2015 Frederic ODDOU
*/

#include <stdlib.h>

int		my_getnbr(char *str)
{
  unsigned int	i;
  int		neg;
  int		nbr;

  i = 0;
  neg = 0;
  nbr = 0;
  if (str == NULL)
    return (0);
  while ((str[i] < '0' || str[i] > '9') && str[i] != '\0')
    {
      if (str[i] == '-')
	neg++;
      i++;
    }
  while (str[i] >= '0' && str[i] <= '9' && str[i] != '\0')
    {
      nbr = (nbr * 10) + (str[i] - '0');
      i++;
    }
  if (neg % 2 == 1)
    nbr = -(nbr);
  return (nbr);
}
