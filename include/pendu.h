/*
** pendu.h for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 19:41:56 2016 Ronan Boiteau
** Last update Tue Jun 14 20:38:37 2016 Ronan Boiteau
*/

#ifndef PENDU_H_
# define PENDU_H_

# define NB_TRY (10)
# define CHAR_HIDDEN '*'

char	*get_file(const char *filepath);
void	run_game(char *word, int try);
char	*select_word(const char *file);

#endif /* !PENDU_H_ */
