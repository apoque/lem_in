/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:21:48 by srossi            #+#    #+#             */
/*   Updated: 2018/04/16 19:53:25 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
	ft_putendl(room->name);
	return (0);
}

static int	ft_add_room(t_room **a_lst, t_room *new_room)
{
	new_room->next_room_list = *a_lst;
	*a_lst = new_room;
	return (0);
}

static int	ft_create_room(t_room **a_lst_room, int room_id, char *line)
{
	t_room *room;

	room = (t_room *)malloc(sizeof(t_room));
	ft_bzero(room, sizeof(t_room));
	ft_load_room(room, line, room_id);
	ft_putstr("room name : ");
	ft_putendl(room->name);
	ft_putstr("room id : ");
	ft_putnbr(room->nb_room);
	ft_putchar('\n');
	ft_putstr("X vaut : ");
	ft_putnbr(room->x);
	ft_putchar('\n');
	ft_putstr("Y vaut : ");
	ft_putnbr(room->y);
	ft_putchar('\n');
//	ft_add_room(a_lst_room, room);
	return (0);
}

int	ft_parse(char *line, t_game *game)
{
	//	t_ant *l_ants;
	t_room	**a_lst_room;
//	t_room	*lst_room_begin;
	//	l_ants = NULL;
	a_lst_room = NULL;
//	lst_room_begin = NULL;
	//	ft_bzero(&l_ants, sizeof(l_ants));
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
		ft_create_room(a_lst_room, game->nb_rooms, line);
	}
	else if (ft_is_tube(line))
		ft_putstr("Tube: ");
	else
	{
		ft_putendl("FORMAT ERROR");
		return (-1);
	}
	ft_putendl(line);
	return (0);
}
