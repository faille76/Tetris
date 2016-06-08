/*
** my_putstr.c for Put str in /lib
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Nov  4 10:44:07 2015 Frederic ODDOU
** Last update Sat Nov 14 16:35:41 2015 Frederic ODDOU
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

unsigned int	my_putstr(char *str)
{
  if (str == NULL)
    return (my_putstr("(null)"));
  return (write(1, str, my_strlen(str)));
}
