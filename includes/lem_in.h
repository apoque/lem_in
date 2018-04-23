/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Updated: 2018/04/23 10:50:21 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include <stdlib.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

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
				struct s_room	*next; // pointeur sur la room suivante
				struct s_room	*next_short_path; //pointeur sur next salle du chemin le plus court
}								t_room;

typedef struct					s_link
{
				t_room			*room;// pointeur vers la premiere salle de chaque chemin court
				struct s_link	*next;// pointeur vers chemin le plus court suivant
}								t_link;

typedef struct					s_game
{
				t_ant			*ants; // liste des fourmis
				t_room			*rooms;
				t_room			*room_start; // debut de la liste chainee des salles
				t_room			*room_end; // fin de la liste chainee des salles
				int				**paths; // tableau des n chemins les plus cours
				int				f_start;
				int				f_end;
				int				f_section;
				int				nb_rooms; // nombre total de salle
				int				nb_ants; // nombre total de fourmi
				int				nb_paths; // nombre de chemins selectionnes
}								t_game;

typedef struct					s_paths
{
				t_room			**sh_path;// pointeur vers la premiere salle de chaque chemin court
				struct s_paths	*next;// pointeur vers chemin le plus court suivant
}								t_paths;


typedef struct					s_ways
{
				int				*way;
				struct s_way	*next;
}								t_ways;

typedef struct					s_pile
{
				t_room			**path; //constitution du chemin dans ce tableau de pointeurs rooms
				struct s_pile	*next; // pointeur vers le cehmin suivant
}								t_pile;

typedef struct					s_sets
{
				int				**set;
				char			****names;
				int				cost;
}								t_sets;

void							ft_select_path(t_game *game);
void							ft_display_res(t_game *game);
int								ft_parse(char *line, t_game *game);
int								ft_create_bounds(t_game *game, char *line);
int								ft_create_room(t_game *game, char *line);
int								ft_size_path(int *path);
void							ft_comptabilities(t_game *game, t_ways **start, int n);
t_paths							*ft_short_path(t_game *game);

#endif
