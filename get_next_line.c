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

static char	*set_line(char *line_buf)
{
	size_t	i;
	size_t	len;
	char	*left_from_buf;

	len = ft_strlen(line_buf);
	i = 0;
	while (line_buf[i])
	{
		if (i <= BUFFER_SIZE && line_buf[i] == '\n')
		{
			if (i == 0)
				left_from_buf = ft_substr(line_buf, i, len + 1);
			left_from_buf = ft_substr(line_buf, i + 1, len + 1);
			printf("left_from_buf => %s", left_from_buf);
			return (left_from_buf);
		}
		i++;
	}
	left_from_buf = ft_strdup(line_buf);
	printf("left_from_buf => %s", left_from_buf);
	return (left_from_buf);
}

static char	*fill_line_buffer(int fd, char *left_from_buf, char *buf)
{
	return (0);
}
// READ, FREE, MALLOC
char	*get_next_line(int fd)
{
	// DONE --- Recuperer le contenu du buffer et le copy/paste --> *left_from_buf
	// search '\n', si R, rappeler read ---- si y'a : extraire la ligne ET le '\n'
	// Ensuite clear le *char
	// Variable static --> garde ce qu'il y avait avant dans *char
	static char buf[BUFFER_SIZE + 1];
	char *line_buf;

	// printf("READ 1 = %zd\n", read(fd, buf, BUFFER_SIZE));
	read(fd, buf, BUFFER_SIZE);

	line_buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!line_buf)
		return (free(line_buf), NULL);
	line_buf = buf;

	// printf("line_buf = %s\n", buf);
	// printf("return read = %zi\n", read(fd, buf, BUFFER_SIZE));
	printf("buf = %s\n", buf);
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
	printf("\n -------------- \n");
	get_next_line(fd);
	printf("\n -------------- \n");
	get_next_line(fd);
	printf("\n -------------- \n");
	get_next_line(fd);
	printf("\n -------------- \n");
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
