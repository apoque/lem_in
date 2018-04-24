/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/04/24 15:31:24 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

static int ft_display_lst(t_game *game)
{
	t_room *alst;

	alst = game->rooms;
	if (alst == NULL)
		return (0);
	while (alst != NULL)
	{
		ft_putstr("Room : ");
		ft_putendl((*alst).name);
		ft_putstr("Liaisons : ");
		while (alst->next_map)
		{
			ft_putstr(alst->next_map->room->name);
			ft_putstr(" ; ");
			alst->next_map = alst->next_map->next;
		}
		ft_putchar('\n');
		alst = alst->next;
	}
	return (0);
}

int main(int argc, const char *argv[])
{
	int fd;
	char *line;
	int i; // nb lignes utiliser structure apres 
	t_game game;
	t_ways	*list_paths;
	int j;

	ft_bzero(&game, sizeof(t_game));

	t_set	set;
	int		k;
	int		m;

	k = 0;
	game.n = 3;
	set.set = (int **)malloc(sizeof(int *) * game.n);
	while (k < game.n)
	{
		m = 0;
		set.set[k] = (int *)malloc(sizeof(int) * (game.nb_rooms + 1));
		while (m <= game.nb_rooms)
		{
			set.set[k][m] = -3;
			m++;
		}
		k++;
	}
	set.nb_path = 0;
	set.cost = 0;

	game.set = set;
	game.set.found = 0;



	i = 0;
	j = 0;
	list_paths = 0;
	if (argc != 2)
	{
		ft_putendl("usage: ./lem_in source_file");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) != -1)
	{
		while (get_next_line(fd, &line))
		{
			if (i == 0)
			{
				ft_putstr("nb ants : ");
				ft_putendl(line);
				game.f_section = 1;
			}
			else
			{
				if (ft_parse(line, &game) == -2)
					return (0);
			}
			i++;
		}
	}
	else
	{
		ft_putendl("Error: wrong source_file");
		return (-1);
	}
	if (close(fd == -1))
	{
		ft_putendl("Error: couldn't close source_file");
		return (-1);
	}
	ft_putendl("--------------------------");
/*	printf("%s\n", game.rooms->name);
	printf("%p\n", game.rooms->next_map);
	ft_display_lst(&game);
	printf("%s\n", game.rooms->name);
	printf("%p\n", game.rooms->next_map);
*/

	list_paths = ft_short_path(&game);
	while (list_paths)
	{
		j = 0;
		while (list_paths->sh_path[j])
		{
			ft_printf("%s %d - ", list_paths->sh_path[j]->name, list_paths->way[j]);
			j++;
		}
		ft_printf("\n");
		list_paths = list_paths->next;
	}

	return (0);
}
