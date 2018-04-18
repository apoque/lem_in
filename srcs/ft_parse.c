/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:21:48 by srossi            #+#    #+#             */
/*   Updated: 2018/04/18 17:17:54 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

int	ft_is_com(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	//set_error si error
	return (0);
}

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

	i = ft_strlen(line);
	nb_coord = 0;
	nb_char = 0;
	while (i >= 0)
	{
		while (ft_isdigit(line[i]))
			i--;
		if (line[i] == ' ' && nb_coord < 2)
			nb_coord++;
		else if ((ft_isalpha(line[i]) || ft_isdigit(line[i]) || ft_isspace(line[i])) && nb_coord == 2)
			nb_char++;
		i--;
	}
	if (nb_coord == 2 && nb_char > 0)
		return (1);
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
		alst = alst->next_room_list;
	}
	return (0);
}

int	ft_parse(char *line, t_game *game)
{
	//	t_ant *l_ants;
	//	l_ants = NULL;
	//	ft_bzero(&l_ants, sizeof(l_ants));
//	t_room	*a_lst_room;
//	a_lst_room = NULL;
	//verifier a chqaue test si error > 0 si oui stop partsing et traite donnees
	if (ft_is_com(line))
		ft_putstr("Comm : ");
	else if (ft_is_start(line))
		ft_putstr("Start: ");
	else if (ft_is_end(line))
		ft_putstr("End  : ");
	else if (ft_is_room(line))
	{
		//si room n'existe pas deja :
		//creer room + assigner le nom et les coordonnees
		game->nb_rooms++;
		ft_putstr("Room: ");
		ft_create_room(game, line);
	}
	else if (ft_is_tube(line))
	{
		ft_create_bounds(game, line);
		ft_putstr("Tube: ");
	}
	else
	{
		ft_putendl("FORMAT ERROR");
		return (-1);
	}
	ft_putendl(line);
	return (0);
}
