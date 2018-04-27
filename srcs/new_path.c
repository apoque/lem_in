/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:47:49 by gvannest          #+#    #+#             */
/*   Updated: 2018/04/27 09:32:51 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_new_shortpath(t_game *game, t_pile *current, t_ways **list_ways)
{
	t_ways *new_path;
	int		k;

	k = 0;
	while (current->path[k])
		k++;
	if(!(new_path = ft_memalloc(sizeof(*new_path))))
		return (-1);
	if(!(new_path->sh_path = ft_memalloc(sizeof(t_room*) * (k + 2))))
		return (-1);
	ft_memcpy(new_path->sh_path, current->path, sizeof(t_room*) * (k + 2));
	if(!(new_path->way = ft_memalloc(sizeof(int) * (k + 3))))
		return (-1);
	k = 0;
	while (new_path->sh_path[k])
	{
		new_path->way[k] = new_path->sh_path[k]->nb_room;
		printf("%s %d\n", new_path->sh_path[k]->name, new_path->sh_path[k]->nb_room);
		k++;
	}
	new_path->way[k] = -3;
	if (*list_ways != 0)
		new_path->next = *list_ways;
	*list_ways = new_path;
	//printf("A\n");
	ft_compatibilities(game, list_ways, game->n);
	//printf("B\n");
	return (0);
}

