/*
** pendu.h for pendu in /home/boitea_r/CPE_colle_semaine8
** 
** Made by Ronan Boiteau
** Login   <boitea_r@epitech.net>
** 
** Started on  Tue Jun 14 19:41:56 2016 Ronan Boiteau
** Last update Tue Jun 14 21:31:49 2016 jamet alexis
*/

#ifndef PENDU_H_
# define PENDU_H_

# define NB_TRY (10)
# define CHAR_HIDDEN '*'

int	run_game(char *word, char *word_disp, int try);
char	*select_word(const char *file);
char	*get_file(const char *filepath);

#endif /* !PENDU_H_ */
