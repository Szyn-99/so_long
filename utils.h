/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:11:19 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/09 17:56:16 by aymel-ha         ###   ########.fr       */
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

int			check_map_path(char *str);
void		del_content(void *content);
int			map_verify(int fd);
int			check_first_last_line(char *line, int base_length);
int			check_status(int start_point, int exit_point, int collectables);
void		init_data(t_requirements *data);

t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
t_list		*gahter_lines(int fd);

#endif
