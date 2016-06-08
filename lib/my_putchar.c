/*
** my_putchar.c for Put char in /lib
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Nov  4 10:43:28 2015 Frederic ODDOU
** Last update Tue Dec  1 15:31:13 2015 Frederic ODDOU
*/

#include <unistd.h>

int	my_putchar(char c)
{
  return (write(1, &c, 1));
}
