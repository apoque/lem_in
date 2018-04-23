/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/04/23 11:57:19 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

static int ft_display_lst(t_room *alst)
{
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

	ft_bzero(&game, sizeof(t_game));

	i = 0;
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
	ft_display_lst(game.rooms);
	return (0);
}
