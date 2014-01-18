#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

# define BUFF_SIZE 64

typedef struct	s_token
{
	int	rows;
	int	cols;
	char	**token;
}		t_token;

int	get_next_line(int fd, char **line);
void	ft_putendl(char *str);
void	ft_putstr(char *s);
char	*ft_strnew(int n);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *s1, char *s2);

int	get_token_lines(char *str);
int	get_token_cols(char *str);
int	get_number(char *str);
t_token	*new_token(int	rows, int cols);
t_token	*get_token(char **line);
void	print_token(t_token *t);

#endif
