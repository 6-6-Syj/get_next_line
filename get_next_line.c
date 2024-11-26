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

char	*set_line(char *line_buf)
{
	size_t	i;
	char	*left_from_buf;

	i = 0;
	while (line_buf[i])
	{
		if (line_buf[i])
		if (line_buf[i] == '\n' && !(line_buf[i + 1]))
			// printf("Test K1 => %s", ft_substr(line_buf, 0, i));
			return (ft_substr(line_buf, 0, i));
		if (line_buf[i] == '\n' && line_buf[i + 1]) // problem about (i + 1),
			// can replace a char to add \0... need to see.
			line_buf[i + 1] = '\0';
		i++;
	}
	printf("Test K2 => %s", ft_substr(line_buf, 0, i));
	i = 0;
	while (line_buf[i])
	{
		// printf("%zu\n", i);
		i++;
	}
	return (ft_strdup(""));
}

// READ, FREE, MALLOC
char	*get_next_line(int fd)
{
	// Recuperer le contenu du buffer et le copy/paste --> *char
	// search '\n', si R, rappeler read ---- si y'a : extraire la ligne ET le '\n'
	// Ensuite clear le *char
	// Variable static --> garde ce qu'il y avait avant dans *char
	static char buf[BUFFER_SIZE + 10];
	char *line_buf;

	// printf("READ 1 = %zd\n", read(fd, buf, BUFFER_SIZE));
	buf[read(fd, buf, BUFFER_SIZE)] = '\0';
	line_buf = buf;
	printf("buf = %s\n", buf);
	// printf("line_buf = %s\n", buf);
	// printf("return read = %zi\n", read(fd, buf, BUFFER_SIZE));
	set_line(line_buf);
	return (0);
}

int main()
{
	int	fd;

	// If there is an error, the function will return -1 as a synonym of failure.
	fd = open("test.txt", O_RDONLY);
	// if (fd == -1)
	// 	return (1);
	get_next_line(fd);
	printf("\n -------------- \n");
	get_next_line(fd);
		// O_RDONLY: In read-only mode, open the file.
		// O_WRONLY: In a write-only mode, open the file
    	// O_RDWR: Open the file in reading and write mode
	    // O_CREAT: This flag is applied to create a file if it doesn’t exist in the specified path or directory
		// O_EXCL: Prevents the file creation if it already exists in the directory or location.

	// fd = close("test.txt");
}
