/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   short_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/20 09:31:56 by gvannest          #+#    #+#             */
/*   Updated: 2018/04/27 17:07:05 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		ft_min_path(t_game *game)
{
	int		nb_start;
	int		nb_end;
	t_link	*link;

	nb_start = 0;
	nb_end = 0;
	link = game->room_start->next_map;
	while (link != 0)
	{
		nb_start++;
		link = link->next;
	}
	link = game->room_end->next_map;
	while (link != 0)
	{
		nb_end++;
		link = link->next;
	}
	game->n = ((game->nb_ants < nb_end) ? game->nb_ants : nb_end);
	game->n = ((nb_start < game->n) ? nb_start : game->n);
	ft_init_set(game);
}

static int		ft_add_link(t_game *game, t_pile *current, t_link *link, int k)
{
	t_pile	*new;
	int		i;

	i = 0;
	game->limit++;
	if (game->limit % 1000 == 0)
		printf("limit = %i\n", game->limit);
	if (!(new = (t_pile*)malloc(sizeof(t_pile))))
		return (0);
	ft_bzero(new, sizeof(t_pile));
	if (!(new->path = (t_room**)malloc(sizeof(t_room*) * (k + 2))))
		return (0);
	ft_bzero(new->path, sizeof(t_room*) * (k + 2));
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
	t_link	*link;
	int		i;
	char	c;

	i = 0;
	while (current->path[i] != 0)
		i++;
	if (current->path[i - 1] == game->room_end)
		return (0);
	link = current->path[i - 1]->next_map;
	while (link)
	{
		i = 0;
		c = 0;
		while (current->path[i] != 0)
			(current->path[i++] == link->room ? c++ : 1);
		(c == 0 ? ft_add_link(game, current, link, i) : 0);
		link = link->next;
	}
	return (1);
}

static t_pile	*ft_init_pile(t_pile *current, t_game *game)
{
	if (!(current = (t_pile*)malloc(sizeof(t_pile))))
		return (0);
	ft_bzero(current, sizeof(t_pile));
	if (!(current->path = (t_room**)malloc(sizeof(t_room*) * 2)))
		return (0);
	ft_bzero(current->path, sizeof(t_room*) * 2);
	current->path[0] = game->room_start;
	return (current);
}

t_ways			*ft_short_path(t_game *game)
{
	t_ways	*list_ways;
	t_pile	*current;
	t_pile	*ptr;

	list_ways = 0;
	current = 0;
	current = ft_init_pile(current, game);
	ptr = current;
	ft_min_path(game);
	while (current && (game->k <= game->nb_ants || game->set.found == 0))
	{
		if (!ft_add_blocks(game, current))
			ft_new_shortpath(game, current, &list_ways);
		ptr = current;
		current = current->next;
		free(ptr->path);
		free(ptr);
	}
	ft_select_path(game);
	ft_display_res(game);
	return (list_ways);
}
