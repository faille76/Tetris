/*
** loadpiece.c for PSU_2015_tetris in /src/Piece/loadpiece
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 14:37:39 2016 antoine
** Last update	Sun Mar 20 14:28:39 2016 antoine GANNAT
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <dirent.h>
#include "piece.h"
#include "tetris.h"
#include "my.h"

int			piece_find_higher(t_piece	*piece)
{
  if (piece->lines > piece->col)
    return (piece->lines);
  return (piece->col);
}

int			check_piece(char		*str)
{
  int			i;
  int			i2;

  if (my_strcmp(str, ".") == 0 || my_strcmp(str, "..") == 0)
    return (1);
  if ((i = my_strstr_end(str, ".tetrimino")) == -1)
    return (1);
  i2 = i;
  while (str[i2] != '\0')
    i2++;
  if (i + 10 != i2)
    return (1);
  return (0);
}

int			piece_add_to_list(char 		*name,
					  t_tetris	*tetris)
{
  int			fd;
  char			*res;

  res = my_strcat_fusion("./tetriminos/", name);
  if ((fd = open(res, O_RDONLY)) == -1)
    return (1);
  if (piece_add_value(tetris->list_piece, fd, name) == 1
      || piece_parser(tetris->list_piece->last, tetris) == 1)
    tetris->list_piece->last->error = 1;
  tetris->list_piece->last->rotate = 0;
  free(res);
  return (0);
}

int			piece_load(t_tetris		*tetris)
{
  DIR			*fd;
  struct dirent 	*res;

  if ((fd = opendir("./tetriminos/")) == NULL)
    return (0);
  while ((res = readdir(fd)))
    {
      if (check_piece(res->d_name) == 0)
	{
	  piece_add(tetris->list_piece);
	  piece_add_to_list(res->d_name, tetris);
	}
    }
  closedir(fd);
  return (0);
}
