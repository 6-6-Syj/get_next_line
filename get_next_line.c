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

	// while (line_buf[i] != '\n' || line_buf[i] != '\0')
	// 	i++;
	// if (line_buf[0] == 0 || line_buf[1] == 0)
	// 	return (NULL);
	// left_from_buf = ft_substr(line_buf, i + 1, len - i);
	// if (!left_from_buf)
	// 	return (free(left_from_buf), NULL);
	// line_buf[i + 1] = '\0';
	// printf("left_from_buf => %s", left_from_buf);
	// return (left_from_buf);

	while (line_buf[i])
	{
		if (i <= BUFFER_SIZE && line_buf[i] == '\n')
		{
			if (i == 0)
				left_from_buf = ft_substr(line_buf, i, len - i);
			left_from_buf = ft_substr(line_buf, i + 1, len - i);
			printf("left_from_buf => %s", left_from_buf);
			line_buf[i + 1] = '\0';
			return (left_from_buf);
		}
		i++;
	}
	left_from_buf = ft_strdup(line_buf);
	// printf("left_from_buf => %s", left_from_buf);
	return (left_from_buf);
}

static char	*fill_buffer(int fd, char *left_from_buf, char *buf)
{
	ssize_t	is_read;
	char	*tmp;

	is_read = 1;
	while (is_read > 0)
	{
		is_read = read(fd, buf, BUFFER_SIZE);
		if (is_read == -1)
			return (free(left_from_buf), NULL);
		else if (is_read == 0)
			break;
		buf[is_read] = 0;
		if (!left_from_buf)
			left_from_buf = ft_strdup("");
		tmp = left_from_buf;
		left_from_buf = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break;
	}
	printf("LEFT (FB) = %s", left_from_buf);
	return (left_from_buf);
}

char	*get_next_line(int fd)
{
	// DONE --- Recuperer le contenu du buffer et le copy/paste --> *left_from_buf
	// search '\n', si R, rappeler read ---- si y'a : extraire la ligne ET le '\n'
	// Ensuite clear le *char
	// Variable static --> garde ce qu'il y avait avant dans *char
	static char *left_from_buf;
	char		*buf;
	char		*line_buf;

	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(buf);
		buf = NULL;
		return (NULL);
	}
	if (!buf)
		return (NULL);
	line_buf = fill_buffer(fd, left_from_buf, buf);
	free(buf);
	buf = NULL;
	if (!line_buf)
		return (NULL);
	left_from_buf = set_line(line_buf);
	return (line_buf);
}

int main()
{
	int	fd;

	// If there is an error, the function will return -1 as a synonym of failure.
	fd = open("test.txt", O_RDONLY);
	// if (fd == -1)
	// 	return (1);
	printf("\n1st read = %s", get_next_line(fd));
	printf("\n -------------- \n");
	// get_next_line(fd);
	printf("\n2nd read = %s", get_next_line(fd));
	printf("\n -------------- \n");
	// get_next_line(fd);
	printf("\n3th read = %s", get_next_line(fd));
	printf("\n -------------- \n");
	// get_next_line(fd);
	printf("\n4th  read = %s", get_next_line(fd));
	printf("\n -------------- \n");
	// get_next_line(fd);
	printf("\n5th read = %s", get_next_line(fd));
	printf("\n -------------- \n");
	printf("\n6th read = %s", get_next_line(fd));
	printf("\n -------------- \n");
	printf("\n7th read = %s", get_next_line(fd));
	printf("\n -------------- \n");
		// O_RDONLY: In read-only mode, open the file.
		// O_WRONLY: In a write-only mode, open the file
    	// O_RDWR: Open the file in reading and write mode
	    // O_CREAT: This flag is applied to create a file if it doesn’t exist in the specified path or directory
		// O_EXCL: Prevents the file creation if it already exists in the directory or location.

	// fd = close("test.txt");
}
