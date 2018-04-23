/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 09:31:56 by gvannest          #+#    #+#             */
/*   Updated: 2018/04/23 10:26:58 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_new_shortpath(t_game *game, t_pile *current, t_paths **list_paths)
{
	t_paths *new_path;
	t_paths *ptr;
	
	ptr = *list_paths;
	if(!(new_path = (t_paths*)malloc(sizeof(t_paths))))
		return (0);
	ft_bzero(new_path, sizeof(t_paths));
	if(!(new_path->sh_path = (t_room**)malloc(sizeof(t_room*) * game->nb_rooms + 1)))
		return (0);
	ft_bzero(new_path->sh_path, sizeof(t_room*) * (game->nb_rooms + 1));
	ft_memcpy(new_path->sh_path, current->path, game->nb_rooms + 1);
	if (ptr != 0)
		new_path->next = ptr;
	*list_paths = new_path;
}

static void		ft_add_link(t_game *game, t_pile *current, t_link *link)
{
	t_pile *new;
	int		i;

	i = 0;
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		return (0);
	ft_bzero(new, sizeof(t_pile));
	if (!(new->path = (t_room**)malloc(sizeof(t_room*) * (game->nb_rooms + 1))))
		return (0);
	ft_bzero(new->path, sizeof(t_room*) * (game->nb_rooms + 1));
	while (current->path[i] != 0)
	{
		new->path[i] = current->path[i];
		i++;
	}
	new->path[i] = link->room;
	new_path[i]->visited = 1;
	while (current->next != 0)
		current = ptr->next;
	current->next = new;
}

static int		ft_add_blocks(t_game *game, t_pile *current)
{
	t_link *link;
	int		i;

	i = 0;
	while (current->path[i] != 0)
		i++;
	if (current->path[i - 1] == game->room_end)
		return (0);
	link = current->path[i - 1]->next_map;
	while (link)
	{
		if (link->room->visited == 0)
		{
			ft_add_link(current, link);
			link = link->next_map;
		}
	}
	return (1);
}

static t_pile	*ft_init_pile(t_pile *current, t_game *game)
{
	if (!(current = (t_pile*)malloc(sizeof(t_pile))))
		return (0);
	ft_bzero(current,sizeof(t_pile));
	if (!(current->path = (t_room**)malloc(sizeof(t_room*))))
		return (0);
	current->path[0] = game->room_start;
	return (current);
}

t_paths		*ft_short_path(t_game *game)
{
	t_paths *list_paths;
	t_pile	*current;
	t_pile	*ptr;
	int		k;

	k = 0;
	ptr = 0;
	current = ft_init_pile(current, game);
	while (current && k < game->nb_ants)
	{
		if (!ft_add_blocks(current))
			ft_add_shortpath(t_pile *current, t_paths **list_paths);
		ptr = current;
		current = current->next;
		free((ptr->path);
		free(ptr);
	}
	return (list_paths);
}
