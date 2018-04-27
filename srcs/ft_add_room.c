/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_room.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:57:20 by srossi            #+#    #+#             */
/*   Updated: 2018/04/27 09:34:28 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static	int	ft_find_room(t_room *lst_room, t_room *new_room)
{
	while (lst_room && !(ft_strcmp(lst_room->name, new_room->name) == 0) &&
			!(lst_room->x == new_room->x && lst_room->y == new_room->y))
		lst_room = lst_room->next;
	if (lst_room && ft_strcmp(lst_room->name, new_room->name) == 0)
		return (1);
	else if (lst_room && (lst_room->x == new_room->x && lst_room->y ==
				new_room->y))
		return (1);
	return (0);
}

static	int	ft_load_room(t_room *room, char *line, int room_id)
{
	int			i;
	int			nb_coord;
	long long	l;

	i = ft_strlen(line) - 1;
	room->nb_room = room_id;
	nb_coord = 0;
	while (nb_coord < 2)
	{
		while (ft_isdigit(line[i]))
			i--;
		if (line[i] == ' ' && nb_coord < 2 && (l = ft_atoi(&line[i])) >= 0 &&
				l < INT_MAX)
		{
			if (nb_coord == 0)
				room->y = l;
			else
				room->x = l;
			nb_coord++;
		}
		else
			return (ft_error("room_add"));
	/*	{
			ft_putendl("Error: can't add room");
			return (-1);
		}*/
		i--;
	}
	room->name = ft_strnew(i + 1);
	ft_strncpy(room->name, line, i + 1);
	return (0);
}

static	int	ft_add_room(t_game *game, t_room *new_room)
{
	if (ft_find_room(game->rooms, new_room) == 1)
		return (1);
	new_room->next = game->rooms;
	game->rooms = new_room;
	return (0);
}

int			ft_create_room(t_game *game, char *line)
{
	t_room *room;

	if (!(room = (t_room *)malloc(sizeof(t_room))))
		return (-1);
	ft_bzero(room, sizeof(t_room));
	game->nb_rooms++;
	if (ft_load_room(room, line, game->nb_rooms) == -1)
		return (-1);
	if (ft_add_room(game, room) == 1)
		ft_memdel((void **)(&room));
	return (0);
}
