/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/04/26 18:26:17 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	main(void)
{
	char	*line;
	t_game	game;
	int		i;

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
	if (ft_last_check(&game) == -2)
	{
		ft_display_lines(&game);
		return (-1);
	}
	//	ft_display_lst(game.rooms);
	ft_display_lines(&game);
	return (0);
}
