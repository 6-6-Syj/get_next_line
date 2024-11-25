/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmagand <jmagand@student.42.fr>            #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-25 15:15:25 by jmagand           #+#    #+#             */
/*   Updated: 2024-11-25 15:15:25 by jmagand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	int		i;
	char	temp_c;

	i = 0;
	temp_c = (char) c;
	while (str[i])
	{
		if (str[i] == temp_c)
			return ((char *) &str[i]);
		i++;
	}
	if (str[i] == temp_c)
		return ((char *) &str[i]);
	return (NULL);
}

char	*ft_strdup(const char *s)
{
	size_t	i;
	char	*arr;

	arr = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	i = 0;
	if (arr == NULL)
		return (NULL);
	while (i < ft_strlen(s))
	{
		arr[i] = s[i];
		i++;
	}
	return (arr);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*temp_s;
	size_t	i;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_strdup(""));
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	temp_s = ft_calloc(len + 1, sizeof(char));
	if (temp_s == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		temp_s[i] = s[start + i];
		i++;
	}
	return (temp_s);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*temp_s;

	i = 0;
	temp_s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (temp_s == NULL)
		return (NULL);
	while (s1[i] != '\0')
	{
		temp_s[i] = (char) s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		temp_s[i + j] = (char) s2[j];
		j++;
	}
	temp_s[i + j] = '\0';
	return (temp_s);
}
