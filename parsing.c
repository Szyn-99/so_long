/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:53:21 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/06 21:42:08 by aymel-ha         ###   ########.fr       */
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
		// if(!line)
		// 	break;
		node = ft_lstnew(line);
		if (!node)
			return (free(line), ft_lstclear(&list_of_lines, del_content), NULL);
		ft_lstadd_back(&list_of_lines, node);
	}
	return (list_of_lines);
}

int	check_line(char *line, int *start_point, int *exit_point, int *collectables)
{
	int	i;
	int line_length;
	if(!line || !line[0])
		return (0);
	line_length = ft_strlen(line);
	if ((line[0] != '1' && line[line_length - 1 - (line[line_length - 1] == '\n')] != '1'))
		return (999);
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
	{
		if (line[i] == 'E')
			(*exit_point)++;
		else if (line[i] == 'P')
			(*start_point)++;	
		else if (line[i] == 'C')
			(*collectables)++;
		else if (line[i] != '0' && line[i] != '1')
			return 0;
		i++;
	}
	return (1);
}

int	map_verify(int fd)
{
	int		start_point;
	int		exit_point;
	int		collectables;
	int		validity;
	t_list	*lines;
	t_list	*another_head;
	char *line_to_check;

	start_point = 0;
	exit_point = 0;
	collectables = 0;
	lines = gahter_lines(fd);
	validity = 99;
	if (!lines)
		return (0);
	another_head = lines;
	line_to_check = "magic";
	while (lines != NULL)
	{
		line_to_check = lines->content;
		if(!line_to_check)
			break ;
		validity = check_line(line_to_check, &start_point, &exit_point, &collectables);
		printf("Line: %sValidity: %d\n", line_to_check, validity);
		if (validity == 0)
			return (ft_lstclear(&another_head, del_content), validity);
		lines = lines->next;
	}
	printf("Start: %d, Exit: %d, Collectables: %d\n", start_point, exit_point, collectables);
	if (!(start_point == 1 && exit_point == 1  && collectables >= 1))
		return (ft_lstclear(&another_head, del_content), 0);
	return (ft_lstclear(&another_head, del_content), 1);
}
