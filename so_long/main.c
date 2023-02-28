/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 19:32:47 by geonlee           #+#    #+#             */
/*   Updated: 2023/01/26 16:32:40 by geonlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && (*s1 || *s2))
	{
		if (*s1++ == *s2++)
			continue ;
		else
			return ((int)((unsigned char)*--s1 - (unsigned char)*--s2));
	}
	return (0);
}

void	exit_error(char *str, int n)
{
	perror(str);
	exit(n);
}

void	ft_putnbr(int n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	write(1, &"0123456789"[n % 10], 1);
}

int	exit_game(t_status *status)
{
	mlx_destroy_window(status->mlx, status->win);
	exit(0);
}

int	main(int argc, char **argv)
{	
	int			n;
	t_status	status;

	if (argc != 2)
		exit_error("Error\nToo many arguments or Has no zero argument\n", 1);
	n = 0;
	while (argv[1][n])
		n++;
	if (ft_strncmp(&argv[1][n - 4], ".ber", 4) != 0)
		exit_error("Error\nMap must ending with the .ber\n", 1);
	if (open(argv[1], O_RDONLY) < 0)
		exit_error("Error\nWrong file name\n", 1);
	map_init(&status);
	parse_map(argv[1], &status);
	status.mlx = mlx_init();
	status.win = mlx_new_window(status.mlx, status.wd * 64, \
	ft_strlen(status.map) / status.wd * 64, "geonlee");
	setting_img(&status, 0);
	bfs(&status);
	mlx_key_hook(status.win, &key_press, &status);
	mlx_hook(status.win, 17, 1L << 2, &exit_game, &status);
	mlx_loop(status.mlx);
}
