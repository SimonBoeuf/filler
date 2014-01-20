# include "./includes/filler.h"

int	strstart(char *str, char *start)
{
	int	i;

	i = 0;
	while (start[i] && str[i])
	{
		if (start[i] != str[i])
			return (0);
		i++;
	}
	if (start[i])
		return (0);
	else
		return (1);
}

int	get_number(char *str)
{
	int	rslt;

	rslt = 0;
	while (*str > 47 && *str < 58)
	{
		rslt *= 10;
		rslt += (*str - '0');
		str++;
	}
	return (rslt);
}


int	abs(int n)
{
	return (n < 0 ? -n : n);
}

int	min(int n1, int n2)
{
	return (n1 > n2 ? n2 : n1);
}
