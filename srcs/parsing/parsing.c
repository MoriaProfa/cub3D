/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: astehl <astehl@student.42vienna.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 21:52:58 by astehl            #+#    #+#             */
/*   Updated: 2026/04/21 19:49:06 by astehl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	*ensure_buf_capacity(char *buf, size_t *size, size_t needed)
{
	size_t	old_size;
	char	*new_buf;

	if (*size < needed)
	{
		old_size = *size;
		while (*size <= needed)
			*size *= 2;
		new_buf = grow_array(buf, old_size, *size, sizeof(char));
		if (!new_buf)
		{
			free(buf);
			return (NULL);
		}
		buf = new_buf;
	}
	return (buf);
}

static char	*read_into_buffer(int fd)
{
	char	*buf;
	char	tmp[1024];
	size_t	buf_size;
	size_t	total;
	ssize_t	nb_read;

	buf_size = 1024;
	total = 0;
	buf = ft_calloc(buf_size, sizeof(char));
	if (!buf)
		return (NULL);
	nb_read = read(fd, tmp, sizeof(tmp));
	while (nb_read > 0)
	{
		buf = ensure_buf_capacity(buf, &buf_size, total + nb_read + 1);
		if (!buf)
			return (NULL);
		ft_memcpy(buf + total, tmp, nb_read);
		total += nb_read;
		nb_read = read(fd, tmp, sizeof(tmp));
	}
	if (nb_read < 0)
		return (free(buf), NULL);
	buf[total] = '\0';
	return (buf);
}

static void	add_game_config_data(t_game *game, char *line)
{
	int	i;

	i = 0;
	checks_complete(game);
	while (line[i] == ' ')
		i++;
	if (line[i + 1] == '\0' && !game->checks.complete)
		return ;
	else if (line[i] == 'N' && line[i + 1] == 'O' && line[i + 2] == ' ')
		check_and_add_path(game, &line[i + 3], 'N');
	else if (line[i] == 'E' && line[i + 1] == 'A' && line[i + 2] == ' ')
		check_and_add_path(game, &line[i + 3], 'E');
	else if (line[i] == 'S' && line[i + 1] == 'O' && line[i + 2] == ' ')
		check_and_add_path(game, &line[i + 3], 'S');
	else if (line[i] == 'W' && line[i + 1] == 'E' && line[i + 2] == ' ')
		check_and_add_path(game, &line[i + 3], 'W');
	else if (line[i] == 'F' && line[i + 1] == ' ')
		convert_and_add_color(game, &line[i + 2], 'F');
	else if (line[i] == 'C' && line[i + 1] == ' ')
		convert_and_add_color(game, &line[i + 2], 'C');
}

static void	extract_data(t_game *game, char *buf)
{
	int	i;

	i = -1;
	game->data = ft_split(buf, '\n');
	if (!game->data)
	{
		free(buf);
		error_exit(game, "Game data memory allocation (split) failed\n");
	}
	game->map.data = ft_split(find_map_start(buf), '\n');
	free(buf);
	if (!game->map.data)
		error_exit(game, "Map data memory allocation (split) failed\n");
	while (game->data[++i])
		add_game_config_data(game, game->data[i]);
	if (!game->checks.complete)
		error_exit(game, "Game config data incorrect/incomplete\n");
}

void	read_extract_and_validate_file(t_game *game, char *fn)
{
	int		fl;
	int		fd;
	char	*buf;

	fl = ft_strlen(fn);
	if (fl < 5 || fn[fl - 5] == '/' || ft_strncmp(&fn[fl - 4], ".cub", 5) != 0)
		error_exit(game, "Invalid filename\n");
	fd = open(fn, O_RDONLY);
	if (fd < 0)
		(perror("Error\nOpening file failed"), exit(1));
	buf = read_into_buffer(fd);
	close(fd);
	if (!buf)
		error_exit(game, "Buffer memory allocation failed\n");
	if (ft_strlen(buf) < 61)
		(free(buf), error_exit(game, "File is empty/too small\n"));
	first_validity_check_map(game, find_map_start(buf), buf);
	extract_data(game, buf);
	second_validity_check_map(game);
	check_player(game);
}
