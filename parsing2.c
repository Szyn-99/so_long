/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/07 17:30:37 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/09 18:17:43 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	check_first_last_line(char *line, int base_length)
{
	int	line_length;
	int	i;

	line_length = ft_strlen(line);
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

int	check_status(int start_point, int exit_point, int collectables)
{
	if ((start_point == 1 && exit_point == 1 && collectables >= 1))
		return (1);
	return (0);
}

int	final_check(char *found, char *str, int i)
{
	if (!found)
	{
		while (str[i] != '.' && str[i])
			i++;
		if (i >= 1)
			return (1);
		else
			return (0);
	}
	i++;
	while (found[i] != '.' && found[i])
		++i;
	if (i >= 1)
		return (1);
	return (0);
}

int	check_map_path(char *str)
{
	char	*extention;
	int		i;
	char	*found;

	if (!str)
		return (0);
	extention = ft_strnstr(str, ".ber", ft_strlen(str));
	if (extention == NULL)
		return (0);
	i = 0;
	found = ft_strrchr(str, '/');
	if (!found)
		found = NULL;
	return (final_check(found, str, i));
}
