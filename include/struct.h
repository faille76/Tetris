/*
** struct.h for struct in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Thu Mar 17 11:55:19 2016 Frederic ODDOU
** Last update	Thu Mar 17 14:11:39 2016 antoine GANNAT
*/

#ifndef STRUCT_H_
# define STRUCT_H_

typedef struct	s_keyboard
{
  char		*left;
  char		*right;
  char		*turn;
  char		*drop;
  char		*quit;
  char		*pause;
  char		*ghost;
}		t_keyboard;

/*
** Structure d'une pièce : donne les infos
*/
typedef struct		s_piece
{
  char			*name;
  int			col;
  int			lines;
  short			rotate;
  char			**tab;
  char			color;
  char			dir;
  short			error;
  struct s_piece	*next;
  struct s_piece	*prev;
}			t_piece;

/*
** Structure de controle des pièces
*/
typedef struct		s_control_piece
{
  int			count;
  struct s_piece	*first;
  struct s_piece	*last;
}			t_control_piece;

typedef struct		s_tetris
{
  unsigned int		high_score;
  unsigned int		score;
  unsigned int		line;
  int			level;
  short			error;
  unsigned int		timer;
  int			nb_line;
  int			nb_col;
  char			**map;
  short			debug;
  short			hide_next;
  short			use_ghost;
  short			next_piece;
  t_keyboard		*keys;
  t_control_piece	*list_piece;
}			t_tetris;

typedef struct	s_fptr_parser
{
  char		*short_arg;
  char		*long_arg;
  int		(*function)(t_tetris *, int ac, char **av, short type);
}		t_fptr_parser;

#endif /* STRUCT_H_ */
