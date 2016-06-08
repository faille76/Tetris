/*
** tetris_parser.c for tetris parser in /src/core/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Feb 26 14:43:25 2016 Frederic ODDOU
** Last update	Fri Mar 18 17:14:17 2016 antoine GANNAT
*/

#include <stdlib.h>
#include "my.h"
#include "tetris.h"
#include "piece.h"
#include "keyboard.h"
#include "parser.h"

int		tetris_parser_ck(char			*s1,
				 char 			*s2,
				 int 			i,
				 int 			ac)
{
  if (s1 != NULL && my_strncmp(s1, s2, my_strlen(s1)) == 0)
    {
      if (i >= 0)
	{
	  if (my_strlen(s1) == my_strlen(s2))
	    {
	      if (my_strcmp("-d", s2) == 0 || my_strcmp("-w", s2) == 0)
		return (1);
	      else if (ac > i)
		return (1);
	    }
	}
      else
	{
	  if (!my_strcmp("--debug", s2) || !my_strcmp("--without-next", s2))
	    return (2);
	  else if (my_strncmp("--debug", s2, my_strlen(s1)) &&
		   my_strncmp("--without-next", s2, my_strlen(s1)) &&
		   my_strlen(s1) < my_strlen(s2))
	    return (2);
	}
    }
  return (0);
}

int		tetris_parser_exec(t_tetris 		*tetris,
				   int 			ac,
				   char 		**av,
				   t_fptr_parser	flags[])
{
  int		i;
  int		search;
  int		ok;

  i = 1;
  while (i < ac)
    {
      search = 0;
      ok = -1;
      while (flags[search].function != NULL && ok == -1)
	{
	  ok = 0;
	  if (tetris_parser_ck(flags[search].short_arg, av[i], i, ac) == 1)
	    i += (flags[search].function)(tetris, i, av, 1);
	  else if (tetris_parser_ck(flags[search].long_arg, av[i], -1, ac) == 2)
	    i += (flags[search].function)(tetris, i, av, 2);
	  else
	    ok = -1;
	  search++;
	}
      if (ok == -1)
	return (1);
      i++;
    }
  return (0);
}

int		tetris_parser(t_tetris			*tetris,
			      int 			ac,
			      char 			**av)
{
  t_fptr_parser	flags[] = {
    {"-l", "--level=", &tetris_parser_level},
    {"-kl", "--key-left=", &tetris_parser_left},
    {"-kr", "--key-right=", &tetris_parser_right},
    {"-kt", "--key-turn=", &tetris_parser_turn},
    {"-kd", "--key-drop=", &tetris_parser_drop},
    {"-kq", "--key-quit=", &tetris_parser_quit},
    {"-kp", "--key-pause=", &tetris_parser_pause},
    {NULL, "--map-size=", &tetris_parser_map},
    {"-w", "--without-next", &tetris_parser_without},
    {"-d", "--debug", &tetris_parser_debug},
    {NULL, NULL, NULL},
  };

  if (tetris_parser_exec(tetris, ac, av, flags) == 1 || tetris->error > 0)
    {
      my_putstr("Un problème est survenue durant le parsing.\n");
      return (1);
    }
  if (tetris_parser_final(tetris))
    {
      my_putstr("Un doublon de touche est détecté.\n");
      return (1);
    }
  return (0);
}
