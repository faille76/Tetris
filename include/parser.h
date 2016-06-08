/*
** tetris.h for tetris in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Feb 26 12:01:58 2016 Frederic ODDOU
** Last update Fri Feb 26 17:07:21 2016 antoine
*/

#ifndef PARSER_H_
# define PARSER_H_

# include "struct.h"

int		tetris_parser(t_tetris			*tetris,
			      int			ac,
			      char			**av);
int		tetris_parser_exec(t_tetris 		*tetris,
				   int			ac,
				   char			**av,
				   t_fptr_parser	flags[]);

int		tetris_parser_level(t_tetris		*tetris,
				   int 			ac,
				   char 		**av,
				   short 		type);
int		tetris_parser_left(t_tetris		*tetris,
				   int 			ac,
				   char 		**av,
				   short 		type);
int		tetris_parser_right(t_tetris		*tetris,
				   int 			ac,
				   char 		**av,
				   short 		type);
int		tetris_parser_turn(t_tetris		*tetris,
				   int 			ac,
				   char 		**av,
				   short 		type);
int		tetris_parser_drop(t_tetris		*tetris,
				   int 			ac,
				   char 		**av,
				   short 		type);
int		tetris_parser_quit(t_tetris		*tetris,
				   int 			ac,
				   char 		**av,
				   short 		type);
int		tetris_parser_pause(t_tetris		*tetris,
				   int 			ac,
				   char 		**av,
				   short 		type);
int		tetris_parser_map(t_tetris		*tetris,
				   int 			ac,
				   char 		**av,
				   short 		type);
int		tetris_parser_without(t_tetris		*tetris,
				   int 			ac,
				   char 		**av,
				   short 		type);
int		tetris_parser_debug(t_tetris		*tetris,
				   int 			ac,
				   char 		**av,
				   short 		type);

int		tetris_parser_check_keys_doublon(char 	c,
						 char 	*c_keys,
						 int	i);
int		tetris_parser_check_keys(t_tetris 	*tetris);
int		tetris_parser_final(t_tetris 		*tetris);

#endif /* PARSER_H_ */
