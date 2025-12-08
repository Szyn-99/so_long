/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 12:43:23 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/08 19:51:14 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_helpers.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
	{
		return (lst);
	}
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}
