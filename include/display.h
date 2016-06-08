/*
** display.h for display in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Mar  1 14:34:17 2016 Frederic ODDOU
** Last update	Tue Mar 15 23:05:58 2016 antoine GANNAT
*/

#ifndef DISPLAY_H_
# define DISPLAY_H_

# include <ncurses.h>
# include "struct.h"

SCREEN		*window_start(t_tetris		*tetris);
void		window_stop(SCREEN 		*win,
			    t_tetris		*tetris);
void		display_board_line(int		height,
				   t_tetris	*tetris);
void		display_interface(t_tetris 	*tetris);
void		display_board(t_tetris		*tetris);

#endif /* DISPLAY_H_ */
