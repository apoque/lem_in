/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/04/27 17:54:11 by gvannest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	char	*line;
	t_game	game;
	int		i;
	t_ways	*list_ways;

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
		else if (i == -1)
		{
			ft_display_lines(&game);
			return (-1);
		}
	}
	ft_display_lines(&game);
	if (ft_last_check(&game) == -2)
		return (-1);
	//ft_display_lst(game.rooms);
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

	k = 0;
	game.n = 3;
	set.set = (int **)malloc(sizeof(int *) * game.n);
	while (k < game.n)
	{
		m = 0;
		set.set[k] = (int *)malloc(sizeof(int) * (game.nb_rooms + 1));
		while (m <= game.nb_rooms)
		{
			set.set[k][m] = -3;
			m++;
		}
		k++;
	}
	set.nb_path = 0;
	set.cost = 0;

	game.set = set;
	game.set.found = 0;




	i = 0;
		while (get_next_line(0, &line))
		{
			if (i == 0)
			{
			//	ft_putstr("nb ants : ");
				game.nb_ants = ft_atoi(line);
				ft_add_lants(&game);
			//	ft_putnbr(game.nb_ants);
			//	ft_putstr("\n");
				game.f_section = 1;
			}
			else
			{
				if (ft_parse(line, &game) == -1)
					return (-1);
			}
			i++;
			ft_add_line(line, &game);
			ft_strdel(&line);
		}
	ft_putendl("--------------------------");
//	ft_display_lst(game.rooms);
	ft_putendl("--------------------------");
//	ft_display_lines(&game);
	ft_putendl("--------------------------");
	list_paths = ft_short_path(&game);
=======
	//	ft_display_lst(game.rooms);
	ft_display_lines(&game);
>>>>>>> parse:srcs/main.c
	return (0);
}*/
