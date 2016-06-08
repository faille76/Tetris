/*
** char.c for sources in /home/antoine/Documents/my_printf/sources
**
** Made by gannat-a
** Login   <antoine@epitech.net>
**
** Started on  Wed Nov 11 16:10:06 2015 gannat-a
** Last update	Mon Mar 14 13:34:40 2016 Full Name
*/

#include <stdarg.h>
#include "my.h"

int	charaff(va_list ap)
{
  my_putchar(va_arg(ap, int));
  return (0);
}
