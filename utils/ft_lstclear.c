/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 13:10:32 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/08 19:51:20 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_helpers.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!lst || !*lst || !del)
		return ;
	tmp = *lst;
	while (tmp)
	{
		tmp2 = tmp->next;
		ft_lstdelone(tmp, del);
		tmp = tmp2;
	}
	*lst = NULL;
}
