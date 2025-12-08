/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_helpers.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/16 11:11:19 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/08 19:56:53 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HELPERS_H
# define UTILS_HELPERS_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1337
# endif

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

char				*ft_strrchr(const char *s, int c);
char				*ft_strchr(const char *s, int c);
char				*get_next_line(int fd);
char				*ft_strjoin(char *s1, char *s2);
size_t				ft_strlen(const char *s);
char				*ft_strdup(char *s);
char				*ft_strnstr(const char *big, const char *little, size_t len);

t_list				*ft_lstnew(void *content);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));

#endif
