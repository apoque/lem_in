#include "lem_in.h"
#include <stdio.h>

int ft_display_lst(t_room *room)
{
	t_room *alst;
	t_link *link;

	alst = room;
	if (alst == NULL)
		return (0);
	while (alst != NULL)
	{
		ft_putstr("Room (");
		ft_putnbr(alst->nb_room);
		ft_putstr(") : ");
		ft_putendl(alst->name);
		ft_putstr("Liaisons : ");
		link = alst->next_map;
		while (link)
		{
			ft_putstr(link->room->name);
			ft_putstr(" ; ");
			link = link->next;
		}
		ft_putchar('\n');
		alst = alst->next;
	}
	return (0);
}
