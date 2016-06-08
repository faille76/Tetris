/*
** my_putnbr.c for Put nbr in /lib
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Nov  4 10:49:37 2015 Frederic ODDOU
** Last update Sun Nov 15 13:17:47 2015 Frederic ODDOU
*/

#include "my.h"

int	my_putnbr(int nbr)
{
  int	pow;
  int	i;

  pow = 1;
  i = 0;
  if (nbr == -2147483648)
    i += my_putstr("-2147483648");
  else
    {
      if (nbr < 0)
	{
	  i += my_putchar('-');
	  nbr = -(nbr);
	}
      while ((nbr / pow) >= 10)
	pow *= 10;
      while (pow > 0)
	{
	  i += my_putchar(((nbr / pow) % 10) + '0');
	  pow /= 10;
	}
    }
  return (i);
}
