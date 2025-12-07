/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:53:21 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/07 18:42:24 by aymel-ha         ###   ########.fr       */
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
		if (!line || !line[0])
			break ;
		node = ft_lstnew(line);
		if (!node)
			return (free(line), ft_lstclear(&list_of_lines, del_content), NULL);
		ft_lstadd_back(&list_of_lines, node);
	}
	return (list_of_lines);
}

int	check_line(char *line, int *start_point, int *exit_point, int *collectables,
		int base_length)
{
	int	i;
	int	line_length;

	line_length = ft_strlen(line);
	if (line_length != base_length)
		return (0);
	if ((line[0] != '1' || line[line_length - 1] != '1'))
		return (0);
	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == 'E')
			(*exit_point)++;
		else if (line[i] == 'P')
			(*start_point)++;
		else if (line[i] == 'C')
			(*collectables)++;
		else if (line[i] != '0' && line[i] != '1')
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

int	check_line_length(char *line, int len)
{
	int	line_len;

	line_len = ft_strlen(line);
	if (line_len != len)
		return (0);
	return (1);
}

void	init_data(int *flag, int *start_point, int *exit_point,
		int *collectables)
{
	*flag = 1;
	*start_point = 0;
	*exit_point = 0;
	*collectables = 0;
}
int	map_verify(int fd)
{
	t_list			*lines;
	t_list			*another_head;
	t_requirements	data;
	char			*line_to_check;

	lines = gahter_lines(fd);
	if (!lines || fd < 0)
		return (0);
	init_data(&data.flag, &data.start, &data.exit, &data.collect);
	another_head = lines;
	while (lines != NULL)
	{
		line_to_check = lines->content;
		if (data.flag)
		{
			data.line_length = ft_strlen(line_to_check);
			if (check_first_last_line(line_to_check, data.line_length) == 0)
				return (0);
			data.flag = 0;
		}
		data.validity = check_line(line_to_check, &data.start, &data.exit,
				&data.collect, data.line_length);
		if (data.validity == 0)
			break ;
		lines = lines->next;
	}
	if (!check_first_last_line(line_to_check, data.line_length))
		data.validity = 0;
	if (check_status(data.start, data.exit, data.collect) == 0
		|| data.validity == 0)
		return (ft_lstclear(&another_head, del_content), 0);
	return (ft_lstclear(&another_head, del_content), 1);
}
