/*
** my.h for My.h in /include/
**
** Made by Frederic ODDOU
** Login oddou_f <frederic.oddou@epitech.eu>
**
** Started on  Wed Nov  4 10:51:07 2015 Frederic ODDOU
** Last update	Tue Mar 15 16:04:53 2016 antoine GANNAT
*/

#ifndef MY_H_
# define MY_H_

# define READ_SIZE (1)

# include <stdarg.h>

int		my_putchar(char			c);
unsigned int	my_putstr_e(char		*str);
unsigned int	my_putstr(char 			*str);
int		my_getnbr(char 			*nbr);
unsigned int	my_strlen(char 			*str);
char		*my_strcat(char 		*dest,
			   char			*src);
char		*my_strcat_fusion(char 		*dest,
				  char 		*src);
char		*my_strcat_dyn(char 		*dest,
			       char 		*src);
char		*my_strcat_dyn_char(char 	*dest,
				    char 	src);
int		my_strcmp(char 			*s1,
			  char			*s2);
int		my_strncmp(char 		*str,
			   char			*search,
			   unsigned int 	nb);
char		*my_strcpy(char 		*dest,
			   char			*src);
char		*my_strncpy(char 		*dest,
			    char		*src,
			    int			len);
char		*my_strdup(char 		*str);
int		my_putnbr(int 			nbr);
char		*get_next_read(const int 	fd);
int		my_strstr(char 			*str,
			  char 			*end);
int		my_strstr_end(char		*str,
			      char		*end);
int		my_name_compare(char 		*la,
				char		*lb);
int		string(va_list 			ap);
int		binary(va_list 			ap);
int		charaff(va_list 		ap);
int		nbaff(va_list 			ap);
void		my_printf(char			*str, ...);
void		my_getstr(char			*key);

#endif /* MY_H_ */
