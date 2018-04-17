/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:04:38 by gvannest          #+#    #+#             */
/*   Updated: 2018/04/17 18:03:08 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../gnl/get_next_line.h"

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
				int				nb_bounds; //nombre de liaisons d une salle
				int				*bonded_rooms; // liste des salles adjascentes
				int				occupied; //0 si libre sinon numero de la fourmi
				char			visited; //1 :si salle visitee dans algo  du chemin plus court sinon 0
				int				nb_steps;
				struct s_link	*next_map; // tableau de pointeurs sur les salles next
				struct s_room	*next_short_path; //pointeur sur next salle du chemin le plus court
				struct s_room	*next_room_list; // pointeur sur la room suivante parcours fichier
}								t_room;

typedef struct					s_link
{
				t_room			*room;// pointeur vers la premiere salle de chaque chemin court
				struct s_link	*next;// pointeur vers chemin le plus court suivant
}								t_link;

typedef struct					s_game
{
				t_ant			*ants; // liste des fourmis
				t_room			*room_start; // debut de la liste chainee des salles
				t_room			*room_end; // fin de la liste chainee des salles
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


void							ft_select_path(t_game *game);
void							ft_display_res(t_game *game);
int								ft_parse(char *line, t_game *game);

#endif
