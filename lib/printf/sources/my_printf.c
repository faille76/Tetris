/*
** my_printf.c for my_printf in /home/antoine/Documents/my_printf
**
** Made by gannat-a
** Login   <antoine@epitech.net>
**
** Started on  Tue Nov  3 13:59:37 2015 gannat-a
** Last update	Tue Mar 15 16:01:30 2016 antoine GANNAT
*/

#include <stdlib.h>
#include <stdarg.h>
#include "my.h"

void	setparams(int i, va_list ap)
{
  int (*ptrfct[10])(va_list);
  ptrfct[0] = &nbaff;
  ptrfct[1] = &nbaff;
  ptrfct[2] = &string;
  ptrfct[3] = &charaff;
  ptrfct[i](ap);
}

int	my_type(char *str, int i)
{
  char	*params;
  int	j;

  params = "discb";
  j = 0;
  while (str[i] != params[j] && params[j] != '\0')
    {
      j++;
    }
  return (j);
}

void	my_printf(char *str, ...)
{
  int		i;
  va_list	ap;

  i = 0;
  va_start(ap, str);
  while (str[i] != '\0')
    {
      if (str[i] == '%')
	{
	  setparams(my_type(str, i + 1), ap);
	  i = i + 1;
	}
      else if (str[i] != '\0' && str[i] != '%')
	my_putchar(str[i]);
      i++;
      va_end(ap);
    }
}
