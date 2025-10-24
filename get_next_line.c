/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiaz-e <madiaz-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:37:04 by madiaz-e          #+#    #+#             */
/*   Updated: 2025/10/24 12:14:13 by madiaz-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*fill_line(int fd, char *leftover, char *buffer)
{
	char	*tmp_line;
	ssize_t	bytes_r;

	bytes_r = 1;
	while (bytes_r > 0)
	{
		bytes_r = read(fd, buffer, BUFFER_SIZE);
		if (bytes_r == -1)
			return (NULL);
		else if (bytes_r == 0)
			break ;
		if (!leftover)
			leftover = ft_strdup("");
		leftover = ft_strjoin(tmp_line, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	return (leftover);
}

static char	*leave_leftover(char *line_b)
{
	char	*left;
	ssize_t	i;

	i = 0;
	while (line_b[i] != '\n' && line_b[i] != '0')
		i++;
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	//Comprobar si fd es valido, limpiar memoria
	line = fill_line(fd, leftover, buffer);
	free(buffer);
	if (!line)
		return (NULL);
	leftover = leave_leftover(line);
	return (line);
}
