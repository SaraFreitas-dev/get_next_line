/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:30:43 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/13 18:30:43 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// If BUFFER_SIZE is not defined in the compilation command, use 42
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

// Function to test simultaneous file descriptors
void	test_simultaneous(const char *file1, const char *file2)
{
	int		fd1;
	int		fd2;
	char	*line1;
	char	*line2;
	
	// Open both files
	fd1 = open(file1, O_RDONLY);
	fd2 = open(file2, O_RDONLY);

	if (fd1 < 0 || fd2 < 0)
	{
		perror("Error opening one or both files");
		close(fd1);
		close(fd2);
		return ;
	}

	printf("--- Reading lines alternately ---\n");
	
	// Read and print alternately until both files are finished
	while (1)
	{
		line1 = get_next_line(fd1);
		if (line1)
		{
			printf("FD 1: [%s]", line1);
			free(line1);
		}

		line2 = get_next_line(fd2);
		if (line2)
		{
			printf("FD 2: [%s]", line2);
			free(line2);
		}

		if (!line1 && !line2)
			break ;
	}

	printf("\n--- All files finished ---\n");
	close(fd1);
	close(fd2);
}

int	main(void)
{
	test_simultaneous("text.txt", "text2.txt");

	return (0);
}