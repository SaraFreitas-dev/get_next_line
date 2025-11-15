/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 22:28:15 by sarfreit          #+#    #+#             */
/*   Updated: 2025/11/15 22:28:15 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// Prepare line for return
char	*ft_line(char *buffer)
{
	char	*line;
	size_t	i;

	i = 0;
	if (!buffer || !buffer[i])
		return (NULL);
	while (buffer[i] && (buffer[i] != '\n'))
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && (buffer[i] != '\n'))
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

// find next line
char	*ft_next(char *buffer)
{
	int		i;
	int		j;
	char	*next_line;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && (buffer[i] != '\n'))
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	next_line = malloc(ft_strlen(buffer) - i + 1);
	if (buffer[i] == '\n')
		i++;
	j = 0;
	while (buffer[i])
		next_line[j++] = buffer[i++];
	next_line[j] = '\0';
	free(buffer);
	return (next_line);
}

char	*ft_free_and_join(char *line, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(line, buffer);
	if (!temp)
	{
		free(line);
		return (NULL);
	}
	free(line);
	return (temp);
}

char	*ft_read_line(int fd, char *line)
{
	int		bytes_read;
	char	*buffer;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!line)
		line = ft_strdup("");
	bytes_read = 1;
	while (line && !ft_strchr(line, '\n') && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			free(line);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		line = ft_free_and_join(line, buffer);
	}
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*line;

	if (fd < 0 || fd >= 4096 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer[fd] = ft_read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}
/*
#include <stdio.h>
int main(void)
{
    int  fd1;
    int  fd2;
    char *line1;
    char *line2;

    fd1 = open("text.txt", O_RDONLY);
    fd2 = open("text2.txt", O_RDONLY);

    if (fd1 < 0 || fd2 < 0)
        return (1);

    line1 = get_next_line(fd1);
    line2 = get_next_line(fd2);

    while (line1 || line2)
    {
        if (line1)
        {
            printf("[FD1] %s", line1);
            free(line1);
            line1 = get_next_line(fd1);
        }
        if (line2)
        {
            printf("[FD2] %s", line2);
            free(line2);
            line2 = get_next_line(fd2);
        }
    }

    close(fd1);
    close(fd2);
    return (0);
}
*/