/*
** debug.c for debug in /src/debug/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Tue Mar  1 13:44:23 2016 Frederic ODDOU
** Last update	Wed Mar 16 12:58:02 2016 antoine GANNAT
*/

#include <unistd.h>
#include "my.h"
#include "tetris.h"
#include "piece.h"

void		piece_display_piece(t_piece	*piece)
{
  int		i;

  i = 0;
  while (piece->tab[i] != NULL)
    {
      my_printf("%s\n", piece->tab[i]);
      i++;
    }
}

void		piece_view(t_control_piece	*control)
{
  t_piece	*list;
  int		i;

  i = 0;
  if (control->first != NULL && control->last != NULL)
    {
      list = control->first;
      while (i == 0 || list != control->first)
	{
	  my_printf("Tetriminos : Name %s : ", list->name);
	  if (list->error == 1)
	    my_putstr("Error\n");
	  else
	    {
	      my_printf("Size %d*%d : Color %d :\n", list->col,
			list->lines,
			list->color);
	      piece_display_piece(list);
	    }
	  list = list->next;
	  i++;
	}
    }
}

void		tetris_debug_list_keys(t_tetris *tetris)
{
  my_putstr("Key Left : ");
  tetris_debug_keys(tetris->keys->left);
  my_putstr("Key Right : ");
  tetris_debug_keys(tetris->keys->right);
  my_putstr("Key Turn : ");
  tetris_debug_keys(tetris->keys->turn);
  my_putstr("Key Drop : ");
  tetris_debug_keys(tetris->keys->drop);
  my_putstr("Key Quit : ");
  tetris_debug_keys(tetris->keys->quit);
  my_putstr("Key Pause : ");
  tetris_debug_keys(tetris->keys->pause);
}

void		tetris_debug(t_tetris		*tetris)
{
  char		c;

  if (tetris->debug)
    {
      my_putstr("*** DEBUG MODE ***\n");
      tetris_debug_list_keys(tetris);
      my_printf("Next : %s\n", (tetris->hide_next == 1) ? "Yes" : "No");
      my_printf("Level : %d\n", tetris->level);
      my_printf("Size : %d*%d\n", tetris->nb_line, tetris->nb_col);
      my_printf("Tetriminos : %d\n", tetris->list_piece->count);
      piece_sort_in_name(tetris->list_piece);
      piece_view(tetris->list_piece);
      my_putstr("Press a key to start Tetris\n");
      read(0, &c, 1);
    }
}
