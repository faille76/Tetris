/*
** tetris_parser_map.c for tetris parser map in /src/parser/
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

int		tetris_parser_map(t_tetris	*tetris,
				  int 		ac,
				  char		**av,
				  short 	type)
{
  int		end;
  char		*str;

  (void)type;
  str = &av[ac][my_strlen("--map-size=")];
  if ((end = my_strstr(str, ",")) >= 1)
    {
      tetris->nb_line = my_getnbr(str);
      tetris->nb_col = my_getnbr(&str[end + 1]);
    }
  else
    tetris->error = 1;
  return (0);
}
