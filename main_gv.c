/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/04/23 17:48:19 by gvannest         ###   ########.fr       */
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
	t_paths		*list_paths;
	int j;

	ft_bzero(&game, sizeof(t_game));

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
				ft_parse(line, &game);
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
			ft_printf("%s - ", list_paths->sh_path[j]->name);
			j++;
		}
		ft_printf("\n");
		list_paths = list_paths->next;
	}

	return (0);
}
