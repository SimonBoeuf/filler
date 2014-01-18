# include "./includes/filler.h"

t_token	*new_token(int rows, int cols)
{
	t_token *t;
	int	i;

	t = (t_token*)malloc(sizeof(t_token));
	t->rows = rows;
	t->cols = cols;
	t->token = (char**)malloc(sizeof(char*) * (rows + 1));
	i = 0;
	while (i < rows)
	{
		t->token[i] = (char*)malloc(cols);
		i++;
	}
	t->token[i] = NULL;
	return (t);
}

int	get_token_lines(char *str)
{
	while (*str != ' ')
		str++;
	str++;
	return (get_number(str));
}

int	get_token_cols(char *str)
{
	while (*str != ' ')
		str++;
	str++;
	while (*str != ' ')
		str++;
	str++;
		return (get_number(str));
}

t_token	*get_token(char **line)
{
	t_token *token;
	int	i;

	token = new_token(get_token_lines(*line), get_token_cols(*line));
	i = 0;
	while (i < token->rows)
	{
		get_next_line(0, line);
		token->token[i] = ft_strcpy(token->token[i], *line);
		i++;
	}
	return (token);
}

void	print_token(t_token *t)
{
	int	i;
	i = 0;
	ft_putstr_fd("rows : ", 2);
	ft_putnbr_fd(t->rows, 2);
	ft_putstr_fd("\ncols : ", 2);
	ft_putnbr_fd(t->cols, 2);
	ft_putstr_fd("\nToken :\n", 2);
	while(i < t->rows)
	{
		ft_putendl_fd(t->token[i],2);
		i++;
	}
}
