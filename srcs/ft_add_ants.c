/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:21:28 by srossi            #+#    #+#             */
/*   Updated: 2018/04/26 18:36:33 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static	int	ft_create_ant(t_game *game)
{
	t_ant *new_ant;

	if (!(new_ant = (t_ant*)malloc(sizeof(t_ant))))
		return (-1);
	ft_bzero(new_ant, sizeof(t_ant));
	new_ant->next = game->ants;
	game->ants = new_ant;
	return (0);
}

int			ft_add_lants(t_game *game)
{
	int i;

	i = 0;
	while (i < game->nb_ants)
	{
		ft_create_ant(game);
		game->ants->nb = i;
		i++;
	}
	return (0);
}
