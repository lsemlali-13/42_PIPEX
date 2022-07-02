/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/02 19:57:27 by lsemlali          #+#    #+#             */
/*   Updated: 2022/07/02 19:57:28 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "get_next_line/get_next_line.h"

int	get_file(char *s)
{
	int	pid;
	int	fd[2];

	pipe(fd);
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		ft_putstr_fd(s, fd[1]);
		close(fd[1]);
		exit(0);
	}
	else
	{
		close(fd[1]);
		wait(NULL);
		return (fd[0]);
	}
}

int	here_doc(char *str, t_pipe *p, char *file)
{
	char	*buf;
	char	*s;

	s = NULL;
	(*p).file2 = open(file, O_RDWR | O_APPEND | O_CREAT, 0600);
	(*p).cm = 3;
	buf = get_next_line(0);
	while (buf != NULL)
	{
		buf[ft_strlen(buf)] = 0;
		if (ft_strncmp(buf, str, ft_strlen(buf) - 1) == 0
			&& ft_strlen(buf) - 1 == ft_strlen(str))
			break ;
		s = ft_strjoin(s, buf);
		free(buf);
		buf = get_next_line(0);
	}
	return (get_file(s));
}
