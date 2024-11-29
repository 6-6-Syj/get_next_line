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

// char	*empty_line(char *left_buf)
// {
// 	char	*tmp;
// 	size_t	len;
// 	size_t	i;

// 	len = ft_strlen(left_buf);
// 	i = 0;
// 	while (left_buf[i])
// 	{
// 		while (left_buf[i] != '\n' && left_buf[i])
// 			i++;
// 		while (left_buf[len] != '\n' && left_buf[len])
// 			len--;
// 		if (i != len)
// 		{
// 			if (i == 0)
// 				tmp = ft_substr(left_buf, i, len - i);
// 			tmp = ft_substr(left_buf, i + 1, len - i);
// 			return (tmp);
// 		}
// 		i++;
// 	}
// 	return (NULL);
// }

static char	*set_line(char *line_buf)
{
	size_t	i;
	size_t	len;
	char	*left_buf;

	len = ft_strlen(line_buf);
	i = 0;

	// while (line_buf)
	// 	empty_line(line_buf);
	if (line_buf[i] == 0 || line_buf[1] == 0)
        return (NULL);
	while (line_buf[i])
	{
		if (line_buf[i] == '\n')
		{
			if (i == 0)
				left_buf = ft_substr(line_buf, i, len - i);
			left_buf = ft_substr(line_buf, i + 1, len - i);
			if (!left_buf)
				return (free(left_buf), NULL);
			line_buf[i + 1] = '\0';
			return (left_buf);
		}
		i++;
	}
	left_buf = ft_substr(line_buf, i, len - i);
	return (left_buf);
}

static char	*fill_buffer(int fd, char *left_buf, char *buf)
{
	ssize_t	is_read;
	char	*tmp;

	is_read = 1;
	while (is_read > 0)
	{
		is_read = read(fd, buf, BUFFER_SIZE);
		if (is_read == -1)
			return (free(left_buf), NULL);
		else if (is_read == 0)
			break ;
		if (!left_buf)
			left_buf = ft_strdup("");
		tmp = left_buf;
		buf[is_read] = '\0';
		left_buf = ft_strjoin(tmp, buf);
		free(tmp);
		tmp = NULL;
		if (ft_strchr(buf, '\n'))
			break ;
			// return (set_line(left_buf));
	}
	// printf("LEFT (FB) = %s", left_buf);
	return (left_buf);
}


char	*get_next_line(int fd)
{
	static char *left_buf;
	char		*line_buf;
	char		*buf;

	buf = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buf)
		return (free(buf), NULL);
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (free(buf), NULL);
	line_buf = fill_buffer(fd, left_buf, buf);
	free(buf);
	// buf = NULL;
	if (!line_buf)
		return (free(line_buf), NULL);
	left_buf = set_line(line_buf);
	return (line_buf);
}

// int main()
// {
// 	int	fd;
// 	char *next_line;

// 	fd = open("test.txt", O_RDONLY);

// 	next_line = malloc(1);
// 	next_line[0] = '\0';
// 	if (fd == -1)
// 		return (1);
// 	while (next_line != NULL)
// 	{
// 		next_line = get_next_line(fd);
// 		printf("\n\nLine = %s", next_line);
// 		printf("\n -------------- \n");
// 	}

// 	close(fd);
// 	return (0);
// }
