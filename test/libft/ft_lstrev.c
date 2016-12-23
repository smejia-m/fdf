/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smejia-m <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 15:28:50 by smejia-m          #+#    #+#             */
/*   Updated: 2016/07/25 15:33:48 by smejia-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstrev(t_list **list)
{
	t_list	*prev;
	t_list	*now;
	t_list	*next;

	prev = NULL;
	now = *list;
	while (now != NULL)
	{
		next = now->next;
		now->next = prev;
		prev = now;
		now = next;
	}
	*list = prev;
}
