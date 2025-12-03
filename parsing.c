/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:53:21 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/03 11:23:08 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pars.h"

void del_content(void *content)
{
    free(content);
    content = NULL;
}
t_list *gahter_lines(int fd)
{
    t_list *list_of_lines = NULL;
    t_list *line;

    char *line = "magic";
    while(line != NULL)
    {
        line = get_next_line(fd);
        if(!line)
        {
            ft_lstclear(&list_of_lines, del_content);
            return NULL;
        }
        line = ft_lstnew(line);
        ft_lstadd_back(&list_of_lines, line);
    }
    return list_of_lines;
}
int verify_line(char *line, t_list *clear)
{
    int i = 0;
    int start_point = 0;
    int exit_point = 0;
    int collectables = 0;
    while(line[i] != '\0')
    {
        if(!ft_strchr(&line[0], '1') || !ft_strrchr(&line, '1'))
        {
            
        }
    }
}

char *check_lines(t_list *lines)
{
    t_list *copy_to_clear = lines;
    int start_point = 0;
    int exit_point = 0;
    int collectables = 0;
    while(lines->content != NULL)
    {
        
    }
    
}

int map_verify();