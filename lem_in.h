/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 17:43:37 by srossi            #+#    #+#             */
/*   Updated: 2018/04/11 18:05:04 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
 #define LEM_IN_H

typedef	struct	s_ant
{
	int	ant;
	int	*path;
	int	nb_iter;
	int	room;
	int	iter;
}				t_ant;

typedef	struct	s_room
{
	int		room;
	int		x;
	int		y;
	int		nb_links;
	int		*next_rooms;
	int		occupied;
	s_room	*next;
}				t_room;

typedef	struct	s_map
{
	s_ant	*tab;
	s_room	*lst_rooms;
	int		**n_short_paths;
	int		nb_rooms;
}				t_map;

#endif
