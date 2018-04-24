/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:21:48 by srossi            #+#    #+#             */
/*   Updated: 2018/04/24 18:53:17 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int ft_is_start(char *line)
{
	if (line[0] == '#' && line[1] == '#' && ft_strcmp(&line[2], "start") == 0)
		return (1);
	//set_error si error
	return (0);
}

int ft_is_end(char *line)
{
	if (line[0] == '#' && line[1] == '#' && ft_strcmp(&line[2], "end") == 0)
		return (1);
	//set_error si error
	return (0);
}

int	ft_is_com(char *line)
{
	if (line[0] == '#' && !ft_is_start(line) && !ft_is_end(line)) //line[1] != '#')
		return (1);
	//set_error si error
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
	//set_error si error
	return (0);
}

static int ft_isspace(char c)
{
	if (c <= 32)
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
	while (i >= 0)
	{
		while (ft_isdigit(line[i]) && nb_coord < 2)
			i--;
		if (line[i] == ' ' && nb_coord < 2)
			nb_coord++;
		else if ((ft_isalpha(line[i]) || ft_isdigit(line[i]) || ft_isspace(line[i])) && nb_coord == 2)
			nb_char++;
		i--;
	}
	if (nb_coord == 2 && nb_char > 0)
		return (1);
	ft_putnbr(nb_coord);
	ft_putchar('-');
	ft_putnbr(nb_char);
	ft_putchar('\n');
	//set_error si error
	return (0);
}

static int ft_display_lst(t_room *alst)
{
	if (alst == NULL)
		return (0);
	while (alst != NULL)
	{
		ft_putendl((*alst).name);
		alst = alst->next;
	}
	return (0);
}

int	ft_parse(char *line, t_game *game)
{
	ft_putstr("Line : ");
	ft_putendl(line);
	if (game->f_section < 1)
	{
		ft_putendl("Probleme section");
		return (-1);
	}
	if (ft_is_com(line))
		ft_putstr("Comm : ");
	else if (ft_is_start(line))
	{
		if (game->f_start > 0)
		{
			ft_putendl("Deux salles 'start' !");
			return (-1);
		}
		game->f_start++;
//		ft_putstr("Start: ");
	}
	else if (ft_is_end(line))
	{
		if (game->f_end > 0)
		{
			ft_putendl("Deux salles 'end' !");
			return (-1);
		}
		game->f_end++;
//		ft_putstr("End  : ");
	}
	else if (ft_is_room(line) && (game->f_section == 1 || game->f_section == 2 || game->f_section == 3))
	{
//		ft_putstr("Room: ");
		ft_create_room(game, line);
		if (game->f_end == 1 && game->f_start == 1 && game->f_section < 3) // derniere salle ajoutee est end : on change de section et on conserve adresse de end
		{
			game->room_end = game->rooms;
			game->room_end->nb_room = -2;
			game->f_section = 3;
		}
		else if (game->f_start == 1 && game->f_end == 0 && game->f_section == 1) // derniere salle ajoutee est start : on change de section et on conserve adresse de end
		{
			game->room_start = game->rooms;
			game->f_section = 2;
			game->room_start->nb_room = -1;
			game->f_section = 2;
		}
	}
	else if (ft_is_tube(line) && game->f_section == 3)
	{
		ft_create_bounds(game, line);
//		ft_putstr("Tube: ");
	}
	else
	{
		if (!ft_is_room(line))
		{
			ft_putendl("FORMAT ERROR ROOM");
			ft_putnbr(game->f_section);
		}
		return (-1);
	}
//	ft_putendl(line);
	return (0);
}
