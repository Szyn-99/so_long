/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:53:21 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/07 17:46:37 by aymel-ha         ###   ########.fr       */
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

int	map_verify(int fd)
{
	t_list			*lines;
	t_list			*another_head;
	t_requirements	requirements;
	char			*line_to_check;

	if (!lines || fd < 0)
		return (0);
	requirements.flag = 1;
	requirements.start_point = 0;
	requirements.exit_point = 0;
	requirements.collectables = 0;
	lines = gahter_lines(fd);
	requirements.validity = 99;
	another_head = lines;
	while (lines != NULL)
	{
		line_to_check = lines->content;
		if (!line_to_check)
			break ;
		if (requirements.flag)
		{
			requirements.line_length = ft_strlen(line_to_check);
			if (check_first_last_line(line_to_check,
					requirements.line_length) == 0)
				return (0);
			requirements.flag = 0;
		}
		requirements.validity = check_line(line_to_check, &requirements.start_point,
				&requirements.exit_point, &requirements.collectables,
				requirements.line_length);
		if (requirements.validity == 0)
			break ;
		lines = lines->next;
	}
	if (!check_first_last_line(line_to_check, requirements.line_length))
		requirements.validity = 0;
	if (check_status(requirements.start_point, requirements.exit_point,
			requirements.collectables) == 0 || requirements.validity == 0)
		return (ft_lstclear(&another_head, del_content), 0);
	return (ft_lstclear(&another_head, del_content), 1);
}
