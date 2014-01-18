# include "./includes/filler.h"

t_token	*new_token(int rows, int cols)
{
	t_token *t;
	int	i;

	t = (t_token*)malloc(sizeof(t_token));
	t->rows = rows;
	t->cols = cols;
	t->token = (char**)malloc(sizeof(char*) * rows);
	i = 0;
	while (i < rows)
	{
		t->token[i] = (char*)malloc(cols);
		i++;
	}
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
	token->token[i] = NULL;
	return (token);
}

void	print_token(t_token *t)
{
	int	i;
	i = 0;
	while(i < t->rows)
		ft_putendl(t->token[i]);
}
