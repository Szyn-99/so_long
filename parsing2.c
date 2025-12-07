/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:37 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/07 17:30:38 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	check_first_last_line(char *line, int base_length)
{
	int	line_length;
	int	i;

	line_length = ft_strlen(line);
	printf("line length = %d\nbase_length = %d\n", line_length, base_length);
	if (line_length != base_length)
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}
