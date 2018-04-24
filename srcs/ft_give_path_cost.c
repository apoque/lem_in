/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_give_path_cost.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:04:38 by gvannest          #+#    #+#             */
/*   Updated: 2018/04/24 16:30:37 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include <stdio.h>

int			**ft_ordonate_set(int **set, int n)
{
	int	i;
	int	j;
	int	*tmp;

	i = 0;
	j = 1;
	while (n > j)
	{
		if (ft_size_path(set[i]) > ft_size_path(set[j]))
		{
			tmp = set[i];
			set[i] = set[j];
			set[j] = tmp;
			i = 0;
			j = 1;
		}
		else
		{
			i++;
			j++;
		}
	}
	return (set);
}

void			ft_change_set(t_game *game, int **set, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		game->set.set[i] = set[i];
		i++;
	}
	while (i < game->n)
	{
		game->set.set[i] = NULL;
		i++;
	}
}

void			ft_give_path_cost(t_game *game, int **set, int n, int ants)
{
	int	k;
	int	paths_used;
	int	cost;

	set = ft_ordonate_set(set, n);
	paths_used = 0;
	k = 0;
	cost = ft_size_path(set[paths_used]) - 2;

	/*int i;
	i = 0;
	while (set[0][i] != -3)
	{
		printf("%i-", set[0][i]);
		i++;
	}
	printf("\n");*/

	while (ants > 0)
	{
		if (paths_used < n - 1)
		{
			while (cost < (ft_size_path(set[paths_used + 1]) - 2) && ants > 0)
			{
				cost++;
				ants = ants - paths_used - 1;
			}
			paths_used++;
		}
		else
		{
			ants = ants - paths_used - 1;
			cost++;
		}
	}
	if (cost < game->set.cost || game->set.cost == 0)
	{
		game->set.cost = cost;
		game->set.found = 1;
		game->set.nb_path = n;
		ft_change_set(game, set, n);
	}
	printf("This set will cost %i\n", cost);
}
