/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:52:58 by geonlee           #+#    #+#             */
/*   Updated: 2023/01/26 16:32:39 by geonlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_press(int keycode, t_status *status)
{
	if (keycode == 126)
		ft_up (status);
	if (keycode == 125)
		ft_down(status);
	if (keycode == 124)
		ft_right(status);
	if (keycode == 123)
		ft_left(status);
	if (keycode == 53)
		exit(0);
	return (0);
}

void	ft_up(t_status *status)
{
	if (status->player - status->wd >= 0)
	{
		if (status->map[status->player - status->wd] != '1')
		{
			if (status->map[status->player - status->wd] == 'E' \
			&& status->collect == 0)
			{
				write(1, "Congratulation!", 15);
				exit(0);
			}
			if (status->map[status->player - status->wd] == 'E')
				return ;
			if (status->map[status->player - status->wd] == 'C')
				status->collect--;
			status->move++;
			ft_putnbr(status->move);
			write(1, "\n", 1);
			status->map[status->player - status->wd] = 'P';
			status->map[status->player] = '0';
			mlx_clear_window(status->mlx, status->win);
			setting_img(status, 0);
		}
	}
}

void	ft_down(t_status *status)
{
	if (status->player + status->wd <= ft_strlen(status->map))
	{
		if (status->map[status->player + status->wd] != '1')
		{
			if (status->map[status->player + status->wd] == 'E' \
			&& status->collect == 0)
			{
				write(1, "Congratulation!", 15);
				exit(1);
			}
			if (status->map[status->player + status->wd] == 'E')
				return ;
			if (status->map[status->player + status->wd] == 'C')
				status->collect--;
			status->move++;
			ft_putnbr(status->move);
			write(1, "\n", 1);
			status->map[status->player + status->wd] = 'P';
			status->map[status->player] = '0';
			mlx_clear_window(status->mlx, status->win);
			setting_img(status, 0);
		}
	}
}

void	ft_right(t_status *status)
{
	if (status->player + 1 >= 0)
	{
		if (status->map[status->player + 1] != '1')
		{
			if (status->map[status->player + 1] == 'E' && status->collect == 0)
			{
				write(1, "Congratulation!", 15);
				exit(1);
			}
			if (status->map[status->player + 1] == 'E')
				return ;
			if (status->map[status->player + 1] == 'C')
				status->collect--;
			status->move++;
			ft_putnbr(status->move);
			write(1, "\n", 1);
			status->map[status->player + 1] = 'P';
			status->map[status->player] = '0';
			mlx_clear_window(status->mlx, status->win);
			setting_img(status, 0);
		}
	}
}

void	ft_left(t_status *status)
{
	if (status->player - 1 >= 0)
	{
		if (status->map[status->player - 1] != '1')
		{
			if (status->map[status->player - 1] == 'E' && status->collect == 0)
			{
				write(1, "Congratulation!", 15);
				exit(1);
			}
			if (status->map[status->player - 1] == 'E')
				return ;
			if (status->map[status->player - 1] == 'C')
				status->collect--;
			status->move++;
			ft_putnbr(status->move);
			write(1, "\n", 1);
			status->map[status->player - 1] = 'P';
			status->map[status->player] = '0';
			mlx_clear_window(status->mlx, status->win);
			setting_img(status, 0);
		}
	}
}
