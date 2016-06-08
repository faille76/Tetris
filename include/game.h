/*
** game.h for PSU_2015_tetris in /include/
**
** Made by antoine
** Login   <antoine@epitech.net>
**
** Started on  Wed Mar 02 13:48:18 2016 antoine
** Last update	Thu Mar 17 00:19:09 2016 antoine GANNAT
*/

#ifndef GAME_H_
# define GAME_H_

# include "struct.h"

int	game_collision(t_piece			*piece,
		       char 			**map,
		       int 			x,
		       int 			y);
int	game_collision_left(t_piece 		*piece,
			    char 		**map,
			    int 		x,
			    int 		y);
int	game_collision_right(t_piece		*piece,
			     char 		**map,
			     int 		x,
			     int 		y);
int	game_play(t_tetris			*tetris);
int	game_init_map(t_tetris			*tetris);
void	game_aff(t_piece			*piece,
		 int 				x,
		 int 				y,
		 t_tetris 			*tetris);
void	game_save_map(t_piece 			*piece,
		      t_tetris 			*tetris,
		      int 			x,
		      int 			y);
int	game_control(int 			*x,
		     int 			*y,
		     t_tetris 			*tetris,
		     t_piece 			*piece);
void	game_check_line(t_tetris 		*tetris);
t_piece	*game_change_piece(t_piece 		*piece,
			   int 			nbr);
void	game_save(t_tetris			*tetris);
int	game_pause(t_tetris			*tetris,
		   char				*keys);
void	game_end_screen(t_tetris		*tetris);

#endif /* GAME_H_ */
