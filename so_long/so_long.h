/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:32:46 by geonlee           #+#    #+#             */
/*   Updated: 2023/01/26 16:32:36 by geonlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "mlx.h"
# include	<stdio.h>
# include	<stdlib.h>
# include	<fcntl.h>
# include	<unistd.h>

typedef struct s_status
{
	char	*map;
	int		wd;
	int		player;
	int		collect;
	int		move;
	void	*win;
	void	*mlx;
}	t_status;

typedef struct s_node
{
	int				data;
	struct s_node	*next;
}	t_node;

typedef struct s_queue
{
	t_node	*front;
	t_node	*rear;
	int		count;
}	t_queue;

int		key_press(int keycode, t_status *status);
void	ft_bzero(void *s, size_t n);
int		ft_strlen(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strdup(const char *s1);
char	*slicing_newline(char *s, int n_idx, int n);
int		idx_newline(char *s);
char	*rtn_newline(char **line);
char	*read_err(char **line, int read_byte);
char	*get_next_line(int fd);
void	init_queue(t_queue *queue);
void	append_queue(t_queue *queue, int data);
int		popleft_queue(t_queue *queue);
void	exit_error(char *str, int n);
void	map_init(t_status *status);
void	ft_putnbr(int n);
void	valid_map(t_status *status, int start, int map_exit);
void	parse_map(char *file, t_status *status);
void	setting_img(t_status *status, int i);
void	ft_up(t_status *status);
void	ft_down(t_status *status);
void	ft_left(t_status *status);
void	ft_right(t_status *status);
void	search_bfs(t_status *status, t_queue *queue, char **str, int idx);
void	bfs(t_status *status);

#endif