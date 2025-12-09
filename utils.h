/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:11:19 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/09 18:56:26 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "utils/utils_helpers.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_requirements
{
	t_list	*lines;
	t_list	*another_head;
	int		start;
	int		exit;
	int		collect;
	int		line_length;
	int		flag;
	int		validity;
	char	*linex;
}			t_requirements;

typedef struct s_gather
{
	t_list	*list;
	t_list	*node;
	char	*line;
	int		inside_map;
	int		empties;
}			t_gather;

/*norminette.c*/
void		for_norminette_sake(t_gather *data);
void		init_data(t_requirements *data);
void		del(void *content);
/*parsing2.c*/
int			check_map_path(char *str);
int			check_status(int start_point, int exit_point, int collectables);
int			check_first_last_line(char *line, int base_length);
int			final_check(char *found, char *str, int i);

/*parsing.c*/
int			check_line(char *line, t_requirements *data, int base_length);
int			map_verify(int fd);
t_list		*gahter_lines(int fd, t_gather *data);

#endif
