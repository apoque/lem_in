/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/04/24 15:08:18 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#include <stdio.h>

static int ft_display_lst(t_room *room)
{
	t_room *alst;
	t_link *link;

	alst = room;
	if (alst == NULL)
		return (0);
	while (alst != NULL)
	{
		ft_putstr("Room (");
		ft_putnbr(alst->nb_room);
		ft_putstr(") : ");
		ft_putendl(alst->name);
		ft_putstr("Liaisons : ");
		link = alst->next_map;
		while (link)
		{
			ft_putstr(link->room->name);
			ft_putstr(" ; ");
			link = link->next;
		}
		ft_putchar('\n');
		alst = alst->next;
	}
	return (0);
}

static int ft_add_line(char *line, t_game *game)
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

static int ft_display_lines(t_game *game)
{
	t_line *ptr;

	ptr = game->lines;
	while (ptr)
	{
		ft_putstr(ptr->str);
		ft_putstr(".\n");
		ptr = ptr->next;
	}
	return (0);
}

static	int	ft_create_ant(t_game *game)
{
	t_ant *new_ant;

	if (!(new_ant = (t_ant*)malloc(sizeof(t_ant))))
		return (-1);
	ft_bzero(new_ant, sizeof(t_ant));
	new_ant->next = game->ants;
	game->ants = new_ant;
	return (0);
}

static	int	ft_add_lants(t_game *game)
{
	int i;

	i = 0;
	while (i < game->nb_ants)
	{
		ft_create_ant(game);
		game->ants->nb = i;
		i++;
	}
	return (0);
}

int main()
{
	char *line;
	int i; // nb lignes utiliser structure apres 
	t_game game;

	ft_bzero(&game, sizeof(t_game));
	i = 0;
		while (get_next_line(0, &line))
		{
			if (i == 0)
			{
			//	ft_putstr("nb ants : ");
				game.nb_ants = ft_atoi(line);
				ft_add_lants(&game);
			//	ft_putnbr(game.nb_ants);
			//	ft_putstr("\n");
				game.f_section = 1;
			}
			else
			{
				if (ft_parse(line, &game) == -1)
					return (-1);
			}
			i++;
			ft_add_line(line, &game);
			ft_strdel(&line);
		}
	ft_putendl("--------------------------");
//	ft_display_lst(game.rooms);
	ft_putendl("--------------------------");
//	ft_display_lines(&game);
	ft_putendl("--------------------------");
	return (0);
}
