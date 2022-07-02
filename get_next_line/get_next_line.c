/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:57:20 by lsemlali          #+#    #+#             */
/*   Updated: 2022/07/01 16:52:45 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_f(int fd, char *buff)
{
	int		i;
	int		j;
	char	*line;

	line = NULL;
	if (buff[0] != 0)
		line = str_join(line, buff);
	while (!ft_search(buff))
	{
		j = 0;
		while (buff[j])
			buff[j++] = 0;
		i = read(fd, buff, 1);
		if (i < 0 || (i == 0 && !line))
			return (0);
		line = str_join(line, buff);
		if (i < 1 && line)
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
		line = sub_str(buff, 0, str_len(buff));
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
	char	*line;

	static char	buff[2];

	line = NULL;
	if (fd < 0 || read(fd, buff, 0) < 0)
		return (0);
	line = ft_join(fd, buff);
	return (line);
}
