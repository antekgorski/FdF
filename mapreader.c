/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mapreader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:31:10 by agorski           #+#    #+#             */
/*   Updated: 2025/01/09 16:39:59 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

t_list	**append_row(t_list **table, t_list *row)
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

void	ft_read(int fd, t_game2 *data)
{
	char	**line;
	char	*line;
	t_list	*row;
	t_list	**table;
	int		i;

	line = get_next_line(fd);
	while (line)
	{
		line = ft_split(line, ' ');
		free(line);
		line = NULL;
		i = ft_count(line);
		row = malloc(sizeof(t_list) * (i + 1));
		i = 0;
		while (line[i])
		{
			row[i].string = chunks[i];
			free(chunks[i]);
			i++;
		}
		free(chunks); // might be error
		chunks = NULL;
		row[i].string = NULL;
		data->map_table = append_row(table, row);
		line = get_next_line(fd);
	}
}
