/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:56:30 by srossi            #+#    #+#             */
/*   Updated: 2018/04/18 18:54:16 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	ft_add_link(t_game *game, t_link *new_link)
{
	new_link->next = game->room_start->next_map;
	ft_putstr("Lien avec ");
//	ft_putstr((new_link->room)->name);
	ft_putendl("cree.");
	game->room_start->next_map = new_link;
	return (0);
}
/*
static int	ft_add_bounds(t_game *game, char *room1, char *room2, t_link *link1, t_link *link2)
{
//	t_link *link1;
//	t_link *link2;
	t_room *ptr;
	int i;

	ptr = game->room_start;

	i = 0;
	while (i < 2)
	{
		while(ft_strcmp(ptr->name, room1) != 0 && ft_strcmp(ptr->name, room2) != 0)
			ptr = ptr->next_room_list;
		if (ft_strcmp(ptr->name, room1) == 0)
		{
			ft_putstr(ptr->name);
			ft_putendl(" found !");
			//ft_add_link(game, link2);
			link2->next = ptr->next_map;
			ptr->next_map = link2;
			ft_putnbr(ptr->nb_bounds);
			ptr->nb_bounds++;
			ft_putchar('-');
			ft_putnbr(ptr->nb_bounds);
			ft_putchar('\n');
		}
		else if (ft_strcmp(ptr->name, room2) == 0)
		{
			ft_putstr(ptr->name);
			ft_putendl(" found !");
			ft_add_link(game, link1);
			ft_putnbr(ptr->nb_bounds);
			ptr->nb_bounds++;
			ft_putchar('-');
			ft_putnbr(ptr->nb_bounds);
			ft_putchar('\n');
		}
		ptr = ptr->next_room_list;
		i++;
	}
	return (0);
}
*/
static int	ft_add_bounds(t_game *game, char *room1, char *room2, t_link *link1, t_link *link2)
{
	t_room *ptr;
	int i;

	ptr = game->room_start;
	i = 0;
	while(ptr)
	{
		ft_putstr(ptr->name);
		ft_putchar('\n');
		ptr = ptr->next_room_list;
	}
	ft_putendl("--------------------------------");
	ptr = game->room_start;
	while (i < 2)
	{
		while(ft_strcmp(ptr->name, room1) != 0 && ft_strcmp(ptr->name, room2) != 0)
		{
			ft_putstr(ptr->name);
			ft_putchar('\n');
			ptr = ptr->next_room_list;
		}
		if (ft_strcmp(ptr->name, room1) == 0)
		{
			ft_putstr(ptr->name);
			link2->room = ptr;
			ft_putchar('#');
			while(ft_strcmp(ptr->name, room2) != 0)
			{
				ft_putstr(ptr->name);
				ft_putchar('$');
				ptr = ptr->next_room_list;
				ft_putchar('&');
			}
			ft_putchar('#');
			link1->room = ptr;
			link2->next = ptr->next_map;
			ptr->next_map = link2;
			ptr = game->room_start;
			while(ft_strcmp(ptr->name, room1) != 0)
				ptr = ptr->next_room_list;
			link1->next = ptr->next_map;
			ptr->next_map = link1;
		}
		else if (ft_strcmp(ptr->name, room2) == 0)
		{
			link1->room = ptr;
			while(ft_strcmp(ptr->name, room1) != 0)
				ptr = ptr->next_room_list;
			link2->room = ptr;
			link2->next = ptr->next_map;
			ptr->next_map = link1;
			ptr = game->room_start;
			while(ft_strcmp(ptr->name, room2) != 0)
				ptr = ptr->next_room_list;
			link2->next = ptr->next_map;
			ptr->next_map = link2;
		}
		ptr = ptr->next_room_list;
		i++;
	}
	return (0);
}


int	ft_create_bounds(t_game *game, char *line)
{
	char *room1;
	char *room2;
	char **tab_split;
	t_link *link1;
	t_link *link2;

	tab_split = ft_strsplit(line, '-');
	room1 = tab_split[0];
	room2 = tab_split[1];
	link1 = (t_link *)malloc(sizeof(t_link));
	link2 = (t_link *)malloc(sizeof(t_link));
	ft_bzero(link1, sizeof(t_link));
	ft_bzero(link2, sizeof(t_link));
	ft_putchar('\n');
	ft_putstr("room 1 : ");
	ft_putendl(room1);
	ft_putstr("room 2 : ");
	ft_putendl(room2);
	ft_add_bounds(game, room1, room2, link1, link2);
	return (0);
}
