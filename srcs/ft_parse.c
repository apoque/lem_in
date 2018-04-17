/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:21:48 by srossi            #+#    #+#             */
/*   Updated: 2018/04/17 18:29:01 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#include <stdio.h>

int	ft_is_com(char *line)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	//set_error si error
	return (0);
}

int ft_is_start(char *line)
{
	if (line[0] == '#' && line[1] == '#' && ft_strcmp(&line[2], "start") == 0)
		return (1);
	//set_error si error
	return (0);
}

int ft_is_end(char *line)
{
	if (line[0] == '#' && line[1] == '#' && ft_strcmp(&line[2], "end") == 0)
		return (1);
	//set_error si error
	return (0);
}

int ft_is_tube(char *line)
{
	int i;
	int nb_minus;

	i = 0;
	nb_minus = 0;
	while (line[i])
	{
		if (line[i] == '-')
			nb_minus++;
		i++;
	}
	if (line[i] == '\0' && nb_minus == 1 && i > 2)
		return (1);
	//set_error si error
	return (0);
}

static int ft_isspace(char c)
{
	if (c <= 32)
		return (1);
	return (0);
}

int ft_is_room(char *line)
{
	int i;
	int nb_coord;
	int nb_char;

	i = ft_strlen(line);
	nb_coord = 0;
	nb_char = 0;
	while (i >= 0)
	{
		while (ft_isdigit(line[i]))
			i--;
		if (line[i] == ' ' && nb_coord < 2)
			nb_coord++;
		else if ((ft_isalpha(line[i]) || ft_isdigit(line[i]) || ft_isspace(line[i])) && nb_coord == 2)
			nb_char++;
		i--;
	}
	if (nb_coord == 2 && nb_char > 0)
		return (1);
	//set_error si error
	return (0);
}

/*
   static int ft_load_test_map(t_game *game)
   {
   t_ant *l_ants;
   t_room *room_start;
   l_ants = NULL;
   room_start = NULL;
   ft_bzero(&l_ants, sizeof(l_ants));
   ft_bzero(&room_start, sizeof(room_start));

   game->nb_rooms = 8;
   game->nb_ants = 10;

   game->ants = l_ants;
   game->room_start = l_room_start;

   return (0);
   }
   */

static int	ft_load_room(t_room *room, char *line, int room_id)
{
	int i;
	int nb_coord;

	i = ft_strlen(line) - 1;
	room->nb_room = room_id;
	nb_coord = 0;
	while (nb_coord < 2)
	{
		while (ft_isdigit(line[i]))
			i--;
		if (line[i] == ' ' && nb_coord < 2)
		{
			if (nb_coord == 0)
				room->y = ft_atoi(&line[i]);
			else
				room->x = ft_atoi(&line[i]);
			nb_coord++;
		}
		i--;
	}
	room->name = ft_strnew(i + 1);
	ft_strncpy(room->name, line,i + 1);
	return (0);
}

static int ft_display_lst(t_room *alst)
{
	if (alst == NULL)
		return (0);
	while (alst != NULL)
	{
		ft_putendl((*alst).name);
		alst = alst->next_room_list;
	}
	return (0);
}

static int	ft_add_room(t_game *game, t_room *new_room)
{
	new_room->next_room_list = game->room_start;
	game->room_start = new_room;
	return (0);
}

static int	ft_create_room(t_game *game, char *line)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	ft_bzero(room, sizeof(t_room));
	game->nb_rooms++;
	ft_load_room(room, line, game->nb_rooms);
	ft_add_room(game, room);
	return (0);
}

static int	ft_add_link(t_game *game, t_link *new_link)
{
	new_link->next = game->room_start->next_map;
	game->room_start->next_map = new_link;
	return (0);
}
static int	ft_add_bounds(t_game *game, char *room1, char *room2)
{
	t_link *link1;
	t_link *link2;
	t_room *ptr;
	ptr = game->room_start;
	int i;

	i = 0;
	link1 = (t_link *)malloc(sizeof(t_link));
	link2 = (t_link *)malloc(sizeof(t_link));
	while (i < 2)
	{
		ft_putnbr(i);
		while(ft_strcmp(ptr->name, room1) != 0 && ft_strcmp(ptr->name, room2) != 0)
			ptr = ptr->next_room_list;
		if (ft_strcmp(ptr->name, room1) == 0)
		{
			ft_putstr(room1);
			ft_putchar('-');
			ft_putstr(ptr->name);
			ft_putendl(" found !");
			ft_add_link(game, link2);
			ft_putnbr(game->room_start->nb_bounds);
			ptr->nb_bounds++;
			ft_putchar('-');
			ft_putnbr(ptr->nb_bounds);
			ft_putchar('\n');
			ptr = ptr->next_room_list;
		}
		else if (ft_strcmp(ptr->name, room2) == 0)
		{
			ft_putstr(room2);
			ft_putchar('-');
			ft_putstr(ptr->name);
			ft_putendl(" found !");
			ft_add_link(game, link1);
			ft_putnbr(ptr->nb_bounds);
			ptr->nb_bounds++;
			ft_putchar('-');
			ft_putnbr(ptr->nb_bounds);
			ft_putchar('\n');
			ptr = ptr->next_room_list;
		}
		i++;
	}
	return (0);
}

static int	ft_create_bounds(t_game *game, char *line)
{
	char *room1;
	char *room2;
	char **tab_split;

	tab_split = ft_strsplit(line, '-');
	room1 = tab_split[0];
	room2 = tab_split[1];
	ft_putstr("room 1 : ");
	ft_putendl(room1);
	ft_putstr("room 2 : ");
	ft_putendl(room2);
	ft_add_bounds(game, room1, room2);
	return (0);
}


int	ft_parse(char *line, t_game *game)
{
	//	t_ant *l_ants;
	//	l_ants = NULL;
	//	ft_bzero(&l_ants, sizeof(l_ants));
//	t_room	*a_lst_room;
//	a_lst_room = NULL;
	//verifier a chqaue test si error > 0 si oui stop partsing et traite donnees
	if (ft_is_com(line))
		ft_putstr("Comm : ");
	else if (ft_is_start(line))
		ft_putstr("Start: ");
	else if (ft_is_end(line))
		ft_putstr("End  : ");
	else if (ft_is_room(line))
	{
		//si room n'existe pas deja :
		//creer room + assigner le nom et les coordonnees
		game->nb_rooms++;
		ft_putstr("Room: ");
		ft_create_room(game, line);
	}
	else if (ft_is_tube(line))
	{
		ft_create_bounds(game, line);
		ft_putstr("Tube: ");
	}
	else
	{
		ft_putendl("FORMAT ERROR");
		return (-1);
	}
	ft_putendl(line);
	return (0);
}
