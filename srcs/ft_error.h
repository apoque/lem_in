/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 18:54:57 by srossi            #+#    #+#             */
/*   Updated: 2018/04/26 19:18:17 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "lem_in.h"

typedef	struct	s_error
{
	char	*id;
	char	*reason;
	int		error;
}				t_error;


struct	s_error		tab_error[]
{
	{"l_error_1", "Error. Link creation failed : room #1 doesn't exist.", -1},
	{"l_error_2", "Error. Link creation failed : room #2 doesn't exist.", -1},
	{"l_error_s", "Error: Start has no link.", -2},
	{"l_error_e", "Error: End has no .link", -2},
};

# endif
