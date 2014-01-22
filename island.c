# include "./includes/filler.h"

t_island	*get_island(char *line, int x)
{
	static t_island	*is = NULL;
	int	y;

	if (is == NULL)
		is = init_island();
	if (line != NULL)
	{
		while (*line != ' ')
			line++;
		line++;
		y = 0;
		while(line[y])
		{
			if (is_player(line[y]))
				add_cell(is, x, y);
			y++;
		}
	}
	return (is);
}

t_island	*get_op_island(char *line, int x)
{
	static t_island	*is = NULL;
	int	y;

	if (is == NULL)
		is = init_island();
	if (line != NULL)
	{
		while (*line != ' ')
			line++;
		line++;
		y = 0;
		while (line[y])
		{
			if (is_opponent_player(line[y]))
				add_cell(is, x, y);
			y++;
		}
	}
	return (is);
}

t_island	*init_island(void)
{
	t_island	*i;

	i = (t_island*)malloc(sizeof(t_island));
	i->first = NULL;
	i->nbcells = 0;
	return (i);
}

t_island	*getfakewalls(t_map *map)
{
	t_island	*is;
	int		i;

	is = init_island();
	i = 0;
	while(i < map->rows)
	{
		if (map->token[i][0] == '.')
			add_cell(is, i, 0);
		i++;
	}
	i = 0;
	while(i < map->cols)
	{
		if (map->token[0][i] == '.')
			add_cell(is, 0, i);
		i++;
	}
	return is;
}

void		add_cell(t_island *island, int x, int y)
{
	t_cell	*c;

	if (island->first == NULL)
	{
		c = new_cell(x, y);
		island->first = c;
	}
	else
	{
		c = island->first;
		while(c->next != NULL && (c->x != x || c->y != y))
			c = c->next;
		if (c->next == NULL)
			c->next = new_cell(x, y);
	}
}

void	print_island(t_island *i)
{
	t_cell	*c;

	c = i->first;
	while (c != NULL)
	{
		ft_putstr_fd("c->x : ", 2);
		ft_putnbr_fd(c->x, 2);
		ft_putendl_fd("", 2);
		ft_putstr_fd("c->y : ", 2);
		ft_putnbr_fd(c->y, 2);
		ft_putendl_fd("", 2);
		c = c->next;
	}
}
