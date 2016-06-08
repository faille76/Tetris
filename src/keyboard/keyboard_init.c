/*
** keyboard_init.c for keyboard init in /src/keyboard/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Feb 26 16:32:31 2016 Frederic ODDOU
** Last update	Fri Mar 18 17:11:33 2016 antoine GANNAT
*/

#include <stdlib.h>
#include "keyboard.h"
#include "my.h"

char		*my_getenv(char			**ae)
{
  int		i;

  i = 0;
  while (ae[i] != NULL)
    {
      if (my_strncmp(ae[i], "TERM=", 5) == 0)
	return (&ae[i][5]);
      i++;
    }
  return (NULL);
}

t_keyboard	*keyboard_init(char		**ae)
{
  t_keyboard	*keys;
  char		*name_env;

  if ((name_env = my_getenv(ae)) == NULL)
    name_env = "xterm";
  if ((keys = malloc(sizeof(*keys))) == NULL)
    return (NULL);
  if ((keys->left = keyboard_init_keys(DEFAULT_KEY_LEFT, name_env)) == NULL)
    return (NULL);
  if ((keys->right = keyboard_init_keys(DEFAULT_KEY_RIGHT, name_env)) == NULL)
    return (NULL);
  if ((keys->turn = keyboard_init_keys(DEFAULT_KEY_TURN, name_env)) == NULL)
    return (NULL);
  if ((keys->drop = keyboard_init_keys(DEFAULT_KEY_DROP, name_env)) == NULL)
    return (NULL);
  keys->quit = DEFAULT_KEY_QUIT;
  keys->pause = DEFAULT_KEY_PAUSE;
  keys->ghost = DEFAULT_KEY_GHOST;
  (void)ae;
  return (keys);
}
