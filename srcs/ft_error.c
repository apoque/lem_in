/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:18:35 by srossi            #+#    #+#             */
/*   Updated: 2018/04/26 19:18:04 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	ft_error(int type_error)
{
	if (type_error == 1)
		ft_putendl("Error #1");
	else if (type_error == 2)
		ft_putendl("Error #2");
	return (-1);
}

int	ft_last_check(t_game *game)
{
	if (!(game->f_start == 2 && game->f_end == 2))
	{
		if (game->f_start < 2)
			ft_putendl("Pas de Start");
		else
			ft_putendl("Pas de End");
		return (-2);
	}
	else if (game->room_start->next_map == NULL ||
			game->room_end->next_map == NULL)
	{
		if (game->room_start->next_map == NULL)
			ft_putendl("Pas de liaisons sur Start");
		else
			ft_putendl("Pas de liaisons sur End");
		return (-2);
	}
	return (0);
}
