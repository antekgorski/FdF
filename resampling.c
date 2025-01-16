/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resampling.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 12:12:16 by agorski           #+#    #+#             */
/*   Updated: 2025/01/16 15:29:08 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_resampling(t_mlx *data)
{
	// ft_printf(" after take center\n");
	// ft_map_test(data);
	ft_map_scale(data);
	ft_map_center(data);
	// ft_printf(" after take scale\n");
	// ft_map_test(data);
}
