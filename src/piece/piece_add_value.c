/*
** pieceaddvalue.c for PSU_2015_tetris in src/Piece
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Fri Feb 26 16:00:09 2016 antoine
** Last update	Sun Mar 20 14:48:59 2016 antoine GANNAT
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"
#include "tetris.h"
#include "piece.h"

int			piece_check_end_line(char	*str,
					     t_piece	*piece,
					     int	line)
{
  int			i;
  int			size;

  i = 0;
  size = piece_find_higher(piece);
  while (str[i] != '\0')
    i++;
  if (i > size)
    {
      i = size - 1;
      while (str[i] != '\0')
	{
	  if (str[i] != ' ' && str[i] != '\n' && str[i] != '\t')
	    {
	      piece->tab[line] = NULL;
	      return (1);
	    }
	  i++;
	}
    }
  return (0);
}

int			piece_check_end_file(int	fd)
{
  char			*str;
  int			i;

  while ((str = get_next_read(fd)))
    {
      i = 0;
      while (str[i] != '\0')
	{
	  if (str[i] == '*')
	    {
	      free(str);
	      return (1);
	    }
	  i++;
	}
      free(str);
    }
  return (0);
}

int			piece_load_tab(t_control_piece 		*p,
				       int			fd)
{
  int			i;
  char			*str;

  i = 0;
  while (i <= p->last->lines - 1 && (str = get_next_read(fd)) != NULL)
    {
      if ((p->last->tab[i] = malloc(sizeof(char)
				    * (piece_find_higher(p->last) + 2))) == NULL)
	return (1);
      if ((int)my_strlen(str) > piece_find_higher(p->last))
	{
	  if (piece_check_end_line(str, p->last, i) == 1)
	    return (1);
	  p->last->tab[i] = my_strncpy(p->last->tab[i], str,
				       piece_find_higher(p->last));
	}
      else
	p->last->tab[i] = my_strncpy(p->last->tab[i], str, my_strlen(str));
      free(str);
      i++;
    }
  p->last->tab[i] = NULL;
  if (str == NULL || piece_check_end_file(fd) == 1)
    return (1);
  return (0);
}

int			get_piece_name(char 			*name,
				       t_control_piece		*piece)
{
  int			i;
  int			end;
  char			*new;

  i = 0;
  if (name == NULL)
    return (1);
  if ((new = malloc((my_strlen(name) - 9) * sizeof(char))) == NULL)
    return (1);
  end = my_strstr_end(name, ".tetrimino");
  while (name[i] != '\0' && i != end)
    {
      new[i] = name[i];
      i++;
    }
  new[i] = '\0';
  piece->last->name = new;
  return (0);
}

int			piece_add_value(t_control_piece		*piece,
					int 			fd,
					char 			*name)
{
  char			*str;

  if (get_piece_name(name, piece) == 1)
    {
      piece->last->name = NULL;
      return (1);
    }
  if ((str = get_next_read(fd)) == NULL)
    return (1);
  if (loadfirstline(piece, str) == 1)
    {
      free(str);
      return (1);
    }
  free(str);
  if ((piece->last->tab = malloc(sizeof(char *)
			     * (piece_find_higher(piece->last) + 1))) == NULL)
    return (1);
  if (piece_load_tab(piece, fd) == 1)
    return (1);
  return (0);
}
