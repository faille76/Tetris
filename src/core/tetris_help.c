/*
** tetris_help.c for tetris help in /src/core/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Feb 26 15:58:37 2016 Frederic ODDOU
** Last update Fri Feb 26 16:48:58 2016 oddou_f
*/

#include "my.h"

void	tetris_help(char	*name)
{
  my_putstr("Usage: ");
  my_putstr(name);
  my_putstr(" [options]\n");
  my_putstr("Options:\n");
  my_putstr("--help\t\t\tDisplay this help\n");
  my_putstr("-l --level={num}\tStart Tetris at level num\n");
  my_putstr("-kl --key-left={K}\tMove tetrimino on LEFT with key K\n");
  my_putstr("-kr --key-right={K}\tMove tetrimino on RIGHT with key K\n");
  my_putstr("-kt --key-turn={K}\tTurn tetrimino with key K\n");
  my_putstr("-kd --key-drop={K}\tSet default DROP on key K\n");
  my_putstr("-kq --key-quit={K}\tQuit program when press key K\n");
  my_putstr("-kp --key-pause={K}\tPause and restart game when press key K\n");
  my_putstr("--map-size={row,col}\tSet game size at row, col\n");
  my_putstr("-w --without-next\tHide next tetrimino\n");
  my_putstr("-d --debug\t\tDebug mode\n");
}

int	tetris_if_help(int	ac,
		       char 	**av)
{
  int	i;

  i = 1;
  while (i < ac)
    {
      if (my_strcmp(av[i], "--help") == 0)
	return (1);
      i++;
    }
  return (0);
}
