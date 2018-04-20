/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compatibilities.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apoque   <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 16:04:38 by gvannest          #+#    #+#             */
/*   Updated: 2018/03/06 17:01:37 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

#include <stdio.h>


void		ft_print_set(int **set, int n)
{
	int	i;
	int	j;

	i = 0;
	printf("SET\n");
	while (i < n)
	{
		j = 1;
		printf("chemin n*%i = ", i + 1);
		while (set[i][j] != -2)
		{
			printf("%i-", set[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
	printf("\n");
}

int			ft_are_compatible(int **set, int n)
{
	int	i[5];

	i[0] = -1;
	i[4] = 0;
	while (++i[0] < n && i[4] == 0)
	{
		i[1] = i[0];
		while (++i[1] < n && i[4] == 0)
		{
			i[2] = 0;
			while (set[i[0]][i[2]] != -2 && i[4] == 0)
			{
				i[3] = 0;
				while (set[i[1]][i[3]] != -2 && i[4] == 0)
				{
					if (set[i[0]][i[2]] == set[i[1]][i[3]] && set[i[0]][i[2]] >= 0)
						i[4] = 1;
					i[3]++;
				}
				i[2]++;
			}
		}
	}
	return ((i[4] == 0) ? 1 : 0 );
}

void		ft_recursive(t_game *game, int ***sett, int *ii, t_ways **way_bi, int *nn)
{
	t_ways	*way_bis;
	int		i;
	int		n;
	int		**set;
	int		k;

	way_bis = *way_bi;
	i = *ii;
	n = *nn;
	set = *sett;
	k = i;
	while (way_bis != NULL)
	{
		set[i] = way_bis->way;
		if (ft_are_compatible(set, i + 1) == 1)
		{
			if (++i == n)
			{
				ft_print_set(set, n);
				ft_give_path_cost(game, set, game->n, game->nb_ants);
			}
			else
				ft_recursive(game, &set, &i, &(way_bis->next), &n);
		}
		if (k != i)
			i--;
		way_bis = way_bis->next;
	}
}

void		ft_compatibilities(t_game *game, t_ways **start, int n) //ft a appeler a chaque fois qu on trouve un nouveau chemin
{
	t_ways	*way;
	t_ways	*way_bis;
	int		**set;
	int		i;

	way = *start;
	set = (int **)malloc(sizeof(int *) * n);
	//while (way != NULL)
	//{
		i = 0;
		set[i] = way->way;
		way_bis = way->next;
		i++;
		while (n > 1 && game->set.found == 0)
		{
			ft_recursive(game, &set, &i, &way_bis, &n);
			n--;
		}
		ft_print_set(set, n);
		if (game->set.found == 0)
			ft_give_path_cost(game, set, n, game->nb_ants);
		//way = way->next;
	//}
}
