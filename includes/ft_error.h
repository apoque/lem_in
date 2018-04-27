/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: srossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/27 10:20:53 by srossi            #+#    #+#             */
/*   Updated: 2018/04/27 10:42:40 by srossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERROR_H
# define FT_ERROR_H

# include "lem_in.h"

typedef	struct		s_error
{
	char	*reason;
	int		type_error;
	char	*str_print;

}t_error;

struct s_error tab_errors[] =
{
	{(char *)"room_add", -1,(char *)"Error: room was already added."}
};

#endif
