/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:57:58 by agorski           #+#    #+#             */
/*   Updated: 2025/01/11 18:31:49 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_map(t_mlx *data)
{
	size_t	i;

	i = 0;
	while (i < data->map_height)
	{
		free(data->map_table[i]);
		data->map_table[i] = NULL;
		i++;
	}
	free(data->map_table);
	data->map_table = NULL;
}

void	ft_free_tab(void ***table)
{
	int	i;

	if (table == NULL || *table == NULL)
		return ;
	i = 0;
	while ((*table)[i])
	{
		free((*table)[i]);
		(*table)[i] = NULL;
		i++;
	}
	free(*table);
	*table = NULL;
}
