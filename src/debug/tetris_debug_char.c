/*
** tetris_debug_char.c for tetris debug char in /src/debug/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Mar 17 15:21:58 2016 Frederic ODDOU
** Last update Thu Mar 17 15:21:58 2016 Frederic ODDOU
*/

#include "my.h"

void		tetris_debug_keys(char 		*c)
{
  int		i;

  i = 0;
  while (c[i] != '\0')
    {
      if (c[i] == '\e')
	my_putstr("^E");
      else if (c[i] == ' ')
	my_putstr("(space)");
      else
	my_putchar(c[i]);
      i++;
    }
  my_putchar('\n');
}
