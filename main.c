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
	t_room *room1;
	t_room *room2;
	t_room *room3;
	t_room *room4;
	t_room *room5;
	t_room *room6;
	t_room *room7;
	t_room *room8;
	t_room *room9;
	t_room *room10;


	room10 = (t_room *)malloc(sizeof(t_room) * 1);
	room10->name = "7";
	room10->nb_room = 7;
	room10->next = NULL;

	room9 = (t_room *)malloc(sizeof(t_room) * 1);
	room9->name = "6";
	room9->nb_room = 6;
	room9->next = room10;

	room8 = (t_room *)malloc(sizeof(t_room) * 1);
	room8->name = "5";
	room8->nb_room = 5;
	room8->next = room9;

	room7 = (t_room *)malloc(sizeof(t_room) * 1);
	room7->name = "4";
	room7->nb_room = 4;
	room7->next = room8;

	room6 = (t_room *)malloc(sizeof(t_room) * 1);
	room6->name = "3";
	room6->nb_room = 3;
	room6->next = room7;

	room5 = (t_room *)malloc(sizeof(t_room) * 1);
	room5->name = "2";
	room5->nb_room = 2;
	room5->next = room6;

	room4 = (t_room *)malloc(sizeof(t_room) * 1);
	room4->name = "end";
	room4->nb_room = -2;
	room4->next = room5;

	room3 = (t_room *)malloc(sizeof(t_room) * 1);
	room3->name = "1";
	room3->nb_room = 1;
	room3->next = room4;

	room2 = (t_room *)malloc(sizeof(t_room) * 1);
	room2->name = "0";
	room2->nb_room = 0;
	room2->next = room3;

	room1 = (t_room *)malloc(sizeof(t_room) * 1);
	room1->name = "start";
	room1->nb_room = -1;
	room1->next = room2;


	game.nb_paths = 3;
	game.nb_ants = 14;
	game.nb_rooms = 10;
	game.paths = (int **)malloc(sizeof(int *) * 3);
	game.paths[0] = (int *)malloc(sizeof(int) * 4);
	game.paths[0][0] = -1;
	game.paths[0][1] = 0;
	game.paths[0][2] = -2;
	game.paths[0][3] = -3;
	game.paths[1] = (int *)malloc(sizeof(int) * 6);
	game.paths[1][0] = -1;
	game.paths[1][1] = 1;
	game.paths[1][2] = 2;
	game.paths[1][3] = 3;
	game.paths[1][4] = -2;
	game.paths[1][5] = -3;
	game.paths[2] = (int *)malloc(sizeof(int) * 7);
	game.paths[2][0] = -1;
	game.paths[2][1] = 4;
	game.paths[2][2] = 5;
	game.paths[2][3] = 6;
	game.paths[2][4] = 7;
	game.paths[2][5] = -2;
	game.paths[2][6] = -3;



	game.ants = (t_ant *)malloc(sizeof(t_ant) * 20);
	game.ants[0].nb = 0;
	game.ants[0].nb_moves = 0;
	game.ants[1].nb = 1;
	game.ants[1].nb_moves = 0;
	game.ants[2].nb = 2;
	game.ants[2].nb_moves = 0;
	game.ants[3].nb = 3;
	game.ants[3].nb_moves = 0;
	game.ants[4].nb = 4;
	game.ants[4].nb_moves = 0;
	game.ants[5].nb = 5;
	game.ants[5].nb_moves = 0;
	game.ants[6].nb = 6;
	game.ants[6].nb_moves = 0;
	game.ants[7].nb = 7;
	game.ants[7].nb_moves = 0;
	game.ants[8].nb = 8;
	game.ants[8].nb_moves = 0;
	game.ants[9].nb = 9;
	game.ants[9].nb_moves = 0;
	game.ants[10].nb = 10;
	game.ants[10].nb_moves = 0;
	game.ants[11].nb = 11;
	game.ants[11].nb_moves = 0;
	game.ants[12].nb = 12;
	game.ants[12].nb_moves = 0;
	game.ants[13].nb = 13;
	game.ants[13].nb_moves = 0;
	game.ants[14].nb = 14;
	game.ants[14].nb_moves = 0;
	game.ants[15].nb = 15;
	game.ants[15].nb_moves = 0;
	game.ants[16].nb = 16;
	game.ants[16].nb_moves = 0;
	game.ants[17].nb = 17;
	game.ants[17].nb_moves = 0;
	game.ants[18].nb = 18;
	game.ants[18].nb_moves = 0;
	game.ants[19].nb = 19;
	game.ants[19].nb_moves = 0;


	game.rooms = &room1;

	t_ways	**way_start;
	t_ways	*way1;
	t_ways	*way2;
	t_ways	*way3;
	t_ways	*way4;
	t_ways	*way5;
	int		i;

	i = 0;
	way_start = &way1;

	way5 = (t_ways *)malloc(sizeof(t_ways));
	way5->nb = 5;
	way5->way = (int *)malloc(sizeof(int) * (game.nb_rooms + 1));
	while (i <= game.nb_rooms)
	{
		way5->way[i] = -3;
		i++;
	}
	i = 0;
	way5->way[0] = -1;
	way5->way[1] = 3;
	way5->way[2] = 11;
	way5->way[3] = 0;
	way5->way[4] = -2;
	way5->next = NULL;

	way4 = (t_ways *)malloc(sizeof(t_ways));
	way4->nb = 4;
	way4->way = (int *)malloc(sizeof(int) * (game.nb_rooms + 1));
	while (i <= game.nb_rooms)
	{
		way4->way[i] = -3;
		i++;
	}
	i = 0;
	way4->way[0] = -1;
	way4->way[1] = 1;
	way4->way[2] = 4;
	way4->way[3] = -2;
	way4->next = way5;

	way3 = (t_ways *)malloc(sizeof(t_ways));
	way3->nb = 3;
	way3->way = (int *)malloc(sizeof(int) * (game.nb_rooms + 1));
	while (i <= game.nb_rooms)
	{
		way3->way[i] = -3;
		i++;
	}
	i = 0;
	way3->way[0] = -1;
	way3->way[1] = 5;
	way3->way[2] = 2;
	way3->way[3] = -2;
	way3->next = way4;

	way2 = (t_ways *)malloc(sizeof(t_ways));
	way2->nb = 2;
	way2->way = (int *)malloc(sizeof(int) * (game.nb_rooms + 1));
	while (i <= game.nb_rooms)
	{
		way2->way[i] = -3;
		i++;
	}
	i = 0;
	way2->way[0] = -1;
	way2->way[1] = 2;
	way2->way[2] = 9;
	way2->way[3] = -2;
	way2->next = way3;

	way1 = (t_ways *)malloc(sizeof(t_ways));
	way1->nb = 1;
	way1->way = (int *)malloc(sizeof(int) * (game.nb_rooms + 1));
	while (i <= game.nb_rooms)
	{
		way1->way[i] = -3;
		i++;
	}
	i = 0;
	way1->way[0] = -1;
	way1->way[1] = 1;
	way1->way[2] = 3;
	way1->way[3] = 8;
	way1->way[4] = -2;
	way1->next = way2;


	ft_compatibilities(&game, way_start, 3);
	printf("\n\n\n");
	ft_compatibilities(&game, way_start, 2);

	//ft_select_path(&game);
	//ft_display_res(&game);
}
