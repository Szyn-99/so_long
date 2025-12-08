/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 11:42:02 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/08 18:05:21 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	l;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (i < len && big[i] != '\0')
	{
		j = 0;
		l = i;
		while (l < len && big[l] && little[j] && little[j] == big[l])
		{
			l++;
			j++;
		}
		if (little[j] == '\0')
		{
			return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
