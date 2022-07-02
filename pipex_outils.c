/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:10 by lsemlali          #+#    #+#             */
/*   Updated: 2022/07/02 19:58:29 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ex_ecu(char *cmd, char *path, char *sp[], char *env[])
{
	if (execve(path, sp, env) == -1)
	{
		put_error(cmd, 1);
		if (sea_rch(cmd, '/'))
			put_error(" : No such file or directory\n", 1);
		else
			put_error(" : Command not found\n", 1);
		exit(1);
	}	
}

void	frst_cmd(char **env, int *fd, char *cmd, int file1)
{
	char	**sp;
	char	*path;

	close(fd[0]);
	sp = ft_split(cmd, ' ');
	if (ft_strncmp(sp[0], "exit", 4) == 0 && ft_strlen(sp[0]) == 4)
		ft_exit(sp);
	path = get_path(handle_env(env), sp[0]);
	dup2(file1, 0);
	dup2(fd[1], 1);
	close(fd[1]);
	close(file1);
	ex_ecu(cmd, path, sp, env);
}

void	next_cmd(char **env, t_pipe *p, int i, char *cmd)
{
	char	**sp;
	char	*path;

	(*p).id[i] = fork();
	if ((*p).id[i] == 0)
	{
		close((*p).fd[i + 1][0]);
		close((*p).fd[i][1]);
		sp = ft_split(cmd, ' ');
		if (ft_strncmp(sp[0], "exit", 4) == 0 && ft_strlen(sp[0]) == 4)
			ft_exit(sp);
		sp[0] = skip_sl(sp[0]);
		path = get_path(handle_env(env), sp[0]);
		dup2((*p).fd[i][0], 0);
		dup2((*p).fd[i + 1][1], 1);
		close((*p).fd[i + 1][1]);
		close((*p).fd[i][0]);
		ex_ecu(cmd, path, sp, env);
	}
}

void	last_cmd(char **env, int *fd, char *cmd, int file)
{
	char	**sp;
	char	*path;

	close(fd[1]);
	sp = ft_split(cmd, ' ');
	if (ft_strncmp(sp[0], "exit", 4) == 0 && ft_strlen(sp[0]) == 4)
		ft_exit(sp);
	sp[0] = skip_sl(sp[0]);
	path = get_path(handle_env(env), sp[0]);
	dup2(fd[0], 0);
	dup2(file, 1);
	close(fd[0]);
	close(file);
	ex_ecu(cmd, path, sp, env);
}
