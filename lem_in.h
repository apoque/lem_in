/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:04:38 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/06 17:01:37 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

typedef struct				s_ant
{
				int			nb; // numero de la fourmi
				int			*path; // suite des numeros de salle qu elle va parcourir
				int			nb_moves; // nombre de coup deja joue
				int			nb_room; // numero de la salle ou elle se trouve
				int			wave; // numero de la vague de depart
}							t_ant;

typedef struct				s_room
{
				char		*name; // nom de la salle
				int			nb_room; // numero de la salle 
				int			x; //coordonnees de la salle
				int			y;
				int			nb_bonds; //nombre de liaisons d une salle
				int			*bonded_rooms; // liste des salles adjascentes
				int			occupied //0 si libre sinon numero de la fourmi
				s_room		*next; // pointeur sur la salle nb_room + 1
}							t_room;

typedef struct				s_map
{
				t_ant		*ants; // liste des fourmis
				t_room		**rooms; // debut de la liste chainee des salles
				int			**ways; // tableau des n chemins les plus cours
				int			nb_rooms; // nombre total de salle
}							t_map;

#endif
