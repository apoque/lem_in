/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/04/30 19:33:03 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"


/*static int ft_display_ants(t_game *game)
{
	t_ant *ptr;

	ptr = game->ants;
	while (ptr)
	{
		ft_putnbr(ptr->nb);
		ft_putchar('-');
		ptr = ptr->next;
	}
	return (0);
}*/

int	main(void)
{
	char	*line;
	t_game	game;
	int		i;
	t_ways	*list_ways;

	i = 0;
	ft_bzero(&game, sizeof(t_game));
	while (get_next_line(0, &line) && i == 0)
	{
		i = ft_parse(line, &game);
		if (i == 0)
		{
			ft_add_line(line, &game);
			if (line)
				ft_strdel(&line);
		}
		else if (i == -2)
			return (-1);
		else if (i == -1)
		{
			ft_display_lines(&game);
			return (-1);
		}
	}
	ft_display_lines(&game);
	if (ft_last_check(&game) == -2)
		return (-1);
	ft_putchar('\n');
	k = 0;
	game.n = 2;
	if (!(game.set.set = (int **)malloc(sizeof(int *) * game.n)))
		exit(EXIT_FAILURE);
	while (k < game.n)
	{
		m = 0;
		if (!(game.set.set[k] = (int *)malloc(sizeof(int) * (game.nb_rooms + 1))))
			exit(EXIT_FAILURE);
		while (m <= game.nb_rooms)
		{
			game.set.set[k][m] = -3;
			m++;
		}
		k++;
	}
	if (ft_last_check(&game) == -2)
		return (-1);
	game.set.nb_path = 0;
	game.set.cost = 0;
	game.set.found = 0;
	if(!(list_ways = ft_short_path(&game)))
		return (-1);
	ft_select_path(&game);
	ft_display_res(&game);
	ft_free_game(&game, list_ways);
//	ft_display_ants(&game);
//	ft_free_lines(game.lines);
//	ft_free_rooms(game.rooms);
//	ft_free_ants(game.ants);
//	ft_free_game(&game);
	return (0);
}
