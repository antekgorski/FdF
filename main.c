/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:05:26 by agorski           #+#    #+#             */
/*   Updated: 2025/01/09 17:55:59 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_mlx	data;

	ft_mlx_init(&data);
	ft_event_handle(&data);
	drawLine(&data, 100, 100, 100, 500); // | po lewej
	drawLine(&data, 100, 100, 700, 100); // - na gorze
	drawLine(&data, 100, 100, 700, 500); /*  \      */
	drawLine(&data, 100, 500, 700, 100); //  /
	drawLine(&data, 700, 100, 700, 500); // | po prawej
	drawLine(&data, 100, 500, 700, 500); // _ na dole
	mlx_loop(data.mlx_start);
	return (0);
}
