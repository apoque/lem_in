/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:14:30 by srossi            #+#    #+#             */
/*   Updated: 2018/05/01 12:15:24 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_add_line(char *line, t_game *game)
{
	t_line *new_line;
	t_line *tmp;

	tmp = game->lines;
	if (line == NULL || game == NULL || !(new_line = malloc(sizeof(t_line))))
		return (-1);
	ft_bzero(new_line, sizeof(t_line));
	if (game->lines == NULL)
	{
		game->lines = new_line;
		new_line->str = ft_strdup(line);
	}
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		new_line->str = ft_strdup(line);
		tmp->next = new_line;
	}
	return (0);
}
