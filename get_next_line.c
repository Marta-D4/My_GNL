/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiaz-e <madiaz-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 11:37:04 by madiaz-e          #+#    #+#             */
/*   Updated: 2025/10/29 14:46:24 by madiaz-e         ###   ########.fr       */
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
		buffer[bytes_r] = '\0';
		if (!leftover)
			leftover = ft_strdup("");
		tmp_line = leftover;
		leftover = ft_strjoin(tmp_line, buffer);
		free(tmp_line);
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
	while (line_b[i] != '\n' && line_b[i] != '\0')
		i++;
	if (line_b[i] == 0)
		return (NULL);
	left = ft_substr(line_b, i + 1, ft_strlen(line_b) - i);
	if (*left == 0)
	{
		free(left);
		left = NULL;
	}
	line_b[i + 1] = 0;
	return (left);
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*line;
	char		*buffer;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	line = fill_line(fd, leftover, buffer);
	free(buffer);
	buffer = NULL;
	if (!line)
	{
		free(leftover);
		leftover = NULL;
		return (NULL);
	}
	leftover = leave_leftover(line);
	return (line);
}

/*int main(void)
{
	int fd = open("texto.txt", O_RDONLY);
	char *linea;

	while ((linea = get_next_line(fd)) != NULL)
	{
		printf("Línea: %s", linea);
		free(linea);
	}

	close(fd);
	return (0);
}*/
