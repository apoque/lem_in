/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:18:35 by srossi            #+#    #+#             */
/*   Updated: 2018/04/27 11:12:36 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	ft_error(char *reason)
{
	t_error *tab_error;
	int i;
	
	i = 0;
	if (!(tab_error = (t_error*)malloc(sizeof(t_error))))
		return (-1);
	while (ft_strcmp(reason, tab_error[i].reason) != 0)
		i++;
	ft_putendl(tab_error[i].str_print);
	return (tab_error[i].type_error);
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
