/*
** string.c for sources in /home/antoine/Documents/my_printf/sources
**
** Made by gannat-a
** Login   <antoine@epitech.net>
**
** Started on  Wed Nov 11 15:53:56 2015 gannat-a
** Last update	Mon Mar 14 13:34:23 2016 Full Name
*/

#include <stdarg.h>
#include "my.h"

int	string(va_list ap)
{
  my_putstr(va_arg(ap, char*));
  return (0);
}
