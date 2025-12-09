/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:53:21 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/09 18:57:10 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

t_list	*gahter_lines(int fd, t_gather *data)
{
	for_norminette_sake(data);
	while (data->line)
	{
		data->line = get_next_line(fd);
		if (!data->line)
			break ;
		if (!data->line[0])
		{
			free(data->line);
			if (!data->inside_map)
				continue ;
			data->empties = 1;
			continue ;
		}
		if (data->empties)
			return (free(data->line), ft_lstclear(&data->list, del), NULL);
		data->inside_map = 1;
		data->empties = 0;
		data->node = ft_lstnew(data->line);
		if (!data->node)
			return (free(data->line), ft_lstclear(&data->list, del), NULL);
		ft_lstadd_back(&data->list, data->node);
	}
	return (data->list);
}

int	check_line(char *line, t_requirements *data, int base_length)
{
	int	i;
	int	line_length;

	line_length = ft_strlen(line);
	if (!line_length)
		return (1);
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
	t_gather		gather_data;

	init_data(&data);
	data.lines = gahter_lines(fd, &gather_data);
	if (!data.lines || fd < 0)
		return (0);
	data.another_head = data.lines;
	data.line_length = ft_strlen(data.lines->content);
	if (check_first_last_line(data.lines->content, data.line_length) == 0)
		return (ft_lstclear(&data.another_head, del), 0);
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
		return (ft_lstclear(&data.another_head, del), 0);
	return (ft_lstclear(&data.another_head, del), 1);
}
