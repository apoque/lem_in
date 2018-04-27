/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/04/27 18:24:14 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	char	*line;
	t_game	game;
	int		i;
	t_ways	*list_ways;
	int		k;
	int		m;

	i = 0;
	ft_bzero(&game, sizeof(t_game));
	while (get_next_line(0, &line) && i == 0)
	{
		i = ft_parse(line, &game);
		if (i == 0)
		{
			ft_add_line(line, &game);
			if (line)
				ft_strdel(&line);
		}
		else if (i == -2)
			return (-1);
		else if (i == -1)
		{
			ft_display_lines(&game);
			return (-1);
		}
	}
	ft_display_lines(&game);
	if (ft_last_check(&game) == -2)
		return (-1);
	list_ways = ft_short_path(&game);
	ft_select_path(&game);
	ft_display_res(&game);
	return (0);
}

/*int main()
//{
	char *line;
	int i; // nb lignes utiliser structure apres 
	t_ways	*list_paths;
	t_game game;

	ft_bzero(&game, sizeof(t_game));

	t_set	set;
	int		k;
	int		m;

=======
	ft_putchar('\n');
>>>>>>> 823bc038341225f78c5858fd3eeb33bd6fc1b74d
	k = 0;
	game.n = 2;
	game.set.set = (int **)malloc(sizeof(int *) * game.n);
	while (k < game.n)
	{
		m = 0;
		game.set.set[k] = (int *)malloc(sizeof(int) * (game.nb_rooms + 1));
		while (m <= game.nb_rooms)
		{
			game.set.set[k][m] = -3;
			m++;
		}
		k++;
	}
	game.set.nb_path = 0;
	game.set.cost = 0;
	game.set.found = 0;
	list_ways = ft_short_path(&game);
	return (0);
}
