/*
** tools.h for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 19:05:39 2016 Ronan Boiteau
** Last update Tue Jun 14 21:32:06 2016 jamet alexis
*/

#ifndef TOOLS_H_
# define TOOLS_H_

void	my_putchar(const char letter);
void	my_putchar_fd(int fd, const char letter);
void	my_putnbr(int nb);
void	my_putstr(const char *str);
void	my_putstr_fd(int fd, const char *str);
int	my_strlen(const char *str);
char	*get_next_line(const int fd);
char	*my_realloc(char *old_str, const size_t size);

#endif /* !TOOLS_H_ */
