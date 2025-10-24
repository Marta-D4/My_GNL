/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiaz-e <madiaz-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 14:51:52 by madiaz-e          #+#    #+#             */
/*   Updated: 2025/10/24 11:13:07 by madiaz-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	x;

	x = 0;
	if (!s)
		return (NULL);
	while (s[x])
	{
		if (s[x] == (char)c)
			return ((char *)&s[x]);
		x++;
	}
	if (s[x] == (char)c)
		return ((char *)&s[x]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	x;

	ptr = malloc(ft_strlen(s) + 1);
	x = 0;
	if (!ptr)
		return (NULL);
	while (s[x])
	{
		ptr[x] = s[x];
		x++;
	}
	ptr[x] = 0;
	return (ptr);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		x;
	int		y;
	char	*tmp;

	x = 0;
	y = 0;
	tmp = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!tmp)
		return (NULL);
	while (s1[x])
		tmp[y++] = s1[x++];
	x = 0;
	while (s2[x])
		tmp[y++] = s2[x++];
	tmp[y] = 0;
	return (tmp);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*tmp;
	size_t	x;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	tmp = (char *)malloc(sizeof(char) * len + 1);
	if (!tmp)
		return (NULL);
	x = 0;
	while (x < len)
	{
		tmp[x] = s[start + x];
		x++;
	}
	tmp[x] = 0;
	return (tmp);
}
