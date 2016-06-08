/*
** game_save.c for PSU_2015_tetris
**
** Made by	Full Name
** Login	Full Name
**
** Started on	Mon Mar 14 10:02:57 2016 Full Name
** Last update	Tue Mar 15 18:43:20 2016 antoine GANNAT
*/

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "tetris.h"

int	get_nbr_length(int		nbr)
{
  int	i;

  i = 1;
  while (nbr > 9)
    {
      nbr /= 10;
      i *= 10;
    }
  return (i);
}

void	game_save(t_tetris		*tetris)
{
  int	fd;
  int	n;
  char	str[1];

  if (tetris->score == 0)
    return;
  n = get_nbr_length(tetris->score);
  if ((fd = open("save.tet", O_CREAT | O_WRONLY | O_APPEND, 0666)) == -1)
    return;
  while (n >= 1)
    {
      str[0] = ((tetris->score / n) % 10) + 48;
      write(fd, &str, 1);
      n /= 10;
    }
  write(fd, "\n", 1);
}
