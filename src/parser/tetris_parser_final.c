/*
** tetris_parser_final.c for tetris parser final in /src/parser/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Mar  2 14:43:15 2016 Frederic ODDOU
** Last update	Fri Mar 18 19:01:07 2016 antoine GANNAT
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"

int		tetris_parser_check_keys_doublon(char 	*c,
						 char 	**c_keys,
						 int	nb)
{
  short		i;

  i = nb + 1;
  while (i < 7)
    {
      if (my_strcmp(c_keys[i], c) == 0)
	return (1);
      i++;
    }
  return (0);
}

int		tetris_parser_check_keys(t_tetris	*tetris)
{
  char		**c_keys;
  short		i;

  i = 0;
  if ((c_keys = malloc(sizeof(char *) * 7)) == NULL)
    return (1);
  c_keys[0] = tetris->keys->left;
  c_keys[1] = tetris->keys->right;
  c_keys[2] = tetris->keys->turn;
  c_keys[3] = tetris->keys->drop;
  c_keys[4] = tetris->keys->quit;
  c_keys[5] = tetris->keys->pause;
  c_keys[6] = "null";
  while (i < 7)
    {
      if (tetris_parser_check_keys_doublon(c_keys[i], c_keys, i))
	return (1);
      i++;
    }
  free(c_keys);
  return (0);
}

int		tetris_parser_final(t_tetris		*tetris)
{
  if (tetris->nb_line <= 2 || tetris->nb_line > MAX_LINE)
    return (1);
  if (tetris->nb_col <= 2 || tetris->nb_col > MAX_COL)
    return (1);
  return (tetris_parser_check_keys(tetris));
}
