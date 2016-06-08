/*
** tetris.h for tetris in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Feb 26 12:01:58 2016 Frederic ODDOU
** Last update	Thu Mar 17 00:19:03 2016 antoine GANNAT
*/

#ifndef TETRIS_H_
# define TETRIS_H_

# include "struct.h"

# define DEFAULT_LINE	20
# define DEFAULT_COL	10
# define DEFAULT_LEVEL	1
# define DEFAULT_HIDE	1
# define DEFAULT_DEBUG	0

# define MAX_LINE	50
# define MAX_COL	100

t_tetris		*tetris_init(char	**ae);

int			tetris_if_help(int 	ac,
				       char 	**av);
void			tetris_help(char 	*str);

void			tetris_free(t_tetris 	*tetris);
void			tetris_debug(t_tetris 	*tetris);
void			tetris_debug_keys(char 	*c);

void			init_ioctl(int		mode);

#endif /* TETRIS_H_ */
