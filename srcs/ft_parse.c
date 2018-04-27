/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:21:48 by srossi            #+#    #+#             */
/*   Updated: 2018/04/27 17:24:36 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_parse(char *line, t_game *game)
{
	if (ft_strlen(line) == 0)
		return (ft_error("empty_line"));
	if (ft_is_com(line))
		;
	else if (game->f_section == 0)
	{
		if (line[0] == '-')
			return (ft_error("wrong_ants"));
		game->nb_ants = ft_atoi(line);
		if (game->nb_ants < 1)
			return (ft_error("wrong_ants"));
		game->f_section = 1;
	}
	else if (ft_is_start(line) && (game->flag == 0 || game->flag == 1))
	{
		game->flag = 1;
		if (game->f_start > 0)
			return (ft_error("many_starts"));
		game->f_start++;
	}
	else if (ft_is_end(line) && (game->flag == 0 || game->flag == 2))
	{
		game->flag = 2;
		if (game->f_end > 0)
			return (ft_error("many_ends"));
		game->f_end++;
	}
	else if (ft_is_tube(line) && game->f_start == 2 && game->f_end == 2)
	{
		if (ft_create_bounds(game, line) != 0)
			return (ft_error("link_format"));
		game->f_section = 2;
	}
	else if (ft_is_tube(line) && !(game->f_start == 2 && game->f_end == 2))
		return (-2);
	else if (ft_is_room(line) && (game->f_section < 2))
	{
		if (ft_create_room(game, line) == -1)
			return (-1);
		if (game->f_end == 1)
		{
			game->room_end = game->rooms;
			game->room_end->nb_room = -2;
			game->f_end = 2;
		}
		else if (game->f_start == 1 && game->f_section < 2)
		{
			game->room_start = game->rooms;
			game->room_start->nb_room = -1;
			game->f_start = 2;
		}
		game->flag = 0;
	}
	else
		return (ft_error("line_format"));
	return (0);
}
