/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:21:28 by srossi            #+#    #+#             */
/*   Updated: 2018/05/01 16:22:55 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int	ft_create_ant(t_game *game, t_ant *ant)
{
	int		i;

	i = 0;
	if (!(ant->path = (int *)malloc(sizeof(int) * (game->nb_rooms + 1))))
		return (-1);
	while (i < game->nb_rooms + 1)
	{
		ant->path[i] = -3;
		i++;
	}
	ant->nb_moves = 0;
	ant->wave = 0;
//	ant->next = game->ants;
	return (0);
}

int			ft_add_lants(t_game *game)
{
	int i;

	i = 0;
	if (!(game->ants = (t_ant *)malloc(sizeof(t_ant) * game->nb_ants)))
		return (-1);
	while (i < game->nb_ants)
	{
		if (ft_create_ant(game, &(game->ants[i])) == -1)
			return (ft_error("noadd_ants"));
		game->ants[i].nb = i;
		i++;
	}
	return (0);
}
