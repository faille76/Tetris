/*
** tetris_parser_level.c for tetris_parser_level in /src/parser/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Sun Feb 28 13:19:12 2016 Frederic ODDOU
** Last update Sun Feb 28 13:19:12 2016 Frederic ODDOU
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"
#include "piece.h"
#include "keyboard.h"
#include "parser.h"

int		tetris_parser_level(t_tetris	*tetris,
				    int 	ac,
				    char 	**av,
				    short 	type)
{
  unsigned int	len;

  len = my_strlen("--level=");
  if (type == 1)
    {
      tetris->level = my_getnbr(av[ac + 1]);
      return (1);
    }
  else
    {
      if (my_strlen(av[ac]) > len)
	{
	  tetris->level = my_getnbr(&av[ac][len]);
	  if (tetris->level < 1)
	    tetris->error = 1;
	}
      else
	tetris->error = 1;
    }
  return (0);
}
