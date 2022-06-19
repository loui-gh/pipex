/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 23:04:33 by Loui :)           #+#    #+#             */
/*   Updated: 2022/02/24 23:19:22 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < (n - 1))
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin_mod(char const *s1, char const *s2, size_t lazy)
{
	size_t	j;
	char	*newstring;

	j = 0;
	newstring = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!newstring)
		return (NULL);
	while (s1[lazy] != '\0')
	{
		newstring[j] = s1[lazy];
		lazy++;
		j++;
	}
	newstring[j] = '/';
	j++;
	lazy = 0;
	while (s2[lazy] != '\0')
	{
		newstring[j] = s2[lazy];
		j++;
		lazy++;
	}
	newstring[j] = '\0';
	return (newstring);
}
