/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:10 by agorski           #+#    #+#             */
/*   Updated: 2024/11/08 19:06:39 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include <math.h>
# include "./libft++/libft.h"
# include "minilibx-linux/mlx.h"

// typedef struct s_color
// {

// }

typedef struct s_mlx
{
	void *mlx_start; //
	void	*mlx_win;
}			t_mlx;


void		drawLine(t_mlx *data, int x0, int y0, int x1, int y1 /*, float r0, float g0, float b0, float r1, float g1, float b1*/);

#endif
