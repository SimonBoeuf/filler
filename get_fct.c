#include "filler.h"

static void			get_size(char *buff, t_board *board)
{
	while (*buff < '0' || *buff > '9')
		buff++;
	board->length = 0;
	while (*buff >= '0' && *buff <= '9')
	{
		board->length *= 10;
		board->length += *buff - '0';
		buff++;
	}
	buff++;
	board->width = 0;
	while (*buff >= '0' && *buff <= '9')
	{
		board->width *= 10;
		board->width += *buff - '0';
		buff++;
	}
}

static void			get_field(t_board *board)
{
	int			i;
	char		*buff;

	i = 0;
	while (i < board->length)
	{
		ft_gnl(0, &buff);
		while (!is_shape(*buff) && !is_dot(*buff) && !is_piece(*buff))
			buff++;
		board->field[i] = ft_strdup(buff);
		i++;
	}
}

t_board				*get_board()
{
	char		*buff;
	t_board		*board;

	board = (t_board *)malloc(sizeof(t_board));
	ft_gnl(0, &buff);
	get_size(buff, board);
	ft_gnl(0, &buff);
	board->field = (char **)malloc(sizeof(char *) * board->length);
	get_field(board);
	return (board);
}

t_piece				*get_piece()
{
	char		*buff;
	t_piece		*piece;

	piece = (t_piece *)malloc(sizeof(t_piece));
	ft_gnl(0, &buff);
	get_size(buff, piece);
	piece->field = (char **)malloc(sizeof(char *) * piece->length);
	get_field(piece);
	return (piece);
}