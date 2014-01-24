#include "filler.h"

int				is_shape(char c)
{
	return (c == '*');
}

int				is_dot(char c)
{
	return (c == '.');
}

int				is_piece(char c)
{
	return (c == 'o' || c == 'O' || c == 'x' || c == 'X');
}