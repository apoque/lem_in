/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:47:49 by gvannest          #+#    #+#             */
/*   Updated: 2018/04/24 13:55:58 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		ft_new_shortpath(t_game *game, t_pile *current, t_paths **list_paths)
{
	t_paths *new_path;
	int		k;

	k = 0;
	while (current->path[k])
		k++;
	if(!(new_path = (t_paths*)malloc(sizeof(*new_path))))
		return (-1);
	ft_bzero(new_path, sizeof(*new_path));
	if(!(new_path->sh_path = (t_room**)malloc(sizeof(t_room*) * (k + 2))))
		return (-1);
	ft_bzero(new_path->sh_path, sizeof(t_room*) * (k + 2));
	ft_memcpy(new_path->sh_path, current->path, sizeof(t_room*) * (k + 2));
	if(!(new_path->sh_path_nb = (int*)malloc(sizeof(int) * (k + 3))))
		return (-1);
	ft_bzero(new_path->sh_path_nb, sizeof(int) * (k + 3));
	k = 0;
	while (new_path->sh_path[k])
	{
		new_path->sh_path_nb[k] = new_path->sh_path[k]->nb_room;
		k++;
	}
	new_path->sh_path_nb[k] = -3;
	if (*list_paths != 0)
		new_path->next = *list_paths;
	*list_paths = new_path;
	return (0);
}

