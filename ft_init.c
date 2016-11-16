/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 12:47:01 by smejia-m          #+#    #+#             */
/*   Updated: 2016/11/11 12:47:03 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
**fonction qui initisialise la structure param
*/

t_parse			*ft_parse_ini(void)
{
	t_parse		*params;

	if (!(params = (t_parse *)malloc(sizeof(t_parse))))
		return (NULL);
	params->tab = NULL;
	params->index_y = 0;
	params->index_x = 0;
	params->count_lines = 0;
	params->tmp_len = 0;
	params->len = 0;
	params->ret = 0;
	return (params);
}