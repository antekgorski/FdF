/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 19:10:10 by agorski           #+#    #+#             */
/*   Updated: 2025/01/19 19:10:14 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_map_test(t_mlx *data)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i + 1 <= (data->map_height))
	{
		j = 0;
		while ((j + 1) <= (data->map_width))
		{
			ft_printf("[%d,%d] x:%d y:%d alt:%d rgb:%X row_len:%d map_len:%d\n",
				i, j, data->map_table[i][j].x, data->map_table[i][j].y,
				data->map_table[i][j].alt, data->map_table[i][j].color,
				data->map_table[i][j].row_width, data->map_width);
			if (j + 1 == data->map_table[i][j].row_width)
				break ;
			j++;
		}
		i++;
	}
	ft_printf("\n\n<<<<<<<<<<>>>>>>>>>>\n\n");
}
