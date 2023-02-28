/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:54:57 by geonlee           #+#    #+#             */
/*   Updated: 2023/01/26 16:32:42 by geonlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	search_bfs(t_status *status, t_queue *queue, char **str, int idx)
{
	char	*map;

	map = *str;
	if (0 <= idx && idx < ft_strlen(status->map))
	{	
		if (map[idx] == '0' || map[idx] == 'C')
		{
			map[idx] = 'P';
			append_queue(queue, idx);
		}
		else if (map[idx] == 'E')
			map[idx] = '?';
	}
}

void	bfs(t_status *status)
{
	t_queue	queue;
	char	*map;
	int		i;

	map = ft_strdup(status->map);
	init_queue(&queue);
	append_queue(&queue, status->player);
	while (queue.count != 0)
	{
		i = popleft_queue(&queue);
		search_bfs(status, &queue, &map, i + 1);
		search_bfs(status, &queue, &map, i - 1);
		search_bfs(status, &queue, &map, i + status->wd);
		search_bfs(status, &queue, &map, i - status->wd);
	}
	i = 0;
	while (map[i])
	{
		if (map[i] == 'C' || map[i] == 'E')
			exit_error("Error\nWrong Map! : bfs invalid map\n", 1);
		i++;
	}
	free(map);
}

void	init_queue(t_queue *queue)
{
	queue->front = NULL;
	queue->rear = NULL;
	queue->count = 0;
}

void	append_queue(t_queue *queue, int data)
{
	t_node	*now;

	now = (t_node *)malloc(sizeof(t_node));
	now->data = data;
	now->next = NULL;
	if (queue->count == 0)
	{
		queue->front = now;
	}
	else
	{
		queue->rear->next = now;
	}
	queue->rear = now;
	queue->count++;
}

int	popleft_queue(t_queue *queue)
{
	int		n;
	t_node	*now;

	n = 0;
	if (queue->count == 0)
		return (n);
	now = queue->front;
	n = now->data;
	queue->front = now->next;
	free(now);
	queue->count--;
	return (n);
}
