/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:12 by lsemlali          #+#    #+#             */
/*   Updated: 2022/06/23 16:43:59 by lsemlali         ###   ########.fr       */
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

void	ex_comm(int **fd, int ac, char *av[], char *env[])
{
	t_pipe	p;
	int		i;
	int		k;

	p.file1 = open(av[1], O_RDONLY);
	if (p.file1 == -1)
		put_error(ft_strjoin(av[1], " : No such file or directory"));
	p.pid1 = fork();
	if (p.pid1 == 0)
		frst_cmd(env, fd[0], av[2], p.file1);
	p.file2 = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0600);
	k = 3;
	i = -1;
	while (++i < ac - 5)
	{
		next_cmd(env, fd, i, av[k++]);
		close(fd[i][0]);
		close(fd[i][1]);
	}
	p.pid2 = fork();
	if (p.pid2 == 0)
		last_cmd(env, fd[i], av[ac - 2], p.file2);
}

int	main(int ac, char **av, char *env[])
{
	int	**fd;
	int	i;

	if (ac < 5)
		put_error("Error : you need at least 4 arguments");
	i = -1;
	fd = malloc((ac - 4) * sizeof(int *));
	while (++i < ac - 4)
	{
		fd[i] = malloc(2 * sizeof(int));
		pipe(fd[i]);
	}
	ex_comm(fd, ac, av, env);
	i = -1;
	while (++i < ac - 4)
	{
		close(fd[i][0]);
		close(fd[i][1]);
	}
	while (wait(NULL) != -1)
	{
	}
	return (0);
}
