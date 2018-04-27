/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:34:49 by srossi            #+#    #+#             */
/*   Updated: 2018/04/27 10:51:23 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_is_start(char *line)
{
	if (line[0] == '#' && line[1] == '#' && ft_strcmp(&line[2], "start") == 0)
		return (1);
	return (0);
}

int	ft_is_end(char *line)
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

int	ft_is_tube(char *line)
{
	int i;
	int nb_minus;

//	ft_putendl("TUBE");
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

int	ft_is_room(char *line)
{
	int i;

//	ft_putendl("ROOM !");
	i = ft_strlen(line) - 1;
	if (!ft_isdigit(line[i]))
		return (0);
	while (i > 0 && ft_isdigit(line[i]))
		i--;
	if (i > 0 && line[i] == ' ')
		i--;
	else
	{
		if (line[i] == '-')
			ft_putendl("Coord neg");
		return (0);
	}
	while (i > 0 && ft_isdigit(line[i]))
		i--;
	if (i > 0 && line[i] == ' ')
		i--;
	else
	{
		if (line[i] == '-')
			ft_putendl("Coord neg");
		return (0);
	}
	if (line[0] == 'L')
	{
		ft_putendl("Room starts with an 'L'");
		return (0);
	}
	if (i >= 0)
		return (1);
	return (0);
}
