# include "./includes/filler.h"

t_cell	*new_cell(int x, int y)
{
	t_cell	*c;

	c = (t_cell*)malloc(sizeof(t_cell));
	c->x = x;
	c->y = y;
	c->next = NULL;
	c->live = 0;
	return (c);
}

int	get_cell_val(t_cell *c, t_token *t, t_play *p, t_map *m)
{
	int	val;
	int	i;
	int	j;
	int	xtp;
	int	ytp;

	val = 0;
	i = 0;
	while (i < t->rows)
	{
		j = 0;
		while (j < t->cols)
		{
			if (is_shape(t->token[i][j]))
			{
				xtp = i + p->x < 0 ? m->rows + i + p->x : i + p->x;
				ytp = j + p->y < 0 ? m->cols + j + p->y : j + p->y;
				if (abs(xtp - c->x) - abs(ytp - c->y) == 1)
					return(-1);
				if (m->rows + m->cols - min(abs(xtp - c->x), abs(ytp - c->y)) > val)
						val = m->rows + m->cols - min(abs(xtp - c->x), abs(ytp - c->y));
			}
			j++;
		}
		i++;
	}
	return (val);
}

void	get_cells_lives(t_island *i, t_map *m)
{
	int	lives;
	t_cell *c;
	int	xtoplay;
	int	ytoplay;

	c = i->first;
	while (c != NULL)
	{
		lives = 0;
		xtoplay = c->x - 1 < 0 ? m->rows - 1: c->x - 1;
		ytoplay = c->y - 1 < 0 ? m->cols - 1: c->y - 1;
		if (m->token[xtoplay][ytoplay] == '.')
			lives++;
		xtoplay = c->x + 1 >= m->rows ? m->rows - 1: c->x + 1;
		ytoplay = c->y - 1 < 0 ? m->cols - 1 : c->y - 1;
		if (m->token[xtoplay][ytoplay] == '.')
			lives++;
		xtoplay = c->x - 1 < 0 ? m->rows - 1: c->x - 1;
		ytoplay = c->y - 1 >= m->cols ? m->cols - 1 : c->y + 1;
		if (m->token[xtoplay][ytoplay] == '.')
			lives++;
		xtoplay = c->x + 1 >= m->rows ? m->rows - 1: c->x + 1;
		ytoplay = c->y - 1 >= m->cols ? m->cols - 1 : c->y + 1;
		if (m->token[xtoplay][ytoplay] == '.')
			lives++;
		if (lives == 0)
			remove_cell(c, i);
		else
			c->live = lives;
		c = c->next;
	}
}

void	remove_cell(t_cell *c, t_island *i)
{
	t_cell *cursor;

	cursor = i->first;
	while (cursor != NULL)
	{
		if (cursor->next != NULL)
		{
			if (cursor->next->x == c->x && cursor->next->y == c->y)
			{
				cursor->next = cursor->next->next;
				break;
			}
		}
		cursor = cursor->next;
	}
}
