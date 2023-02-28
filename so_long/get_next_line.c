/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: geonlee <geonlee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 21:04:08 by geonlee           #+#    #+#             */
/*   Updated: 2023/01/16 20:47:30 by geonlee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	return (len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		n;
	int		k;

	n = 0;
	result = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!result)
		return (NULL);
	result[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	if (s1)
	{
		while (s1[n])
		{
			result[n] = s1[n];
			n++;
		}
	}
	k = n;
	n = 0;
	while (s2[n])
	{
		result[k + n] = s2[n];
		n++;
	}
	return (result);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*c_dst;
	char	*c_src;

	c_dst = (char *)dst;
	c_src = (char *)src;
	i = 0;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		c_dst[i] = c_src[i];
		i++;
	}
	return ((void *)c_dst);
}

char	*ft_strdup(const char *s1)
{
	int		slen;
	char	*dup;

	slen = ft_strlen(s1);
	dup = (char *)malloc(slen + 1);
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s1, slen);
	dup[slen] = '\0';
	return (dup);
}

char	*slicing_newline(char *s, int n_idx, int n)
{
	int		idx;
	int		len;
	char	*str;

	idx = -1;
	if (n == 0)
	{
		str = (char *)malloc(n_idx + 1);
		if (!str)
			return (NULL);
		while (idx++ != n_idx - 1)
			str[idx] = s[idx];
		str[idx] = '\0';
		return (str);
	}
	idx = n_idx + 1;
	len = ft_strlen(s);
	str = (char *)malloc(len - idx + 1);
	if (!str)
		return (NULL);
	while (++n + idx != len)
		str[n] = s[idx + n];
	str[n] = '\0';
	return (str);
}
