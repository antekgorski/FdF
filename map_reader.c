/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:31:10 by agorski           #+#    #+#             */
/*   Updated: 2025/01/09 20:27:24 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_map(t_game2 *data)
{
	int		n;
	int		x;
	int		y;
	int		scale;
	t_list	*array;

	x = 50;
	y = 50;
	n = 0;
	array = data->map_table;
	scale = data->scale;
	while (&array[n])
	{
		if (&array[n + 1] != NULL)
			draw_line(x, y, x + (50 * scale), y + (25 + scale));
		x += 50 * scale;
		y = 25 * scale;
		n++;
	}
}

static t_list	**append_row(t_list **table, t_list *row)
{
	t_list	**new_argv;
	int		i;

	i = 0;
	while (table && table[i])
		i++;
	new_argv = malloc(sizeof(t_list *) * (i + 2));
	if (new_argv == NULL)
		ft_panic("malloc", 1);
	i = 0;
	while (table && table[i])
	{
		new_argv[i] = table[i];
		i++;
	}
	new_argv[i] = row;
	new_argv[i + 1] = NULL;
	return (new_argv);
}

static void	ft_set_point(char **color_p, char **point, t_tab_point *row, int i)
{
	color_p = ft_split(point[i], ',');
	row[i].alt = ft_atoi(point[i]);
	if (ft_count(color_p) == 2)
		row[i].color = ft_atoi(color_p[1]);
	else
		row[i].color = 0xFFFFFF;
}

void	ft_read(int fd, t_mlx *data)
{
	t_read	read;

	read.line = get_next_line(fd);
	while (read.line)
	{
		read.point = ft_split(read.line, ' ');
		free(read.line);
		read.line = NULL;
		read.i = ft_count(read.point);
		read.row = malloc(sizeof(t_tab_point) * (read.i + 1));
		read.i = 0;
		while (read.point[read.i])
		{
			ft_set_point(read.color_p, read.point, read.row, read.i);
			read.i++;
		}
		ft_free_tab((void **)read.point);
		ft_free_tab((void **)read.color_p);
		read.tab = append_row(data->map->map_table, read.row);
		free(read.row);
		ft_free_tab((void **)data->map->map_table);
		data->map->map_table = read.tab;
		ft_free_tab((void **)read.tab);
		read.line = get_next_line(fd);
	}
}
