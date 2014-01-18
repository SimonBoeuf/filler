# include "./includes/filler.h"

void	ft_putstr(char *str)
{
	write(1, str, 3);
	write(2, str, 3);
}

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

int	get_token_lines(char *str)
{
	while (*str != ' ')
		str++;
	str++;
	return (*str - 48);
}

int	main()
{
	char	*line;
	char	*token;
	int	nblines;

	nblines = -1;
	token = "3 2\n";
	while(get_next_line(0, &line) > 0 && nblines)
	{
		if(strstart(line, "Piece") && nblines)
		{
			nblines = get_token_lines(line);
		}
		nblines --;
	}
	ft_putstr(token);
	return (0);
}
