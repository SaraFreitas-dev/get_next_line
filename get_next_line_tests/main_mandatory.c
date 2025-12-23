/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mandatory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sarfreit <sarfreit@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 18:26:53 by sarfreit          #+#    #+#             */
/*   Updated: 2025/12/13 18:26:53 by sarfreit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

// Function to run tests on a file
// Function to run tests on a file. Only takes the filename as argument.
void	test_file(const char *filename)
{
	int		fd;
	char	*line;
	int		i;
	
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		perror("Error opening file");
		return ;
	}

	i = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("Line %3d: [%s]", i, line);
		free(line);
		i++;
	}
	
	printf("\n--- End of file reached ---\n");
	close(fd);
}

int	main(void)
{
	// Test 1: Standard File
	printf("TEST 1: Standard File (text.txt) | BUFFER_SIZE = %d\n", BUFFER_SIZE);
	test_file("text.txt"); 
	
	// Test 2: Multiple reads
	printf("TEST 2: File with multiple reads (text2.txt) | BUFFER_SIZE = %d\n", BUFFER_SIZE);
	test_file("text2.txt");
	
	return (0);
}