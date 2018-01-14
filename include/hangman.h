#ifndef HANGMAN_H_
# define HANGMAN_H_

# define NB_TRY (10)
# define CHAR_HIDDEN '*'

int	run_game(char *word, char *word_disp, int try);
char	*select_word(const char *file);
char	*get_file(const char *filepath);

#endif /* !HANGMAN_H_ */
