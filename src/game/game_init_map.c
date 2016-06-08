/*
** game_init_map.c for PSU_2015_tetris in /src/game/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 02 13:51:16 2016 antoine
** Last update	Thu Mar 17 14:14:48 2016 antoine GANNAT
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>
#include "tetris.h"
#include "my.h"

void	game_get_high_score(t_tetris	*tetris)
{
  int	fd;
  char	*str;
  int	res;

  res = 0;
  if ((fd = open("save.tet", O_RDONLY)) == -1)
    return;
  while ((str = get_next_read(fd)) != NULL)
    {
      if (my_getnbr(str) > res)
	res = my_getnbr(str);
      free(str);
    }
  tetris->high_score = res;
}

int	game_init_map(t_tetris		*tetris)
{
  int	i;
  int	j;

  i = 0;
  if ((tetris->map = malloc(sizeof(char *) * (tetris->nb_line + 1))) == NULL)
    return (1);
  while (i < tetris->nb_line)
    {
      j = 0;
      if ((tetris->map[i] = malloc(sizeof(char) * tetris->nb_col)) == NULL)
	return (1);
      while (j < tetris->nb_col)
	{
	  tetris->map[i][j] = -1;
	  j++;
	}
      i++;
    }
  tetris->map[i] = NULL;
  tetris->timer = time(NULL);
  tetris->use_ghost = 0;
  game_get_high_score(tetris);
  return (0);
}
