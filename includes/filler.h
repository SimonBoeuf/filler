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

typedef struct	s_play
{
	int	x;
	int	y;
	int	val;
	char	*string;
}		t_play;

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
char	*ft_itoa(int n);
void	ft_bzero(char *s, int n);
int	ft_strlen(char *s);
char	*ft_strcat(char *s1, const char *s2);
void	ft_putchar_fd(char c, int fd);

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

t_play	*new_play(int x, int y);
t_play	*get_play(t_map *map, t_token *token);
t_play	**get_plays(t_map *map, t_token *token);
int	get_nb_plays(t_map *map, t_token *token);
t_play	*get_best_play(t_play **plays);
t_play	*get_next_play(t_map *map, t_token *token, int lastplay);
int	get_play_val(t_map *map, t_token *token, t_play *play);
int	play(t_map *map, t_token *token, int x, int y);
int	is_player(char c);
int	is_opponent_player(char c);
int	is_shape(char c);

#endif
