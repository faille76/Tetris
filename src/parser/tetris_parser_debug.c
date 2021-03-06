/*
** tetris_parser_debug.c for tetris parser debug in /src/parser/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Feb 28 13:20:09 2016 Frederic ODDOU
** Last update Sun Feb 28 13:20:09 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"
#include "piece.h"
#include "keyboard.h"
#include "parser.h"

int		tetris_parser_debug(t_tetris 	*tetris,
				    int 	ac,
				    char 	**av,
				    short 	type)
{
  (void)ac;
  (void)av;
  (void)type;
  tetris->debug = 1;
  return (0);
}
