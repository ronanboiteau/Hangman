#ifndef TOOLS_H_
# define TOOLS_H_

void	my_putchar(char letter);
void	my_putchar_fd(int fd, char letter);
void	my_putnbr(int nb);
void	my_putstr(const char *str);
void	my_putstr_fd(int fd, const char *str);
int	my_strlen(const char *str);
char	*get_next_line(int fd);
char	*my_realloc(char *old_str, size_t size);

#endif /* !TOOLS_H_ */
