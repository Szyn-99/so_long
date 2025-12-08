/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:53:21 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/08 17:47:31 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

void	del_content(void *content)
{
	free(content);
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
		if (!line)
			break ;
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue ;
		}
		node = ft_lstnew(line);
		if (!node)
			return (free(line), ft_lstclear(&list_of_lines, del_content), NULL);
		ft_lstadd_back(&list_of_lines, node);
	}
	return (list_of_lines);
}

int	check_line(char *line, t_requirements *data, int base_length)
{
	int	i;
	int	line_length;

	line_length = ft_strlen(line);
	if (!line_length)
		return (0);
	if (line_length != base_length)
		return (0);
	if ((line[0] != '1' || line[line_length - 1] != '1'))
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'E')
			data->exit++;
		else if (line[i] == 'P')
			data->start++;
		else if (line[i] == 'C')
			data->collect++;
		else if (line[i] != '0' && line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

int	map_verify(int fd)
{
	t_requirements	data;

	init_data(&data);
	data.lines = gahter_lines(fd);
	if (!data.lines || fd < 0)
		return (0);
	data.another_head = data.lines;
	data.line_length = ft_strlen(data.lines->content);
	if (check_first_last_line(data.lines->content, data.line_length) == 0)
		return (ft_lstclear(&data.another_head, del_content), 0);
	while (data.lines != NULL)
	{
		data.linex = data.lines->content;
		data.validity = check_line(data.linex, &data, data.line_length);
		if (data.validity == 0)
			break ;
		data.lines = data.lines->next;
	}
	if (!check_first_last_line(data.linex, data.line_length))
		data.validity = 0;
	if (check_status(data.start, data.exit, data.collect) == 0
		|| data.validity == 0)
		return (ft_lstclear(&data.another_head, del_content), 0);
	return (ft_lstclear(&data.another_head, del_content), 1);
}
