/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:41:32 by Loui :)           #+#    #+#             */
/*   Updated: 2022/02/25 00:50:41 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	ft_count_strings(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static int	ft_string_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != 0 && s[len] != c)
		len++;
	return (len);
}

static char	*ft_create_string(const char *s, size_t n)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = malloc((n + 1) * sizeof(char *));
	if (!dest)
		return (NULL);
	while (i < n)
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	free_dbl_ptr(char	**array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	i;
	size_t	string;

	if (s == 0)
		return (NULL);
	i = 0;
	string = ft_count_strings(s, c);
	array = (char **)malloc((string + 1) * sizeof(char *));
	if (!array)
		return (0);
	while (i < string)
	{
		while (*s == c && *s != 0)
			s++;
		array[i] = ft_create_string(s, ft_string_len(s, c));
		if (!array[i++])
		{
			free_dbl_ptr(array);
			return (NULL);
		}
		s = s + ft_string_len(s, c);
	}
	array[i] = 0;
	return (array);
}
