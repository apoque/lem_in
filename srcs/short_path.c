/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 09:31:56 by gvannest          #+#    #+#             */
/*   Updated: 2018/04/23 17:51:08 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		ft_new_shortpath(t_game *game, t_pile *current, t_paths **list_paths)
{
	t_paths *new_path;
	
	if(!(new_path = (t_paths*)malloc(sizeof(*new_path))))
		return (0);
	ft_bzero(new_path, sizeof(*new_path));
	if(!(new_path->sh_path = (t_room**)malloc(sizeof(t_room*) * (game->nb_rooms))))
		return (0);
	ft_bzero(new_path->sh_path, sizeof(t_room*) * (game->nb_rooms));
	ft_memcpy(new_path->sh_path, current->path, sizeof(t_room*) * (game->nb_rooms));
	if (*list_paths != 0)
		new_path->next = *list_paths;
	*list_paths = new_path;
	return (1);
}

static int		ft_add_link(t_game *game, t_pile *current, t_link *link)
{
	t_pile *new;
	int		i;

	i = 0;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		return (0);
	ft_bzero(new, sizeof(t_pile));
	if (!(new->path = (t_room**)malloc(sizeof(t_room*) * (game->nb_rooms))))
		return (0);
	ft_bzero(new->path, sizeof(t_room*) * (game->nb_rooms));
	while (current->path[i] != 0)
	{
		new->path[i] = current->path[i];
		i++;
	}
	new->path[i] = link->room;
	while (current->next != 0)
		current = current->next;
	current->next = new;
	return (1);
}

static int		ft_add_blocks(t_game *game, t_pile *current)
{
	t_link *link;
	int		i;
	char	c;

	i = 0;
	while (current->path[i] != 0)
		i++;
	if (i > 0 && current->path[i - 1] == game->room_end)
		return (0);
	link = current->path[i - 1]->next_map;
	while (link)
	{
		i = 0;
		c = 0;
		while (current->path[i] != 0)
			(current->path[i++] == link->room ? c++ : 1);
		(c == 0 ? ft_add_link(game, current, link) : 0);
		link = link->next;
	}
	return (1);
}

static t_pile	*ft_init_pile(t_pile *current, t_game *game)
{
	if (!(current = (t_pile*)malloc(sizeof(t_pile))))
		return (0);
	ft_bzero(current,sizeof(t_pile));
	if (!(current->path = (t_room**)malloc(sizeof(t_room*) * 2)))
		return (0);
	ft_bzero(current->path, sizeof(t_room*) * 2);
	current->path[0] = game->room_start;
	return (current);
}

t_paths		*ft_short_path(t_game *game)
{
	t_paths *list_paths;
	t_pile	*current;
	t_pile	*ptr;

	ptr = 0;
	list_paths = 0;
	current = ft_init_pile(current, game);
	while (current)
	{
		if (!ft_add_blocks(game, current))
			ft_new_shortpath(game, current, &list_paths);
		ptr = current;
		current = current->next;
		free(ptr->path);
		free(ptr);
	}
	return (list_paths);
}
