/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aymel-ha <aymel-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 16:45:43 by aymel-ha          #+#    #+#             */
/*   Updated: 2025/12/09 19:00:25 by aymel-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	fd;
	int	status;

	if (ac != 2)
	{
		printf("No Path");
		return (1);
	}
	(void)ac;
	if (!av[1])
		return (printf("Requires Map"), 1);
	if (check_map_path(av[1]) == 0)
		return (printf("Invalid Path"), 1);
	fd = open(av[1], O_RDONLY);
	printf("%d\n", fd);
	status = map_verify(fd);
	if (status == 1)
	{
		printf("Valid Map");
		return (0);
	}
	else
		return (printf("Invalid Map"), 1);
}
