/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:49:48 by lsemlali          #+#    #+#             */
/*   Updated: 2021/12/11 16:58:19 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_f(int fd, char *buff)
{
	int		i;
	int		j;
	char	*line;

	line = NULL;
	if (buff[0] != 0)
		line = ft_strjoin(line, buff);
	while (!ft_search(buff))
	{
		j = 0;
		while (buff[j])
			buff[j++] = 0;
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0 || (i == 0 && !line))
			return (0);
		line = ft_strjoin(line, buff);
		if (i < BUFFER_SIZE && line)
			return (line);
	}
	return (line);
}

char	*ft_join(int fd, char *buff)
{
	char	*line;
	int		i;

	if (ft_search(buff))
	{
		line = ft_substr(buff, 0, ft_strlen(buff));
		if (!line)
			return (NULL);
		ft_cut(buff);
	}
	else
	{
		i = 1;
		line = ft_read_f(fd, buff);
		ft_cut(buff);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	buff[1024][BUFFER_SIZE + 1];

	line = NULL;
	if (fd < 0 || read(fd, buff[fd], 0) < 0 || BUFFER_SIZE <= 0)
		return (0);
	line = ft_join(fd, buff[fd]);
	return (line);
}
