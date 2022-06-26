/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:49:31 by lsemlali          #+#    #+#             */
/*   Updated: 2021/12/10 11:49:32 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] && s[i] != '\n')
		i++;
	return (i + 1);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len1;
	size_t	len2;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(len1 + len2 + 1);
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i] && i < len1)
		str[j++] = s1[i++];
	i = 0;
	while (s2 && s2[i] && i < len2)
		str[j++] = s2[i++];
	str[j] = 0;
	free (s1);
	return (str);
}

int	ft_search(const char *s)
{
	int		i;
	int		p;

	p = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	else
		str = malloc(len + 1);
	if (str == NULL)
		return (0);
	while (s[i] && i < len)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}

void	ft_cut(char *buff)
{
	int	i;
	int	j;

	i = ft_strlen(buff);
	j = 0;
	while (buff[i])
		buff[j++] = buff[i++];
	while (buff[j])
		buff[j++] = 0;
}
