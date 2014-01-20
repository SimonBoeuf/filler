# include "./includes/filler.h"

int	main()
{
	char	*line;
	t_token	*token;
	t_map	*map;
	t_play	*play;
	char	player;
	//t_island *island;
	//t_island *opisland;

	token = NULL;
	while(get_next_line(0, &line) > 0)
	{
		if (strstart(line, "$$$"))
		{
			player = get_player(line);
			player = player;
			//ft_putstr_fd("player : ", 2);
			//ft_putchar_fd(player, 2);
			//ft_putendl_fd("", 2);
		}
		if (strstart(line, "Plateau"))
		{
			map = get_map(&line);
			//island = get_island(NULL, 0);
			//opisland = get_op_island(NULL, 0);
			//print_map(map);
			//print_island(island);
			//print_island(opisland);
			//ft_putendl_fd("map printed",2 );
		}
		if (strstart(line, "Piece"))
		{
			token = get_token(&line);
			//print_token(token);
			//ft_putendl_fd("token printed", 2);
		}
		if (token != NULL)
		{
			play = get_next_play(map, token);
			ft_putstr(play->string);
			token = NULL;
		}
	}
	return (0);
}
