/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 13:58:57 by mohaben-          #+#    #+#             */
/*   Updated: 2025/02/03 11:46:37 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_check_arg_and_get_fd(int ac, char *file)
{
	int	fd;

	if (ac != 2)
		p_exit("Invalid number of arguments!\n");
	if (ft_strncmp(file + ft_strlen(file) - 4, ".fdf", 4))
		p_exit("Need a file in format *.fdf!\n");
	fd = open(file, O_RDONLY);
	if (fd == -1)
		p_exit("File don't exist or unvalid permissions!\n");
	return (fd);
}

void	ft_get_width(char *file, int fd, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	if (line == NULL)
		p_exit("No data found!\n");
	map->width = count_words(line);
	while (line)
	{
		if (count_words(line) != map->width)
		{
			free(line);
			p_exit("Found wrong line length!");
		}
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fd = open(file, O_RDONLY);
}

void	ft_get_width_height(char *file, int fd, t_map *map)
{
	char	*line;

	map->height = 0;
	ft_get_width(file, fd, map);
	line = get_next_line(fd);
	while (line)
	{
		map->height++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	fd = open(file, O_RDONLY);
}

void	ft_handle_z_color(char *source, t_point *point)
{
	int		i;
	char	*str;

	if (!ft_strchr(source, ','))
	{
		point->z = ft_atoi(source);
		point->color = -1;
	}
	else
	{
		i = 0;
		while (source[i] && source[i] != ',')
			i++;
		str = ft_substr(source, 0, i);
		point->z = ft_atoi(str);
		free(str);
		i++;
		str = ft_substr(source, i, ft_strlen(source) - i);
		point->color = ft_atoi_hex(str);
		free(str);
	}
}
