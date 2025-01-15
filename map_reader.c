/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:31:10 by agorski           #+#    #+#             */
/*   Updated: 2025/01/15 20:46:48 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_point	**append_row(t_point **table, t_point *row)
{
	t_point	**new_argv;
	int		i;

	i = 0;
	while (table && table[i])
		i++;
	new_argv = malloc(sizeof(t_point *) * (i + 2));
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
	if (table != NULL)
		free(table);
	return (new_argv);
}

static void	ft_set_point(t_read *read, size_t row_width)
{
	read->color_p = ft_split(read->point[read->i], ',');
	read->row[read->i].alt = ft_atoi(read->color_p[0]);
	if (ft_count_line(read->color_p) == 2)
		read->row[read->i].color = ft_atoi(read->color_p[1]);
	else
		read->row[read->i].color = 0xFFFFFFFF;
	ft_free_tab((void ***)&read->color_p);
	read->row[read->i].row_width = row_width;
	read->row[read->i].x = read->i;
	read->row[read->i].y = read->j;
	read->i++;
}

void	ft_init_read(t_read *read)
{
	read->line = NULL;
	read->point = NULL;
	read->color_p = NULL;
	read->row = NULL;
	read->tab = NULL;
	read->i = 0;
	read->j = 0;
}

void	ft_read(int fd, t_mlx *data)
{
	t_read	read;

	ft_init_read(&read);
	read.line = get_next_line(fd);
	while (read.line)
	{
		read.point = ft_split(read.line, ' ');
		free(read.line);
		read.line = NULL;
		data->map_width = ft_count_line(read.point);
		read.row = malloc(sizeof(t_point) * (data->map_width));
		read.i = 0;
		while (read.point[read.i])
			ft_set_point(&read, data->map_width);
		ft_free_tab((void ***)&read.point);
		read.tab = append_row(data->map_table, read.row);
		data->map_table = read.tab;
		read.line = get_next_line(fd);
		read.j++;
		data->map_height = read.j;
	}
	free(read.line);
}
