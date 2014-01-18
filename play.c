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
	map = map;
	token = token;
	return (1);
}

t_play	**get_plays(t_map *map, t_token *token)
{
	int	nbplays;
	t_play	**plays;
	int	i;

	nbplays = get_nb_plays(map, token);
	plays = (t_play**)malloc(sizeof(t_play*));
	i = 0;
	while (i < nbplays)
	{
		plays[i] = get_next_play(map, token, i);
		i++;
	}
	return (plays);
}

t_play	*get_next_play(t_map *map, t_token *token, int lastplay)
{
	t_play	*play;

	play = new_play(2, 3);
	lastplay = lastplay;
	play->val = get_play_val(map, token, play);
	return (play);
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
