/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:12:10 by agorski           #+#    #+#             */
/*   Updated: 2024/11/07 19:36:11 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct s_mlx
{
	void	*mlx_start;     //
	void	*mlx_win;
}			t_mlx;

# include "minilibx-linux/mlx.h"
# include "./libft++/libft.h"

#endif
