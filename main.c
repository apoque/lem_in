/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:07:28 by srossi            #+#    #+#             */
/*   Updated: 2018/04/13 11:07:53 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lem_in.h"

int main(int argc, const char *argv[])
{
	int fd;
	char *line;
	int i; // nb lignes utiliser structure apres 

	i = 0;
	if (argc != 2)
	{
		ft_putendl("usage: ./lem_in source_file");
		return (-1);
	}
	if ((fd = open(argv[1], O_RDONLY)) != -1)
	{
		while (get_next_line(fd, &line))
		{
			if (i == 0)
			{
				ft_putstr("nb ants : ");
				ft_putendl(line);
			}
			else
				ft_parse(line);
			i++;
		}
	}
	else
	{
		ft_putendl("Error: wrong source_file");
		return (-1);
	}
	if (close(fd == -1))
	{
		ft_putendl("Error: couldn't close source_file");
		return (-1);
	}
	
	return (0);
}
