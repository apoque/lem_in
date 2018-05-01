/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/05/01 10:06:13 by apoque           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_get_info(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	while (get_next_line(0, &line) && i == 0)
	{
		i = ft_parse(line, game);
		if (i == 0)
		{
			ft_add_line(line, game);
			if (line)
				ft_strdel(&line);
		}
		else if (i == -2)
			return (-1);
		else if (i == -1)
		{
			ft_display_lines(game);
			return (-1);
		}
	}
	ft_display_lines(game);
	if (ft_last_check(game) == -2)
		return (-1);
	return (1);
}

int	main(void)
{
	t_game	game;
	t_ways	*list_ways;

	ft_bzero(&game, sizeof(t_game));
	if (ft_get_info(&game) < 0)
		return (-1);
	if (!(list_ways = ft_short_path(&game)))
		return (-1);
	ft_select_path(&game);
	ft_display_res(&game);
	ft_free_game(&game, list_ways);
	return (0);
}
