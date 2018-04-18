/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:57:20 by srossi            #+#    #+#             */
/*   Updated: 2018/04/18 17:22:21 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_load_room(t_room *room, char *line, int room_id)
{
	int i;
	int nb_coord;

	i = ft_strlen(line) - 1;
	room->nb_room = room_id;
	nb_coord = 0;
	while (nb_coord < 2)
	{
		while (ft_isdigit(line[i]))
			i--;
		if (line[i] == ' ' && nb_coord < 2)
		{
			if (nb_coord == 0)
				room->y = ft_atoi(&line[i]);
			else
				room->x = ft_atoi(&line[i]);
			nb_coord++;
		}
		i--;
	}
	room->name = ft_strnew(i + 1);
	ft_strncpy(room->name, line, i + 1);
	return (0);
}

static int	ft_add_room(t_game *game, t_room *new_room)
{
	new_room->next_room_list = game->room_start;
	game->room_start = new_room;
	return (0);
}

int	ft_create_room(t_game *game, char *line)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	ft_bzero(room, sizeof(t_room));
	game->nb_rooms++;
	ft_load_room(room, line, game->nb_rooms);
	ft_add_room(game, room);
	return (0);
}
