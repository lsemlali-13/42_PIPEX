/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:04 by lsemlali          #+#    #+#             */
/*   Updated: 2022/06/23 16:43:53 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	put_error(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(2, &s[i], 1);
		i++;
	}
	exit(1);
}

int	main(int ac, char *av[], char *env[])
{
	t_pipe	p;
	int		fd[2];

	if (ac != 5)
		put_error("Error : you must input only 4 arguments");
	pipe(fd);
	p.file1 = open(av[1], O_RDONLY);
	if (p.file1 == -1)
		put_error(ft_strjoin(av[1], " : No such file or directory"));
	p.pid1 = fork();
	if (p.pid1 == -1)
		put_error("Error in fork\n");
	if (p.pid1 == 0)
		frst_cmd(env, fd, av[2], p.file1);
	p.pid2 = fork();
	if (p.pid1 == -1)
		put_error("Error in fork\n");
	p.file2 = open(av[4], O_RDWR | O_TRUNC | O_CREAT, 0600);
	if (p.pid2 == 0)
		last_cmd(env, fd, av[3], p.file2);
	close(fd[0]);
	close(fd[1]);
	while (wait(NULL) != -1)
	{
	}
}
