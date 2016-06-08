/*
** main.c for main in /src/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Feb 26 11:40:13 2016 Frederic ODDOU
** Last update	Sun Mar 20 21:49:18 2016 antoine GANNAT
*/

#include <signal.h>
#include <ncurses.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>
#include <stdlib.h>
#include <termios.h>
#include "my.h"
#include "game.h"
#include "tetris.h"
#include "parser.h"
#include "display.h"
#include "piece.h"

void		init_ioctl(int	mode)
{
  static struct termios	oldT;
  static struct termios	newT;

  if (mode == 1)
    {
      ioctl(0, TCGETS, &oldT);
      ioctl(0, TCGETS, &newT);
      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      ioctl(0, TCSETS, &newT);
    }
  else if (mode == 2)
    {
      ioctl(0, TCGETS, &newT);
      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      newT.c_cc[VMIN] = 0;
      newT.c_cc[VTIME] = 0;
      ioctl(0, TCSETS, &newT);
    }
  else if (mode == 0)
    ioctl(0, TCSETS, &oldT);
}

int			tetris_main(t_tetris *tetris)
{
  SCREEN		*win;

  init_ioctl(1);
  tetris_debug(tetris);
  if ((win = window_start(tetris)) == NULL)
    {
      tetris_free(tetris);
      return (1);
    }
  piece_delete_error(tetris->list_piece);
  game_play(tetris);
  window_stop(win, tetris);
  return (0);
}

void			sighandler(int signum)
{
  (void)signum;
}

int			main(int	ac,
			     char	**av,
			     char	**ae)
{
  t_tetris		*tetris;

  signal(SIGQUIT, sighandler);
  if (tetris_if_help(ac, av) == 1)
    tetris_help(av[0]);
  else
    {
      if ((tetris = tetris_init(ae)) == NULL)
	{
          tetris_help(av[0]);
	  tetris_free(tetris);
	  return (1);
	}
      if (tetris_parser(tetris, ac, av) == 1 || piece_load(tetris) == 1)
	{
          tetris_help(av[0]);
	  tetris_free(tetris);
	  return (1);
	}
      if (tetris_main(tetris) == 1)
	return (1);
      tetris_free(tetris);
      init_ioctl(0);
    }
  return (0);
}
