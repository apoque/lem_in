/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:04:38 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/06 17:01:37 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

int		main(void)
{
	t_game	game;



	game.nb_paths = 2;
	game.nb_ants = 5;
	game.nb_rooms = 4;
	game.paths = (int **)malloc(sizeof(int *) * 2);
	game.paths[0] = (int *)malloc(sizeof(int) * 4);
	game.paths[0][0] = -1;
	game.paths[0][1] = 0;
	game.paths[0][2] = -2;
	game.paths[0][3] = -3;
	game.paths[1] = (int *)malloc(sizeof(int) * 4);
	game.paths[1][0] = -1;
	game.paths[1][1] = 1;
	game.paths[1][2] = -2;
	game.paths[1][3] = -3;

	game.ants = (t_ant *)malloc(sizeof(t_ant) * 5);
	game.ants[0].nb = 0;
	game.ants[1].nb = 1;
	game.ants[2].nb = 2;
	game.ants[3].nb = 3;
	game.ants[4].nb = 4;
	game.ants[5].nb = 5;

	ft_select_path(&game);

	int		i;
	int		j;

	i = 0;
	while (i < game.nb_ants)
	{
		printf("\nANT n*%i\nwave = %i\npath =\n", i, game.ants[i].wave);
		j = 0;
		while (game.ants[i].path[j] != -3)
		{
			printf(" %i -", game.ants[i].path[j]);
			j++;
		}
		printf("\n");
		i++;
	}
	return (0);
}
