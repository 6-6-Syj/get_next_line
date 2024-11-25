/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 15:12:31 by jmagand           #+#    #+#             */
/*   Updated: 2024-11-25 15:12:31 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// READ, FREE, MALLOC
char	*get_next_line(int fd)
{
	printf("Ce petit fd....");
	return (0);
}


int main()
{
	int	fd;
	fd = open("test.txt", O_RDONLY);
	get_next_line(fd);
		// O_RDONLY: In read-only mode, open the file.
		// O_WRONLY: In a write-only mode, open the file
    	// O_RDWR: Open the file in reading and write mode
	    // O_CREAT: This flag is applied to create a file if it doesn’t exist in the specified path or directory
		// O_EXCL: Prevents the file creation if it already exists in the directory or location.

	//  ssize_t read(int fildes, void *buf, size_t nbyte);
}
