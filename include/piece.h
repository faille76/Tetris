/*
** tetris.h for tetris in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Feb 26 12:01:58 2016 Frederic ODDOU
** Last update	Thu Mar 17 15:48:57 2016 antoine GANNAT
*/

#ifndef PIECE_H_
# define PIECE_H_

# include "struct.h"

t_control_piece		*piece_init();
void			piece_add(t_control_piece		*control);
void			piece_delete(t_control_piece		*control,
				     t_piece			*elem);
void			piece_free(t_control_piece		*control);
int			piece_rotate(t_piece			*piece,
				     int 			x,
				     int 			y,
				     t_tetris			*tetris);
void			piece_sort_in_name(t_control_piece	*control);
void			piece_swap(t_control_piece		*control,
				   t_piece 			*elem1,
				   t_piece 			*elem2);
void			piece_swap_in(t_piece 			*elem1,
				      t_piece 			*elem2);
void			piece_swap_beside(t_piece 		*elem1,
					  t_piece 		*elem2);
void			piece_free_tab(char			**tab);
int			piece_find_higher(t_piece 		*piece);
int			piece_load(t_tetris			*tetris);
int			piece_add_to_list(char			*name,
					  t_tetris		*tetris);
void			piece_delete_error(t_control_piece	*control);
int			piece_add_value(t_control_piece		*piece,
					int 			fd,
					char 			*name);
char			*getelemnbr(char 			*str,
				    int 			nbr);
int			piece_parser(t_piece			*piece,
				     t_tetris			*tetris);
int			loadfirstline(t_control_piece		*piece,
				      char 			*str);
void			piece_free_tab(char 			**tab);
void			piece_fill_tab(t_tetris			*tetris);

#endif /* PIECE_H_ */
