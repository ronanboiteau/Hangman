/*
** tools.h for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 19:05:39 2016 Ronan Boiteau
** Last update Tue Jun 14 20:55:29 2016 Ronan Boiteau
*/

#ifndef TOOLS_H_
# define TOOLS_H_

char	*get_next_line(const int fd);
void	my_putchar(const char letter);
void	my_putchar_fd(int fd, const char letter);
void	my_putnbr(int nb);
void	my_putstr(const char *str);
void	my_putstr_fd(int fd, const char *str);
char	*my_realloc(char *old_str, const size_t size);
int	my_strlen(const char *str);

#endif /* !TOOLS_H_ */
