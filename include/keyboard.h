/*
** keyboard.h for keyboard in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Fri Feb 26 16:11:06 2016 Frederic ODDOU
** Last update	Thu Mar 17 14:12:12 2016 antoine GANNAT
*/

#ifndef KEYBOARD_H_
# define KEYBOARD_H_

# include <ncurses.h>
# include "struct.h"

# define DEFAULT_KEY_LEFT	"kl"
# define DEFAULT_KEY_RIGHT	"kr"
# define DEFAULT_KEY_TURN	"ku"
# define DEFAULT_KEY_DROP	"kd"
# define DEFAULT_KEY_GHOST	"a"
# define DEFAULT_KEY_QUIT	"q"
# define DEFAULT_KEY_PAUSE	" "

t_keyboard	*keyboard_init(char		**ae);
char		*keyboard_init_keys(char	*name,
				    char	*name_term);

#endif /* KEYBOARD_H_ */
