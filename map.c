# include "includes/filler.h"

t_map	*init_map(int rows, int cols)
{
	t_map *map;
	int	i;

	map = (t_map*)malloc(sizeof(t_map));
	map->rows = rows;
	map->cols = cols;
	map->token = (char**)malloc(sizeof(char*) * rows);
	i = 0;
	while (i < rows)
	{
		map->token[i] = (char*)malloc(cols);
		i++;
	}
	return (map);
}

char	*get_map_line(char *line)
{
	while (*line != ' ')
		line++;
	line++;
	return (line);
}

t_map	*get_map(char **line)
{
	t_map	*map;
	int	i;

	map = init_map(get_token_lines(*line), get_token_cols(*line));
	get_next_line(0, line);
	i = 0;
	while(i < map->rows)
	{
		get_next_line(0, line);
		map->token[i] = ft_strcpy(map->token[i], get_map_line(*line));
		i++;
	}
	return (map);
}

void	print_map(t_map *m)
{
	t_token	*t;

	t = (t_token*)m;
	print_token(t);
}
