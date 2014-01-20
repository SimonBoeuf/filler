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
			xtoplay = i + x < 0 ? map->rows + i + x : x + i;
			ytoplay = y + j < 0 ? map->cols + j + y : y + j;
			if (is_player(map->token[xtoplay][ytoplay]) && is_shape(token->token[i][j]))
				touch++;
			if (is_opponent_player(map->token[xtoplay][ytoplay]) && is_shape(token->token[i][j]))
				touch += 2;
			j++;
		}
		i++;
	}
	return (touch == 1);
}


t_play	*get_next_play(t_map *m, t_token *t)
{
	int	i;
	int	j;
	t_play	*np;
	t_play	*bp;

	bp = new_play(0, 0);
	i = -t->rows;
	while (i < m->rows)
	{
		j = -t->cols;
		while (j < m->cols)
		{
			if (i + t->rows < m->rows && j + t->cols < m->cols)
				if (play(m, t, i, j))
				{
					np = new_play(j, i);
					if ((np->val = get_play_val(t, np, m))
							> bp->val)
						bp = np;
				}
			j++;
		}
		i++;
	}
	return (bp);
}

int	get_play_val(t_token *token, t_play *play, t_map *map)
{
	int	val;
	int	tmpval;
	t_island	*op_i;
	t_cell		*cursor;

	op_i = get_op_island(NULL, 0);
	cursor = op_i->first;
	val = 1;
	while (cursor != NULL)
	{
		if ((tmpval = get_cell_val(cursor, token, play, map)) < 0)
			return (MAXINT);
		else
		val += tmpval;
		cursor = cursor->next;
	}
	return (val);
}
