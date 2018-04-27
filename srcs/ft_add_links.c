/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_links.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 16:56:30 by srossi            #+#    #+#             */
/*   Updated: 2018/04/27 12:14:49 by gvannest         ###   ########.fr       */
/*   Updated: 2018/04/27 10:19:26 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int	ft_find_link(t_link *link, char *name)
{
	while (link && (ft_strcmp(link->room->name, name) != 0))
		link = link->next;
	if (link && ft_strcmp(link->room->name, name) == 0)
		return (1);
	return (0);
}

static	int	ft_add_link(t_room *ptr, char *room1, char *room2, t_link *link1, t_link *link2)
{
	t_room *ptr_cpy;

	ptr_cpy = ptr;
	if (ft_find_link(ptr_cpy->next_map, room1))
		return (1);
	link1->room = ptr;
	while (ptr_cpy->next && ft_strcmp(ptr_cpy->name, room1) != 0)
		ptr_cpy = ptr_cpy->next;
	if (ft_strcmp(ptr_cpy->name, room1) != 0)
	{
		ft_putendl("Liaison error, la salle 1 nexiste pass");
		return (-1);
	}
	link2->room = ptr_cpy;
	link1->next = ptr_cpy->next_map;
	ptr_cpy->next_map = link1;
	ptr_cpy = ptr;
	while (ptr_cpy->next && ft_strcmp(ptr_cpy->name, room2) != 0)
		ptr_cpy = ptr_cpy->next;
	if (ft_strcmp(ptr_cpy->name, room2) != 0)
	{
		ft_putendl("Liaison error, la salle 2 nexiste pass");
		return (-1);
	}
	link2->next = ptr->next_map;
	ptr->next_map = link2;
	return (0);
}

static	int	ft_add_bounds(t_game *game, char *room1, char *room2, t_link *link1, t_link *link2)
{
	t_room *ptr;

	ptr = game->rooms;
	while (ptr && ft_strcmp(ptr->name, room1) != 0 &&
			ft_strcmp(ptr->name, room2) != 0)
		ptr = ptr->next;
	if (!ptr)
	{
		ft_putendl("salle non trouvee");
		return (-1);
	}
	if (ft_strcmp(ptr->name, room1) == 0)
		ft_add_link(ptr, room2, room1, link2, link1);
	else if (ft_strcmp(ptr->name, room2) == 0)
		ft_add_link(ptr, room1, room2, link1, link2);
	return (0);
}

int			ft_create_bounds(t_game *game, char *line)
{
	char	*room1;
	char	*room2;
	char	**tab_split;
	t_link	*link1;
	t_link	*link2;

	tab_split = ft_strsplit(line, '-');
	room1 = tab_split[0];
	room2 = tab_split[1];
	if (ft_strcmp(room1, room2) == 0)
	{
		ft_putendl("lien meme salle");
		return (-1);
	}
	link1 = (t_link *)malloc(sizeof(t_link));
	link2 = (t_link *)malloc(sizeof(t_link));
	ft_bzero(link1, sizeof(t_link));
	ft_bzero(link2, sizeof(t_link));
	if (ft_add_bounds(game, room1, room2, link1, link2) == -1)
	{
		ft_memdel((void *)link1);
		ft_memdel((void *)link2);
		ft_strdel(&room1);
		ft_strdel(&room2);
		return (-1);
	}
	ft_strdel(&room1);
	ft_strdel(&room2);
	return (0);
}
