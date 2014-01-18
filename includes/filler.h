#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

# define BUFF_SIZE 64

# define P1 'O'
# define P2 'X'

typedef struct	s_token
{
	int	rows;
	int	cols;
	char	**token;
}		t_token;

typedef	t_token t_map;

int	get_next_line(int fd, char **line);

void	ft_putendl(char *str);
void	ft_putendl_fd(char *str, int fd);
void	ft_putstr(char *s);
void	ft_putstr_fd(char *s, int fd);
char	*ft_strnew(int n);
char	*ft_strdup(char *s);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strcpy(char *s1, char *s2);
void	ft_putnbr_fd(int n, int fd);

t_map	*init_map(int rows, int cols);
char	*get_map_line(char *line);
t_map	*get_map(char **line);
void	print_map(t_map *m);

int	get_token_lines(char *str);
int	get_token_cols(char *str);
t_token	*new_token(int	rows, int cols);
t_token	*get_token(char **line);
void	print_token(t_token *t);

int	strstart(char *string, char *start);
int	get_number(char *str);

#endif
