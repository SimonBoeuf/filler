#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <errno.h>
# include <string.h>

# define BUFF_SIZE 64

# define P1 'o'
# define P2 'x'
# define MAXINT 2147483647

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

typedef struct	s_cell
{
	int	x;
	int	y;
	int	live;
	struct s_cell	*next;
}		t_cell;

typedef struct	s_island
{
	t_cell	*first;
	int	nbcells;
}		t_island;

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
int	abs(int n);
int	min(int n1, int n2);

char	get_player(char *line);
char	get_opponent_player(void);

t_play	*new_play(int x, int y);
t_play	*get_next_play(t_map *map, t_token *token);
int	get_play_val(t_token *token, t_play *play, t_map *map);
int	play(t_map *map, t_token *token, int x, int y);

t_cell	*new_cell(int x, int y);
int	get_cell_val(t_cell *c, t_token *t, t_play *p, t_map *m);
void	get_cells_lives(t_island *i, t_map *m);
void	remove_cell(t_cell *c, t_island *i);

t_island	*get_island(char *line, int x);
t_island	*get_op_island(char *line, int x);
t_island	*init_island(void);
void		add_cell(t_island *island, int x, int y);
void		print_island(t_island *i);

int	is_player(char c);
int	is_opponent_player(char c);
int	is_shape(char c);
#endif
