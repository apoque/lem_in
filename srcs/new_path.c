/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvannest <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 13:47:49 by gvannest          #+#    #+#             */
/*   Updated: 2018/04/30 19:24:09 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		display(t_ways *list_ways)
{
	int i = 0;

	while (list_ways->sh_path[i])
	{
		printf("%s ", list_ways->sh_path[i]->name);
		i++;
	}
	putchar('\n');
}

void	ft_init_set(t_game *game)
{
	if(!(game->set.set = (int **)malloc(sizeof(int *) * game->n)))
		exit (EXIT_FAILURE);
	game->set.nb_path = 0;
	game->set.cost = 0;
	game->set.found = 0;
}


int		ft_new_shortpath(t_game *game, t_pile *current, t_ways **list_ways)
{
	t_ways	*new_path;
	int		k;

	k = 0;
	game->nb_chemins_trouves++;
	//printf("nb de chemins trouves : %d\n", game->nb_chemins_trouves);
	while (current->path[k])
		k++;
	if (!(new_path = ft_memalloc(sizeof(*new_path))) ||
		!(new_path->sh_path = ft_memalloc(sizeof(t_room*) * (k + 2))))
		exit(EXIT_FAILURE);
	ft_memcpy(new_path->sh_path, current->path, sizeof(t_room*) * (k + 2));
	if (!(new_path->way = ft_memalloc(sizeof(int) * (k + 3))))
		exit(EXIT_FAILURE);
	k = 0;
	while (new_path->sh_path[k])
	{
		new_path->way[k] = new_path->sh_path[k]->nb_room;
		k++;
	}
	new_path->way[k] = -3;
	game->k = k - 1;
	if (*list_ways != 0)
		new_path->next = *list_ways;
	*list_ways = new_path;
	ft_compatibilities(game, list_ways, game->n);
	//printf("longueur chemin : %d\n", game->k);
	//printf("give path cost : %d\n", game->set.cost);
	printf("csv%d;%d;%d", game->nb_chemins_trouves, game->k, game->set.cost);
	//printf("Premiere salle du chemin trouve : %s\n", (*list_ways)->sh_path[1]->name);
	//display(*list_ways);
	return (0);
}
