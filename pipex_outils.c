/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_outils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:10 by lsemlali          #+#    #+#             */
/*   Updated: 2022/06/23 16:46:01 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*skip_sl(char	*cmd)
{
	char	*n_cmd;
	int		i;

	i = ft_strlen(cmd);
	while (i >= 0)
	{
		if (cmd[i] == '/')
			break ;
		i--;
	}
	n_cmd = ft_substr(cmd, i + 1, ft_strlen(cmd) - (i + 1));
	return (n_cmd);
}

char	*get_path(char *s, char *cmd)
{
	char	**sp;
	char	*n_cmd;
	int		i;

	s = ft_substr(s, 5, ft_strlen(s) - 5);
	sp = ft_split(s, ':');
	i = -1;
	cmd = ft_strjoin("/", cmd);
	while (sp[++i])
	{
		n_cmd = ft_strjoin(sp[i], cmd);
		if (access(n_cmd, F_OK) == 0)
			return (n_cmd);
		n_cmd = NULL;
	}
	return (0);
}

void	frst_cmd(char **env, int *fd, char *cmd, int file1)
{
	char	**sp;
	char	*path;

	dup2(file1, 0);
	close(file1);
	sp = ft_split(cmd, ' ');
	sp[0] = skip_sl(sp[0]);
	path = get_path(env[6], sp[0]);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	execve(path, sp, env);
	write(2, "hehe\n", 5);
}

void	next_cmd(char **env, int **fd, int i, char *cmd)
{
	char	**sp;
	char	*path;
	int		id;

	id = fork();
	if (id == 0)
	{
		sp = ft_split(cmd, ' ');
		sp[0] = skip_sl(sp[0]);
		path = get_path(env[6], sp[0]);
		dup2(fd[i][0], 0);
		dup2(fd[i + 1][1], 1);
		close(fd[i + 1][0]);
		close(fd[i + 1][1]);
		close(fd[i][0]);
		close(fd[i][1]);
		execve(path, sp, env);
	}
}

void	last_cmd(char **env, int *fd, char *cmd, int file)
{
	char	**sp;
	char	*path;

	sp = ft_split(cmd, ' ');
	sp[0] = skip_sl(sp[0]);
	path = get_path(env[6], sp[0]);
	dup2(fd[0], 0);
	dup2(file, 1);
	close(fd[0]);
	close(file);
	close(fd[1]);
	execve(path, sp, env);
}
