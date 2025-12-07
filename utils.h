/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:11:19 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/07 18:14:33 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

char				*ft_strchr(const char *s, int c);
char				*get_next_line(int fd);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(const char *s);
char				*ft_strdup(char *s);
void				del_content(void *content);
int					map_verify(int fd);
int					check_line_length(char *line, int len);
int					check_first_last_line(char *line, int base_length);
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_requirements
{
	int				start;
	int				exit;
	int				collect;
	int				line_length;
	int				flag;
	int				validity;
}					t_requirements;

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
t_list				*gahter_lines(int fd);

#endif
