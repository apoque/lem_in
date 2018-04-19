/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:04:38 by gvannest          #+#    #+#             */
/*   Updated: 2018/04/13 13:32:36 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>

typedef struct					s_ant
{
				int				nb; // numero de la fourmi
				int				*path; // suite des numeros de salle qu elle va parcourir
				int				nb_moves; // nombre de coup deja joue
				int				nb_room; // numero de la salle ou elle se trouve
				int				wave; // numero de la vague de depart
}								t_ant;

typedef struct					s_room
{
				char			*name; // nom de la salle
				int				nb_room; // numero de la salle 
				int				x; //coordonnees de la salle
				int				y;
				int				nb_bonds; //nombre de liaisons d une salle
				int				*bonded_rooms; // liste des salles adjascentes
				int				occupied; //0 si libre sinon numero de la fourmi
				struct s_room	*next; // pointeur vers la salle suivante de l affichage
				struct s_room	**next_map; // tableau de pointeurs sur les salles next
				struct s_room	*next_short_path; //pointeur sur next salle du chemin le plus court
}								t_room;

typedef struct					s_game
{
				t_ant			*ants; // liste des fourmis
				t_room			**rooms; // debut de la liste chainee des salles
				int				**paths; // tableau des n chemins les plus cours
				int				nb_rooms; // nombre total de salle
				int				nb_ants; // nombre total de fourmi
				int				nb_paths; // nombre de chemins selectionnes
}								t_game;

typedef struct					s_paths
{
				t_room			*room;// pointeur vers la premiere salle de chaque chemin court
				struct s_paths	*next;// pointeur vers chemin le plus court suivant
}								t_paths;

typedef struct					s_ways
{
				int				*way;
				struct s_ways	*next;
}								t_ways;

typedef struct					s_sets
{
				int				**set;
				char			****names;
				int				cost;
}								t_sets;

void							ft_select_path(t_game *game);
void							ft_display_res(t_game *game);
int								ft_size_path(int *path);
void							ft_compatibilities(t_game *game, t_ways **start, int n);
#endif
