/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:53:48 by geonlee           #+#    #+#             */
/*   Updated: 2023/01/26 16:32:38 by geonlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	map_init(t_status *status)
{
	status->wd = 0;
	status->player = 0;
	status->move = 0;
	status->collect = 0;
}

void	valid_map(t_status *status, int start, int map_exit)
{
	int	i;

	i = 0;
	while (status->map[i])
	{
		if (i % status->wd == 0 || i % status->wd == status->wd - 1 \
		|| i < status->wd || ft_strlen(status->map) - status->wd <= i)
			if (status->map[i] != '1')
				exit_error("Error\nWrong Map! : not surrounded by walls\n", 1);
		if (status->map[i] == 'P')
			start++;
		else if (status->map[i] == 'C')
			status->collect++;
		else if (status->map[i] == 'E')
			map_exit++;
		else if (status->map[i] != '1' && status->map[i] != '0')
			exit_error("Error\nWrong Map! : unvaild char in map\n", 1);
		i++;
	}
	if (start != 1)
		exit_error("Error\nWrong Map! : multiple/none start point\n", 1);
	if (status->collect == 0)
		exit_error("Error\nWrong Map! : none collectible\n", 1);
	if (map_exit != 1)
		exit_error("Error\nWrong Map! : multiple/none exit\n", 1);
}

void	parse_map(char *file, t_status *status)
{
	int		fd;
	char	*line;
	char	*temp;

	fd = open(file, O_RDONLY);
	line = get_next_line(fd);
	status->wd = ft_strlen(line);
	status->map = line;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = status->map;
		status->map = ft_strjoin(status->map, line);
		free(temp);
		if (status->wd != ft_strlen(line))
			exit_error("Error\nWrong Map! : not rectangle\n", 1);
		if (!status->map)
			exit_error("Error\nfunc \"ft_strjoin\" failed\n", 1);
		free(line);
	}
	if (status->wd < 3 || ft_strlen(status->map) / status->wd < 3)
		exit_error("Error\nWrong Map! : map too small\n", 1);
	valid_map(status, 0, 0);
}

void	setting_img(t_status *s, int i)
{
	int	w;
	int	h;

	while (s->map[i])
	{
		if (s->map[i] == '0')
			mlx_put_image_to_window(s->mlx, s->win, mlx_xpm_file_to_image(s-> \
			mlx, "textures/1.xpm", &w, &h), i % s->wd * 64, i / s->wd * 64);
		if (s->map[i] == '1')
			mlx_put_image_to_window (s->mlx, s->win, mlx_xpm_file_to_image(s-> \
			mlx, "textures/2.xpm", &w, &h), i % s->wd * 64, i / s->wd * 64);
		if (s->map[i] == 'C')
			mlx_put_image_to_window (s->mlx, s->win, mlx_xpm_file_to_image(s-> \
			mlx, "textures/3.xpm", &w, &h), i % s->wd * 64, i / s->wd * 64);
		if (s->map[i] == 'P')
		{
			s->player = i;
			mlx_put_image_to_window (s->mlx, s->win, mlx_xpm_file_to_image(s-> \
			mlx, "textures/4.xpm", &w, &h), i % s->wd * 64, i / s->wd * 64);
		}
		if (s->map[i] == 'E')
			mlx_put_image_to_window (s->mlx, s->win, mlx_xpm_file_to_image(s-> \
			mlx, "textures/5.xpm", &w, &h), i % s->wd * 64, i / s->wd * 64);
		i++;
	}
}
