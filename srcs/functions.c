/*
** functions.c for funct in /home/jamet_a/colle/CPE_colle_semaine8/CPE_colle_semaine8/srcs
** 
** Made by jamet alexis
** Login   <jamet_a@epitech.net>
** 
** Started on  Tue Jun 14 18:53:49 2016 jamet alexis
** Last update Tue Jun 14 18:59:00 2016 jamet alexis
*/

void	my_putchar(const char c)
{
  write(1, &c, 1);
}

void	my_putstr(const char *str)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar(str[i++]);
}

void	my_putchar_fd(const char c, int fd)
{
  write(fd, &c, 1);
}

void	my_putstr_fd(const char *str, int fd)
{
  int	i;

  i = 0;
  while (str[i])
    my_putchar_fd(str[i++]);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
