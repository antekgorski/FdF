    char *line;
	line = get_next_line(fd);
	while (line)
	{
		chunks = ft_split(line, ' ');
		free(line);
		line = NULL;
		i = ft_count(chunks);
		row = malloc(sizeof(t_list) * (i + 1));
		i = 0;
		while (chunks[i])
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

char	*get_next_element(char **line)
{
}


// typedef struct s_list
// {
// 	char	*string;

// }			t_list;

// typedef struct s_game
// {
// 	int		scale;
// 	t_list	**map_table;
// }			t_game2;

// void	draw_map(t_game2 *data)
// {
// 	int		n;
// 	int		x;
// 	int		y;
// 	int		scale;
// 	//t_game2	*map;

// 	x = 50;
// 	y = 50;
// 	n = 0;
// 	map = data->map_table;
// 	scale = data->scale;
// 	while (&map[n])
// 	{
// 		if (&map[n + 1] != NULL)
// 			draw_line(x, y, x + (50 * scale), y + (25 + scale));
// 		x += 50 * scale;
// 		y = 25 * scale;
// 		n++;
// 	}
// }