#include <unistd.h>

int	my_strlen(const char *str)
{
  int	idx;

  idx = 0;
  while (str[idx])
    idx++;
  return (idx);
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
