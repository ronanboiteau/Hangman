/*
** puts.c for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 19:04:48 2016 Ronan Boiteau
** Last update Tue Jun 14 22:20:38 2016 Ronan Boiteau
*/

#include <unistd.h>

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putchar(char letter)
{
  (void)write(1, &letter, 1);
}

void	my_putstr(const char *str)
{
  (void)write(1, str, my_strlen(str));
}

void	my_putchar_fd(int fd, char letter)
{
  (void)write(fd, &letter, 1);
}

void	my_putstr_fd(int fd, const char *str)
{
  (void)write(fd, str, my_strlen(str));
}
