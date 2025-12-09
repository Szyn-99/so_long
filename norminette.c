/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norminette.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 18:10:28 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/09 18:17:44 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	init_data(t_requirements *data)
{
	data->lines = NULL;
	data->another_head = NULL;
	data->start = 0;
	data->exit = 0;
	data->collect = 0;
	data->line_length = 0;
	data->flag = 0;
	data->validity = 0;
	data->linex = NULL;
}
void	for_norminette_sake(t_gather *data)
{
	data->inside_map = 0;
	data->empties = 0;
	data->list = NULL;
	data->line = "magic";
}
void	del(void *content)
{
	free(content);
}