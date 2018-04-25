/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:21:48 by srossi            #+#    #+#             */
/*   Updated: 2018/04/24 17:53:49 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int	ft_parse(char *line, t_game *game)
{
/*	if (game->f_section < 1)
	{
		ft_putendl("Probleme section");
		return (-1);
	}
	*/
	if (ft_is_com(line))
		ft_putstr("Comm : ");
	else if (game->f_section == 0)
	{
		game->nb_ants = ft_atoi(line);
		if (game->nb_ants < 1)
				return (-1);
			ft_add_lants(game);
			game->f_section = 1;
	}
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
	else if (ft_is_room(line) && (game->f_section < 2))
	{
//		ft_putstr("Room: ");
		ft_create_room(game, line);
		if (game->f_end == 1) // derniere salle ajoutee est end : on change de section et on conserve adresse de end
		{
			game->room_end = game->rooms;
			game->room_end->nb_room = -2;
			game->f_end = 2;
		}
		else if (game->f_start == 1 && game->f_section < 2) // derniere salle ajoutee est start : on change de section et on conserve adresse de end
		{
			game->room_start = game->rooms;
			game->room_start->nb_room = -1;
			game->f_start = 2;
		}
	}
	else if (ft_is_tube(line) && game->f_start == 2 && game->f_end == 2)
	{
	//	ft_putstr("Tube: ");
		ft_create_bounds(game, line);
		game->f_section = 2;
	}
	else
	{
		if (!(game->f_start == 2 && game->f_end == 2))
		{
			ft_putendl("Pas de End ou pas de Start");
			return (-2);
		}
		else if (game->room_start->next_map == NULL || game->room_end->next_map == NULL) // si pas au moins une liaison sur start et une liaison sur end
		{
			ft_putendl("Pas de liaisons sur End ou pas de liaisons sur Start");
			return (-2);
		}
		ft_putendl("FORMAT ERROR ROOM");
		return (-1);
	}
	return (0);
}
