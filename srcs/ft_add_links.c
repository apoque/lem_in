/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:56:30 by srossi            #+#    #+#             */
/*   Updated: 2018/04/24 17:08:27 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

static	int	ft_find_link(t_link *link, char *name)
{
	while (link && (ft_strcmp(link->room->name, name) != 0))
		link = link->next;
	if (link && ft_strcmp(link->room->name, name) == 0)
	{
		ft_putendl("lien deja existant");
		return (1);
	}
//	ft_putstr("OK\n");
	return (0);
}

static int	ft_add_link(t_room *ptr, char *room1, char *room2, t_link *link1, t_link *link2)
{
	t_room *ptr_cpy;

	ptr_cpy = ptr;
	if (ft_find_link(ptr_cpy->next_map, room1))
		return (1);
/*
	ft_putstr("1ere salle : ");
	ft_putendl(ptr_cpy->name);
	
*/	link1->room = ptr;
/*	
	ft_putendl("Lien 1 cree.");

	
*/	
	printf("Le ptr_cpy name vaut : %s\n", ptr_cpy->name);
	printf("room1 vaut : %s\n", room1);
	while(ptr_cpy->next && ft_strcmp(ptr_cpy->name, room1) != 0)
		ptr_cpy = ptr_cpy->next;

	
/*	ft_putstr("2eme salle : ");
	ft_putendl(ptr_cpy->name);
	
*/	link2->room = ptr_cpy;
/*	
	ft_putendl("Lien 2 cree.");
*/	
	link1->next = ptr_cpy->next_map;
	ptr_cpy->next_map = link1;
/*	
	ft_putstr("Lien 1 : ");
	ft_putstr(ptr_cpy->name);
	ft_putstr(" - ");
	ft_putstr(link2->room->name);
	ft_putendl(" ajoute.");
*/	
//	ptr_cpy = ptr;
/*	
	ft_putstr("Retour ptr a la salle ");
	ft_putendl(ptr_cpy->name);
*///	while(ft_strcmp(ptr_cpy->name, room2) != 0)
//		ptr_cpy = ptr_cpy->next;
	
	link2->next = ptr->next_map;
	ptr->next_map = link2;
	
/*	ft_putstr("Lien 2 : ");
	ft_putstr(ptr_cpy->name);
	ft_putstr(" - ");
	ft_putstr(link1->room->name);
	ft_putendl(" ajoute.");
*/	return (0);
}

static int	ft_add_bounds(t_game *game, char *room1, char *room2, t_link *link1, t_link *link2)
{
	t_room *ptr;

	ptr = game->rooms;
	while(ft_strcmp(ptr->name, room1) != 0 && ft_strcmp(ptr->name, room2) != 0)
		ptr = ptr->next;
	if (ft_strcmp(ptr->name, room1) == 0 && ptr->name )
		ft_add_link(ptr, room2, room1, link2, link1);
	else if (ft_strcmp(ptr->name, room2) == 0)
		ft_add_link(ptr, room1, room2, link1, link2);
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
	if (ft_strcmp(room1, room2) == 0)
		return (-1);
	link1 = (t_link *)malloc(sizeof(t_link));
	link2 = (t_link *)malloc(sizeof(t_link));
	ft_bzero(link1, sizeof(t_link));
	ft_bzero(link2, sizeof(t_link));
/*	ft_putchar('\n');
	ft_putendl("--------------------------------");
	ft_putchar('\n');
	ft_putstr("room 1 : ");
	ft_putendl(room1);
	ft_putstr("room 2 : ");
	ft_putendl(room2);
*/	if (ft_add_bounds(game, room1, room2, link1, link2) == 1)
	{
		ft_memdel((void *)link1);
		ft_memdel((void *)link2);
	}
	ft_strdel(&room1);
	ft_strdel(&room2);
	return (0);
}
