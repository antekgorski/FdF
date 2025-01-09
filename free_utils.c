/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 19:57:58 by agorski           #+#    #+#             */
/*   Updated: 2025/01/09 20:24:18 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_free_tab(void **table)
{
    int	i;

    i = 0;
    while (table && table[i])
    {
        free(table[i]);
        table[i] = NULL;
        i++;
    }
    free(table);
    table = NULL;
}
