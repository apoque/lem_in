/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/05/01 16:57:37 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_get_info(t_game *game)
{
	char	*line;
	int		i;

	i = 0;
	while (i == 0 && get_next_line(0, &line))
	{
		i = ft_parse(line, game);
		printf("LINE = %s\n", line);
		if (i == 0)
		{
			ft_add_line(line, game);
			((game->f_error == 0) ? game->f_error = 1 : 0);
			ft_strdel(&line);
		}
		else if (i == -2)
		{
			((game->f_error > 0) ? ft_strdel(&line) : 0);
			return (-2);
		}
	}
	if (ft_last_check(game) == -2)
	{
		((game->f_error > 0) ? free(line) : 0);
		return (-2);
	}
	((game->f_error > 0) ? ft_strdel(&line) : 0);
	return (0);
}

int	main(void)
{
	t_game	game;
	t_ways	*list_ways;

	list_ways = NULL;
	ft_bzero(&game, sizeof(t_game));
	if (ft_get_info(&game) == -2)
	{
		ft_free_game(&game, list_ways);
		while (1)
			;
		return (-1);
	}
	ft_display_lines(&game);
	if (!(list_ways = ft_short_path(&game)))
	{
		game.f_error = 4;
		ft_free_game(&game, list_ways);
		while (1)
			;
		return(-1);
	}
	game.f_error = 5;
	ft_select_path(&game);
	ft_display_res(&game);
	ft_free_game(&game, list_ways);
	while (1)
		;
	return (0);
}
