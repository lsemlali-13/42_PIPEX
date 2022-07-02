/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:04 by lsemlali          #+#    #+#             */
/*   Updated: 2022/06/30 22:55:12 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_s(t_pipe p, int *fd, char *av[], char *env[])
{
	p.pid1 = fork();
	if (p.pid1 == -1)
		put_error("Error in fork\n", 0);
	if (p.pid1 == 0)
	{
		if (p.file1 != -1)
			frst_cmd(env, fd, av[2], p.file1);
	}
	else
	{
		p.pid2 = fork();
		if (p.pid2 == -1)
			put_error("Error in fork\n", 0);
		if (p.pid2 == 0)
			last_cmd(env, fd, av[3], p.file2);
		close(fd[0]);
		close(fd[1]);
		while (wait(NULL) != -1)
		{
		}
	}
}

int	main(int ac, char *av[], char *env[])
{
	t_pipe	p;
	int		fd[2];

	if (ac != 5)
		put_error("Error : you must input only 4 arguments\n", 0);
	pipe(fd);
	p.file1 = open(av[1], O_RDONLY);
	p.file2 = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0600);
	if (p.file1 == -1)
		put_error(ft_strjoin(av[1], " : No such file or directory\n"), 1);
	child_s(p, fd, av, env);
	return (0);
}
