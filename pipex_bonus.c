/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:12 by lsemlali          #+#    #+#             */
/*   Updated: 2022/07/02 19:57:54 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ex_comm(t_pipe p, int ac, char *av[], char *env[])
{
	int		i;
	int		k;

	k = p.cm;
	if (k == 4)
		ac--;
	i = -1;
	while (++i < ac - 5)
	{
		next_cmd(env, &p, i, av[k++]);
		close(p.fd[i][0]);
		close(p.fd[i][1]);
	}
}

void	f_close(t_pipe p, int k)
{
	int	i;

	i = -1;
	while (++i <= k)
	{
		close(p.fd[i][0]);
		close(p.fd[i][1]);
	}
}

void	child(t_pipe p, int ac, char *av[], char *env[])
{
	int	k;

	k = ac - 5;
	if (p.cm == 3)
		k = ac - 6;
	p.pid1 = fork();
	if (p.pid1 == 0)
	{
		if (p.file1 != -1)
			frst_cmd(env, p.fd[0], av[p.cm], p.file1);
	}
	else
	{
		p.cm++;
		ex_comm(p, ac, av, env);
		p.pid2 = fork();
		if (p.pid2 == 0)
			last_cmd(env, p.fd[k], av[ac - 2], p.file2);
		f_close(p, k);
		while (wait(NULL) != -1)
			;
	}
}

int	main(int ac, char **av, char *env[])
{
	t_pipe	p;
	int		i;

	if (ac < 5)
		put_error("Error : you need at least 4 arguments", 0);
	i = -1;
	p.fd = malloc((ac - 4) * sizeof(int *));
	while (++i < ac - 4)
	{
		p.fd[i] = malloc(2 * sizeof(int));
		pipe(p.fd[i]);
	}
	if (ft_strncmp(av[1], "here_doc\0", 9) == 0)
		p.file1 = here_doc(av[2], &p, av[ac - 1]);
	else
	{
		p.file1 = open(av[1], O_RDONLY);
		p.file2 = open(av[ac - 1], O_RDWR | O_TRUNC | O_CREAT, 0600);
		p.cm = 2;
	}
	if (p.file1 == -1)
		put_error(ft_strjoin(av[1], " : No such file or directory\n"), 1);
	child(p, ac, av, env);
	return (0);
}
