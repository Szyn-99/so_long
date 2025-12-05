/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:53:21 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/05 22:48:39 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"
#include <stdio.h>

void	del_content(void *content)
{
	free(content);
	content = NULL;
}
t_list	*gahter_lines(int fd)
{
	t_list	*list_of_lines;
	t_list	*node;
	char	*line;

	list_of_lines = NULL;
	line = "magic";
	while (line != NULL)
	{
		line = get_next_line(fd);
		node = ft_lstnew(line);
		free(line), line = NULL;
		if (!node)
			return (ft_lstclear(&list_of_lines, del_content), NULL);
		ft_lstadd_back(&list_of_lines, node);
	}
	return (list_of_lines);
}

int	check_line(char *line, int *start_point, int *exit_point, int *collectables)
{
	int	i;

	if (!((line[0]) == '1' && line[ft_strlen(line) - 1] == '1'))
		return (0);
	i = 1;
	while (line[i] != '\0')
	{
		if (line[i] == 'E')
			(*exit_point) += 1;
		if (line[i] == 'P')
			(*start_point) += 1;
		if (line[i] == 'C')
			(*collectables) += 1;
		if (line[i] == '0')
			i++;
		else
			return (0);
	}
	return (1);
}

int	map_verify(int fd)
{
	int		*start_point;
	int		*exit_point;
	int		*collectables;
	int		validity;
	t_list	*lines;
	t_list	*another_head;

	start_point = 0;
	exit_point = 0;
	collectables = 0;
	lines = gahter_lines(fd);
	if (!lines)
		return (0);
	another_head = lines;
	while (lines->content != NULL)
	{
		validity = check_line(lines->content, start_point, exit_point,
				collectables);
		if (!validity)
			return (ft_lstclear(&another_head, del_content), 0);
		lines = lines->next;
	}
	if (!(*start_point == 1 && *exit_point == 1 && *collectables >= 1))
		return (0);
	return (ft_lstclear(&another_head, del_content), 1);
}
