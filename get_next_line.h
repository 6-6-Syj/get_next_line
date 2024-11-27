/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 15:12:57 by jmagand           #+#    #+#             */
/*   Updated: 2024-11-25 15:12:57 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
#endif
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

// A TEJ
# include <stdio.h>

char	*get_next_line(int fd);
char	*ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_substr(const char *s, unsigned int start, size_t len);
char	*ft_strjoin(const char *s1, const char *s2);
size_t	ft_strlen(const char *s);

#endif
