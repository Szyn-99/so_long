/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:45:43 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/08 16:45:44 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	int		fd;
	t_list	*one;
	t_list	*clear;
	int		a;

	fd = open("map.ber", O_RDONLY);
	a = map_verify(fd);
	printf("map status = %d\n", a);
}
