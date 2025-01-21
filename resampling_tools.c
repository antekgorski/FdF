/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42warsaw.pl>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:52:11 by agorski           #+#    #+#             */
/*   Updated: 2025/01/21 00:37:15 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	ft_init_center_ofset(t_center_ofset *c_ofset)
{
	c_ofset->i = 0;
	c_ofset->j = 0;
	c_ofset->min_x = INT_MAX;
	c_ofset->max_x = INT_MIN;
	c_ofset->min_y = INT_MAX;
	c_ofset->max_y = INT_MIN;
	c_ofset->win_height = HEIGHT;
	c_ofset->win_width = WIDTH;
}

void	ft_map_center(t_mlx *data)
{
	t_center_ofset	c_ofset;

	ft_init_center_ofset(&c_ofset);
	while (c_ofset.i < data->map_height)
	{
		while (c_ofset.j < data->map_width)
		{
			if (data->map_table[c_ofset.i][c_ofset.j].off_x < c_ofset.min_x)
				c_ofset.min_x = data->map_table[c_ofset.i][c_ofset.j].off_x;
			if (data->map_table[c_ofset.i][c_ofset.j].off_x > c_ofset.max_x)
				c_ofset.max_x = data->map_table[c_ofset.i][c_ofset.j].off_x;
			if (data->map_table[c_ofset.i][c_ofset.j].off_y < c_ofset.min_y)
				c_ofset.min_y = data->map_table[c_ofset.i][c_ofset.j].off_y;
			if (data->map_table[c_ofset.i][c_ofset.j].off_y > c_ofset.max_y)
				c_ofset.max_y = data->map_table[c_ofset.i][c_ofset.j].off_y;
			c_ofset.j++;
		}
		c_ofset.j = 0;
		c_ofset.i++;
	}
	data->c_offset_x -= ((c_ofset.min_x + c_ofset.max_x) / 2) - (WIDTH / 2);
	data->c_offset_y -= ((c_ofset.min_y + c_ofset.max_y) / 2) - (HEIGHT / 2);
}

void	ft_apply_m_offset(t_mlx *data, t_point *point, size_t i, size_t j)
{
	(void)i;
	(void)j;
	point->off_x += data->m_offset_x;
	point->off_y += data->m_offset_y;
}

void	ft_apply_cent_offset(t_mlx *data, t_point *point, size_t i, size_t j)
{
	(void)i;
	(void)j;
	point->off_x += data->c_offset_x;
	point->off_y += data->c_offset_y;
}
