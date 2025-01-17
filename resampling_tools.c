/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 14:52:11 by agorski           #+#    #+#             */
/*   Updated: 2025/01/17 14:23:05 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	map_move_left(t_mlx *data, t_point *point)
{
	point->x -= data->mov_ofset;
}

void	map_move_right(t_mlx *data, t_point *point)
{
	point->x += data->mov_ofset;
}

void	map_move_up(t_mlx *data, t_point *point)
{
	point->y -= data->mov_ofset;
}

void	map_move_down(t_mlx *data, t_point *point)
{
	point->y += data->mov_ofset;
}

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

void	ft_map_center(t_mlx *data, t_point *point)
{
	point->x += data->c_offset_x;
	point->y += data->c_offset_y;
}

void	ft_map_recenter(t_mlx *data, t_point *point)
{
	point->x -= data->c_offset_x;
	point->y -= data->c_offset_y;
}


void	ft_center_offset(t_mlx *data)
{
	t_center_ofset	c_ofset;

	ft_init_center_ofset(&c_ofset);
	while (c_ofset.i < data->map_height)
	{
		while (c_ofset.j < data->map_width)
		{
			if (data->map_table[c_ofset.i][c_ofset.j].x < c_ofset.min_x)
				c_ofset.min_x = data->map_table[c_ofset.i][c_ofset.j].x;
			if (data->map_table[c_ofset.i][c_ofset.j].x > c_ofset.max_x)
				c_ofset.max_x = data->map_table[c_ofset.i][c_ofset.j].x;
			if (data->map_table[c_ofset.i][c_ofset.j].y < c_ofset.min_y)
				c_ofset.min_y = data->map_table[c_ofset.i][c_ofset.j].y;
			if (data->map_table[c_ofset.i][c_ofset.j].y > c_ofset.max_y)
				c_ofset.max_y = data->map_table[c_ofset.i][c_ofset.j].y;
			c_ofset.j++;
		}
		c_ofset.i++;
	}
	data->c_offset_x = (c_ofset.win_width - (c_ofset.max_x - c_ofset.min_x)) / 2
		- c_ofset.min_x;
	data->c_offset_y = (c_ofset.win_height - (c_ofset.max_y - c_ofset.min_y))
		/ 2 - c_ofset.min_y;
}

void	ft_map_scale(t_mlx *data, t_point *point)
{
	point->x *= data->scale;
	point->y *= data->scale;
	point->alt *= data->scale;
}
// // Examples of different pointer casts:

// // 1. Function pointer cast
// void (*func)(t_point*) = (void (*)(t_point*))void_ptr;

// // 2. Data pointer cast
// int *number = (int*)void_ptr;

// // 3. Structure pointer cast
// t_point *point = (t_point*)void_ptr;
// int	w;
// int	h;
// w = WIDTH;
// h = HEIGHT;
// while ((data->map_table[0][0].x) < (w
//	- data->map_table[0][data->map_width
// 		- 1].x))
// 	ft_map_resampler(data, map_move_right);
// while ((data->map_table[0][0].y) < (h
//		- data->map_table[data->map_height
// 		- 1][0].y))
// 	ft_map_resampler(data, map_move_down);
