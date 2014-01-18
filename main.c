# include "./includes/filler.h"

int	strstart(char *str, char *start)
{
	int	i;

	i = 0;
	while (start[i] && str[i])
	{
		if (start[i] != str[i])
			return (0);
		i++;
	}
	if (start[i])
		return (0);
	else
		return (1);
}

int	get_number(char *str)
{
	int	rslt;

	rslt = 0;
	while (*str > 47 && *str < 58)
	{
		rslt *= 10;
		rslt += (*str - '0');
		str++;
	}
	return (rslt);
}


int	main()
{
	char	*line;
	t_token	*token;
	char	*play;

	play = "3 2\n";
	while(get_next_line(0, &line) > 0)
	{
		if (strstart(line, "Piece"))
		{
			token = get_token(&line);
			print_token(token);
			ft_putendl_fd("token printed", 2);
		}
		if (token != NULL)
		{
			ft_putstr(play);
			token = NULL;
		}
	}
	return (0);
}
