# include "./includes/filler.h"

int	main()
{
	char	*line;
	t_token	*token;
	t_map	*map;
	char	*play;

	play = "3 2\n";
	while(get_next_line(0, &line) > 0)
	{
		if (strstart(line, "Plateau"))
		{
			map = get_map(&line);
			print_map(map);
			ft_putendl_fd("map printed",2 );
		}
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
