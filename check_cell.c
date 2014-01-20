# include "./includes/filler.h"

int	is_player(char c)
{
	char	player;

	player = get_player(NULL);
	return (c == player || c == player - 32);
}

int	is_opponent_player(char c)
{
	char	opponent_player;

	opponent_player = get_player(NULL) == P1 ? P2 : P1;
	return (c == opponent_player || c == opponent_player - 32);
}

int	is_shape(char c)
{
	return (c == '*');
}
