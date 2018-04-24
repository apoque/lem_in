/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:04:38 by gvannest          #+#    #+#             */
/*   Updated: 2018/04/24 18:12:43 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include <stdio.h>

int			ft_size_path(int *path)
{
	int	i;

	i = 0;
	while (path[i] != -3)
		i++;
	return (i);
}

void		ft_give_path(t_game *game, int path, int ant, int wave)
{
	int	i;
	int size_path;

	i = 0;
	size_path = ft_size_path(game->set.set[path]);
	game->ants[ant].wave = wave;
	if (size_path == 2)
		game->ants[ant].wave = 0;
	game->ants[ant].path = (int *)malloc(sizeof(int) * (size_path + 1));
	while (game->set.set[path][i] != -3)
	{
		game->ants[ant].path[i] = game->set.set[path][i];
		i++;
	}
	//printf("fourmi n*%i wave = %i\n", ant, game->ants[ant].wave);
	game->ants[ant].path[i] = -3;
}

int			ft_check_path(t_game *game, int *path, int ant, int wave)
{
	int	i;
	int	k;
	int	trafic;

	i = 0;
	trafic = 0;
	while (i < ant && trafic == 0)
	{
		k = 0;
		while (trafic == 0 && (k + wave - game->ants[i].wave) < ft_size_path(game->ants[i].path) && (path[k] != -2 && game->ants[i].path[k + wave - game->ants[i].wave] != -2))
		{
			if (path[k]  == game->ants[i].path[k + wave - game->ants[i].wave] && path[k] != -1 && path[k] != -2)
			{
				trafic = 1;
			}
			k++;
		}
		i++;
	}
	//printf("size_path = %i wave = %i & trafic = %i\n", ft_size_path(path), wave, trafic);
	if (trafic == 0)
		return (1);
	else
		return (0);
}

int			ft_is_best_path(t_game *game, int path, int ant)
{
	int	is_best;
	int	i;

	is_best = 1;
	i = 0;
	while (i < path && is_best == 1)
	{
		if (ft_size_path(game->set.set[path]) - ft_size_path(game->set.set[i]) >= game->nb_ants - ant)
			is_best = 0;
		i++;
	}
	if (is_best == 1)
		return (1);
	else
		return (0);
}

void		ft_select_path(t_game *game)
{
	int	wave;
	int	ant;
	int	path;

	wave = 0;
	ant = 0;
	while (ant < game->nb_ants)
	{
		path = 0;
		while (path < game->set.nb_path && ant < game->nb_ants)
		{
			if (ft_check_path(game, game->set.set[path], ant, wave) == 1 && ft_is_best_path(game, path, ant) == 1)
			{
				ft_give_path(game, path, ant, wave);
				ant++;
			}
			path++;
		}
		wave++;
	}
}
