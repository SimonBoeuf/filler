# include "./includes/filler.h"

t_play	*new_play(int	x, int	y)
{
	char	*n1;
	char	*n2;
	t_play	*p;

	p = (t_play*)malloc(sizeof(t_play));
	p->x = x;
	p->y = y;
	p->val = 0;
	n1 = ft_itoa(y);
	n2 = ft_itoa(x);
	p->string = (char*)malloc(ft_strlen(n1) + ft_strlen(n2) + 3);
	ft_bzero(p->string, ft_strlen(n1) + ft_strlen(n2) + 3);
	p->string = ft_strcat(p->string, n1);
	p->string = ft_strcat(p->string, " ");
	p->string = ft_strcat(p->string, n2);
	p->string = ft_strcat(p->string, "\n");
	return (p);
}

t_play	*get_play(t_map *map, t_token *token)
{
	t_play	**plays;
	t_play	*bestplay;

	plays = get_plays(map, token);
	bestplay = get_best_play(plays);
	return (bestplay);
}

int	get_nb_plays(t_map *map, t_token *token)
{
	int	i;
	int	j;
	int	rslt;

	i = -token->rows + 1;
	rslt = 0;
	while (i < token->rows)
	{
		j = -token->cols + 1;
		while (j < map->cols)
		{
			if (i + token->rows < map->rows && j + token->cols < map->cols)
			{
				/*
				ft_putstr_fd("token->rows : ", 2);
				ft_putnbr_fd(token->rows, 2);
				ft_putstr_fd(" token->cols : ", 2);
				ft_putnbr_fd(token->cols, 2);
				ft_putstr_fd(" i : ", 2);
				ft_putnbr_fd(i, 2);
				ft_putstr_fd(" j", 2);
				ft_putnbr_fd(j, 2);
				ft_putendl_fd("", 2);
				if (play(map, token, i, j))
				*/
					rslt++;
			}
			j++;
		}
		i++;
	}
	return (rslt);
}

int	play(t_map *map, t_token *token, int x, int y)
{
	int	i;
	int	j;
	int	touch;
	int	xtoplay;
	int	ytoplay;

	touch = 0;
	i = 0;
	while (i < token->rows && touch < 2)
	{
		j = 0;
		while (j < token->cols && touch < 2)
		{
			if (i + x < 0)
				xtoplay = map->rows + i + x;
			else
				xtoplay = x + i;
			if (y + j < 0)
				ytoplay = map->cols + j + y;
			else
				ytoplay = y + j;
			/*
			ft_putstr_fd("xy : ", 2);
			ft_putnbr_fd(x, 2);
			ft_putstr_fd(":", 2);
			ft_putnbr_fd(y, 2);
			ft_putstr_fd(" ", 2);
			ft_putstr_fd("ij : ", 2);
			ft_putnbr_fd(i, 2);
			ft_putstr_fd(":", 2);
			ft_putnbr_fd(j, 2);
			ft_putstr_fd(" ", 2);
			ft_putstr_fd("xpyp : ", 2);
			ft_putnbr_fd(xtoplay, 2);
			ft_putstr_fd(":", 2);
			ft_putnbr_fd(ytoplay, 2);
			ft_putstr_fd(" touch : ", 2);
			ft_putnbr_fd(touch, 2);
			ft_putendl_fd("", 2);
			ft_putchar_fd(map->token[xtoplay][ytoplay], 2);
			ft_putchar_fd(token->token[i][j], 2);
			ft_putendl_fd("", 2);
			*/
			if (is_player(map->token[xtoplay][ytoplay]) && is_shape(token->token[i][j]))
				touch++;
			if (is_opponent_player(map->token[xtoplay][ytoplay]) && is_shape(token->token[i][j]))
				touch += 2;
			j++;
		}
		i++;
	}
	//ft_putendl_fd("Done", 2);
	return (touch == 1);
}

int	is_player(char c)
{
	char	player;

	player = get_player(NULL);
	return (c == player || c == player + 32);
}

int	is_opponent_player(char c)
{
	char	opponent_player;

	opponent_player = get_player(NULL) == P1 ? P2 : P1;
	return (c == opponent_player || c == opponent_player + 32);
}

int	is_shape(char c)
{
	return (c == '*');
}

t_play	**get_plays(t_map *map, t_token *token)
{
	int	nbplays;
	t_play	**plays;
	int	i;

	nbplays = get_nb_plays(map, token);
	plays = (t_play**)malloc(sizeof(t_play*) * (nbplays + 1));
	i = 0;
	while (i < nbplays)
	{
		plays[i] = get_next_play(map, token, i);
		i++;
	}
	plays[i] = NULL;
	return (plays);
}

t_play	*get_next_play(t_map *map, t_token *token, int lastplay)
{
	int	i;
	int	j;
	int	rslt;
	t_play	*nextplay;

	i = -token->rows + 1;
	rslt = 0;
	while (i < map->rows && rslt <= lastplay)
	{
		j = -token->cols + 1;
		while (j < map->cols && rslt <= lastplay)
		{
			if (i + token->rows < map->rows && j + token->cols < map->cols)
			{
				if (play(map, token, i, j))
					rslt++;
			}
			j++;
		}
		i++;
	}

	nextplay = new_play(j - 1, i - 1);
	nextplay->val = get_play_val(map, token, nextplay);
	return (nextplay);
}

int	get_play_val(t_map *map, t_token *token, t_play *play)
{
	map = map;
	token = token;
	play = play;
	return (1);
}

t_play	*get_best_play(t_play	**plays)
{
	int	i;
	t_play	*best;

	i = 0;
	best = plays[0];
	while (plays[i])
	{
		if (plays[i]->val > best->val)
			best = plays[i];
		i++;
	}
	return (best);
}
