/*
** nbaff.c for sources in /home/antoine/Documents/my_printf/sources
**
** Made by gannat-a
** Login   <antoine@epitech.net>
**
** Started on  Wed Nov 11 16:22:19 2015 gannat-a
** Last update	Tue Mar 15 16:00:04 2016 antoine GANNAT
*/

#include <stdarg.h>
#include "my.h"

int	nbaff(va_list ap)
{
  int	nb;

  nb = va_arg(ap, int);
  my_putnbr(nb);
  return (0);
}
