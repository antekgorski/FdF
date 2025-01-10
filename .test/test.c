/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 15:57:01 by agorski           #+#    #+#             */
/*   Updated: 2025/01/10 15:57:03 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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