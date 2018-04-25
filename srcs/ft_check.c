#include "lem_in.h"

int ft_is_start(char *line)
{
	if (line[0] == '#' && line[1] == '#' && ft_strcmp(&line[2], "start") == 0)
		return (1);
	return (0);
}

int ft_is_end(char *line)
{
	if (line[0] == '#' && line[1] == '#' && ft_strcmp(&line[2], "end") == 0)
		return (1);
	return (0);
}

int	ft_is_com(char *line)
{
	if (line[0] == '#' && !ft_is_start(line) && !ft_is_end(line))
		return (1);
	return (0);
}

int ft_is_tube(char *line)
{
	int i;
	int nb_minus;

	i = 0;
	nb_minus = 0;
	while (line[i])
	{
		if (line[i] == '-')
			nb_minus++;
		i++;
	}
	if (line[i] == '\0' && nb_minus == 1 && i > 2)
		return (1);
	return (0);
}

int ft_is_room(char *line)
{
	int i;
	int nb_coord;
	int nb_char;

	i = ft_strlen(line) - 1;
	nb_coord = 0;
	nb_char = 0;
	if (!ft_isdigit(line[i]))
		return (0);
	while (i >= 0)
	{
		while (ft_isdigit(line[i]) && nb_coord < 2)
			i--;
		if (line[i] == ' ' && nb_coord < 2)
			nb_coord++;
		else if ((ft_isalpha(line[i]) || ft_isdigit(line[i]) || line[i] == ' ')
		&& nb_coord == 2)
			nb_char++;
		i--;
	}
	if (nb_coord == 2 && nb_char > 0)
		return (1);
	return (0);
}
