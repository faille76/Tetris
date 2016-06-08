/*
** my_putstr_e.c for put str e in /lib/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sat Dec 12 14:54:02 2015 Frederic ODDOU
** Last update Sat Dec 12 15:01:45 2015 Frederic ODDOU
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

unsigned int	my_putstr_e(char *str)
{
  if (str == NULL)
    return (my_putstr_e("(null)"));
  return (write(2, str, my_strlen(str)));
}
