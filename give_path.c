/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:04:38 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/06 17:01:37 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int			ft_size_path(int *path)
{
	int	i;

	i = 0;
	while (path[i] != -3)
		i++;
	return (i);
}

void		ft_give_path(t_map *game, int path, int *ant, int wave)
{
	int	i;
	int size_path;

	i = 0;
	size_path = ft_size_path(game->paths[path]);
	game->ants[*ant].wave = wave;
	game->ants[*ant].path = (int *)malloc(sizeof(int) * (size_path + 1));
	while (i < size_path)
	{
		game->ants[*ant].path[i] = game->paths[path][i];
		i++;
	}
	game->ants[*ant].path[i] = -3;
	*ant = *ant + 1;;
}

int			ft_check_path(t_map *game, int *path, int ant, int wave)
{
	int	i;
	int	k;
	int	trafic;

	i = 0;
	trafic = 0;
	while (i < ant && trafic == 0)
	{
		k = 0;
		while ((path[k] != -2 || game->ants[i].path[k + wave - game->ants[i].wave] != -2) && trafic == 0)
		{
			if (path[k]  == game->ants[i].path[k + wave - game->ants[i].wave] && path[k] != -1 && path[k] != -2)
				trafic = 1;
			k++;
		}
		i++;
	}
	if (trafic == 0)
		return (1);
	else
		return (0);
}

void		ft_select_path(t_map *game)
{
	int	wave;
	int	ant;
	int	path;

	wave = 0;
	ant = 0;
	while (ant < game->nb_ants)
	{
		path = 0;
		while (path < game->nb_paths)
		{
			if (ft_check_path(game, game->paths[path], ant, wave) == 1)
				ft_give_path(game, path, &ant, wave);
			path++;
		}
		wave++;
	}
}
