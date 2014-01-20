# include "./includes/filler.h"

char	get_player(char *line)
{
	static char	player = 'Z';

	if (player == 'Z')
		player = line[10] == '1' ? P1 : P2;
	return (player);
}

char	get_opponent_player(void)
{
	char	op_player;
	if (get_player(NULL) == 'Z')
		return ('Z');
	else
		op_player = get_player(NULL) == P1 ? P2 : P1;
	return (op_player);
}
