/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:18:35 by srossi            #+#    #+#             */
/*   Updated: 2018/04/11 18:20:50 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int	ft_error(int type_error)
{
	if (type_error == 1)
		ft_putendl("Error #1");
	else if (type_error == 2)
		ft_putendl("Error #2");
	return (-1);
}
