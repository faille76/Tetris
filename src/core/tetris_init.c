/*
** tetris_init.c for tetris init in /src/core/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Feb 26 14:28:30 2016 Frederic ODDOU
** Last update	Fri Mar 18 17:03:30 2016 antoine GANNAT
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"
#include "piece.h"
#include "keyboard.h"

t_tetris	*tetris_init(char	**ae)
{
  t_tetris	*tetris;

  if ((tetris = malloc(sizeof(*tetris))) == NULL)
    return (NULL);
  tetris->map = NULL;
  tetris->high_score = 0;
  tetris->score = 0;
  tetris->line = 0;
  tetris->level = DEFAULT_LEVEL;
  tetris->timer = 0;
  tetris->nb_line = DEFAULT_LINE;
  tetris->nb_col = DEFAULT_COL;
  tetris->hide_next = DEFAULT_HIDE;
  tetris->debug = DEFAULT_DEBUG;
  tetris->error = 0;
  if ((tetris->list_piece = piece_init()) == NULL)
    return (NULL);
  if ((tetris->keys = keyboard_init(ae)) == NULL)
    return (NULL);
  return (tetris);
}
