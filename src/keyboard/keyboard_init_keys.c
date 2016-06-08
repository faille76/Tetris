/*
** keyboard_init_keys.c for init keys in /src/keyboard/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Mar 18 15:54:45 2016 Frederic ODDOU
** Last update	Fri Mar 18 17:08:30 2016 antoine GANNAT
*/

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <term.h>
#include <termios.h>
#include "my.h"

char			*keyboard_init_keys(char	*name,
					    char	*name_term)
{
  char			*keys;

  if (tgetent(NULL, name_term) == -1)
    {
      my_printf("Le terminal %s n'est pas compatible.\n", name_term);
      return (NULL);
    }
  if ((keys = tgetstr(name, NULL)) == NULL)
    {
      my_printf("La touche %s n'est pas reconnue par le terminal.\n", name);
      return (NULL);
    }
  return (keys);
}
