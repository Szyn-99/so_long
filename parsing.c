/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:53:21 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/07 16:32:21 by aymel-ha         ###   ########.fr       */
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
		if(!line || line[0] == '\n')
			break;
		node = ft_lstnew(line);
		if (!node)
			return (free(line), ft_lstclear(&list_of_lines, del_content), NULL);
		ft_lstadd_back(&list_of_lines, node);
	}
	return (list_of_lines);
}

int	check_line(char *line, int *start_point, int *exit_point, int *collectables, int base_length)
{
	int	i;
	int line_length;
	if(!line || !line[0])
		return (1337);
	line_length = ft_strlen(line);
	printf("base_length = %d VS line_length = %d\n", base_length, line_length);
	if(line_length != base_length)
		return 0;
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
			return 0;
		i++;
	}
	return (1);
}

int check_status(int start_point, int exit_point, int collectables)
{
	if ((start_point == 1 && exit_point == 1 && collectables >= 1))
		return (1);
	return (0);
}
int check_line_length(char *line, int len)
{
    int line_len = ft_strlen(line);
    if(line_len != len)
        return 0;
    return 1;
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
	int line_length;
	int flag = 1;


	
	start_point = 0;
	exit_point = 0;
	collectables = 0;
	lines = gahter_lines(fd);
	validity = 99;
	if (!lines || fd < 0)
		return (0);
	
	another_head = lines;
	line_to_check = "magic";
	while (lines != NULL)
	{
		line_to_check = lines->content;
		if(!line_to_check)
			break ;
		if(flag)
		{
			line_length = ft_strlen(line_to_check);
			flag = 0;
		}
		validity = check_line(line_to_check, &start_point, &exit_point, &collectables, line_length);
		printf("check_line = %d\n", validity);
		if (validity == 1337)
			break;
		else if(validity == 0)
			return (ft_lstclear(&another_head, del_content), 0);
		lines = lines->next;
	}
	printf("check_status = %d\nvalidity = %d\nSP %d\nEP = %d\nCol = %d\n", check_status(start_point, exit_point, collectables),validity, start_point, exit_point, collectables);
	if(check_status(start_point, exit_point, collectables) == 0 || validity != 1337)
		return (ft_lstclear(&another_head, del_content), 0);
	
	return (ft_lstclear(&another_head, del_content), 1);
}
