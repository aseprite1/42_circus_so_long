/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:46:38 by geonlee           #+#    #+#             */
/*   Updated: 2023/01/17 13:57:04 by geonlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_bzero(void *s, size_t n)
{
	size_t			k;
	unsigned char	*temp;

	k = 0;
	temp = (unsigned char *)s;
	while (k < n)
		temp[k++] = 0;
	return ;
}

int	idx_newline(char *s)
{
	int	idx;

	idx = 0;
	if (!s)
		return (-1);
	while (s[idx])
	{
		if (s[idx] == '\n')
			return (idx);
		idx++;
	}
	return (-2);
}

char	*rtn_newline(char **line)
{
	char	*str;
	char	*tmp;
	int		idx;

	idx = idx_newline(*line);
	str = slicing_newline(*line, idx, 0);
	if (!str)
	{
		free(*line);
		*line = NULL;
		return (NULL);
	}
	tmp = slicing_newline(*line, idx, -1);
	if (!tmp)
	{
		free(*line);
		free(str);
		*line = NULL;
		return (NULL);
	}
	if (line)
		free(*line);
	*line = tmp;
	return (str);
}

char	*read_err(char **line, int read_byte)
{
	char	*tmp;

	if (read_byte == -1 || (read_byte == 0 && *line && **line == '\0'))
	{
		if (*line)
			free(*line);
		*line = NULL;
	}
	else if (read_byte == 0)
	{
		if (*line)
		{
			tmp = ft_strdup(*line);
			free(*line);
			*line = NULL;
			return (tmp);
		}
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	static char	*line;
	char		*tmp;
	ssize_t		read_byte;

	if (fd < 0)
		return (NULL);
	ft_bzero(buffer, BUFFER_SIZE + 1);
	if (idx_newline(line) >= 0)
		return (rtn_newline(&line));
	while (1)
	{
		read_byte = read(fd, buffer, BUFFER_SIZE);
		if (read_byte <= 0)
			return (read_err(&line, read_byte));
		tmp = line;
		line = ft_strjoin(tmp, buffer);
		if (tmp)
			free(tmp);
		if (!line)
			return (NULL);
		ft_bzero(buffer, BUFFER_SIZE + 1);
		if (idx_newline(line) >= 0)
			return (rtn_newline(&line));
	}
}
