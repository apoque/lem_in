/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/30 10:59:57 by srossi            #+#    #+#             */
/*   Updated: 2018/04/30 16:27:28 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	ft_free_listways(t_ways *list_ways)
{
	t_ways *ptr_way;

	if (list_ways == 0)
		return (0);
	while (list_ways)
	{
		ptr_way = list_ways;
		free(list_ways->sh_path);
		free(list_ways->way);
		list_ways = list_ways->next;
		free(ptr_way);
	}
	return (0);
}

int	ft_free_ants(t_ant *aant)
{
	t_ant *ant1;
	t_ant *ant2;

	ant1 = aant;
	if (aant == 0)
		return (0);
	while (ant1)
	{
		ant2 = ant1;
		ant1 = ant1->next;
		//	free(ant2->path);
		//	ft_memdel((void *)ant2);
		//	free(ant2);
	}
	return (0);
}

int	ft_free_rooms(t_room *aroom)
{
	t_room *room1;
	t_room *room2;

	room1 = aroom;
	if (aroom == 0)
		return (0);
	while (room1)
	{
		room2 = room1;
		room1 = room1->next;
		ft_strdel(&room2->name);
		ft_free_links(room2->next_map);
		free(room2);
	}
	return (0);
}

int	ft_free_links(t_link *alink)
{
	t_link *link1;
	t_link *link2;

	link1 = alink;
	if (alink == 0)
		return (0);
	while (link1)
	{
		link2 = link1;
		link1 = link1->next;
		free(link2);
	}
	return (0);
}

int	ft_free_lines(t_line *aline)
{
	t_line *line1;
	t_line *line2;

	line1 = aline;
	if (aline == 0)
		return (0);
	while (line1)
	{
		line2 = line1;
		line1 = line1->next;
		ft_strdel(&line2->str);
		free(line2);
	}
	return (0);
}

int	ft_free_game(t_game *game, t_ways *list_ways)
{
	//	ft_free_ants(game->ants);
	ft_free_lines(game->lines);
	ft_free_rooms(game->rooms);
	ft_free_listways(list_ways);
	return (0);
}
