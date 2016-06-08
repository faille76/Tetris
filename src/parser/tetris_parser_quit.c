/*
** tetris_parser_quit.c for tetris parser quit in /src/parser/
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

int		tetris_parser_quit(t_tetris	*tetris,
				   int 		ac,
				   char 	**av,
				   short 	type)
{
  unsigned int	len;

  len = my_strlen("--key-quit=");
  if (type == 1)
    {
      tetris->keys->quit = av[ac + 1];
      return (1);
    }
  else
    {
      if (my_strlen(av[ac]) > len)
	tetris->keys->quit = &av[ac][len];
      else
	tetris->error = 1;
    }
  return (0);
}
