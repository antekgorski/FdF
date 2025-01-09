/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:05:26 by agorski           #+#    #+#             */
/*   Updated: 2025/01/09 19:14:28 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw_line(t_mlx data)
{
	t_point	start;
	t_point	end;

	start = (t_point){0, 0, 100, 100};
	end = (t_point){0, 0, 100, 500};
	drawLine(&data, start, end); // | po lewej
	start = (t_point){0, 0, 100, 100};
	end = (t_point){0, 0, 700, 100};
	drawLine(&data, start, end); // - na gorze
	end = (t_point){0, 0, 700, 500};
	drawLine(&data, start, end); /*  \      */
	start = (t_point){0, 0, 700, 100};
	end = (t_point){0, 0, 700, 500};
	drawLine(&data, start, end); //  /
	start = (t_point){0, 0, 100, 500};
	end = (t_point){0, 0, 700, 500};
	drawLine(&data, start, end); // | po prawej
	start = (t_point){0, 0, 100, 100};
	end = (t_point){0, 0, 700, 500};
	drawLine(&data, start, end); // _ na dole
}

int	main(int argc, char **argv)
{
	t_mlx	data;

	(void)argc;
	(void)argv;
	ft_mlx_init(&data);
	ft_event_handle(&data);
	ft_draw_line(data);
	mlx_loop(data.mlx_start);
	return (0);
}
