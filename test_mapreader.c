/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mapreader.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agorski <agorski@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 09:31:10 by agorski           #+#    #+#             */
/*   Updated: 2024/11/09 15:55:48 by agorski          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_panic(char *s, int status)
{
	ft_putstr_fd(s, 2);

	exit(status);
}
typedef struct s_game
{
	int		scale;
	t_list	**map_table;
}			t_game2;

int	ft_count(char **chunks)
{
	int	i;

	i = 0;
	while (chunks[i])
		i++;
	return (i);
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
	while (tablevoid	ft_panic(char *s, int status)
{
	ft_putstr_fd(s, 2);

	exit(status);
}
		new_argv[i] = table[i];
		i++;
	}
	new_argv[i] = row;	
	new_argv[i + 1] = NULL;
	return (new_argv);
}

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

int	ft_count(char **chunks)
{
	int	i;

	i = 0;
	while (chunks[i])
		i++;
	return (i);
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
	char	**chunks;
	char	*line;
	t_list	*row;
	t_list	**table;
	int		i;

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

int	ft_open(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open a file.\n");
		exit(1);
	}
	return (fd);
}


void	read_file(char **av, t_game2 *data)
{
	int	fd;

	fd = ft_open(av[1]);
	ft_read(fd, data);
	close(fd);
}


int	main(int ac, char **av)
{
	t_game2	data;

	if (ac != 2)
		return (ft_error(1, "Error: Input a map in format *.."));
	read_file(av, &data);
	return (0);
}

int	ft_open(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Failed to open a file.\n");
		exit(1);
	}
	return (fd);
}

void	read_file(char **av, t_game2 *data)
{
	int	fd;

	fd = ft_open(av[1]);
	ft_read(fd, data);
	close(fd);
}


int	main(int ac, char **av)
{
	t_game2	data;

	if (ac != 2)
		return (ft_error(1, "Error: Input a map in format *.."));
	read_file(av, &data);
	return (0);
}
