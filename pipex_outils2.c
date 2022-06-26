/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_outils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 11:01:02 by lsemlali          #+#    #+#             */
/*   Updated: 2022/06/26 11:07:59 by lsemlali         ###   ########.fr       */
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
	char	*tmp;
	char	*n_cmd;
	int		i;

	sp = ft_split(s, ':');
	i = -1;
	tmp = skip_sl(cmd);
	tmp = ft_strjoin("/", tmp);
	while (sp[++i])
	{
		n_cmd = ft_strjoin(sp[i], tmp);
		if (!access(n_cmd, F_OK) && !access(n_cmd, X_OK))
			return (n_cmd);
		n_cmd = NULL;
	}
	if (n_cmd == NULL && access(cmd, X_OK) == 0)
		return (cmd);
	return (0);
}

char	*handle_env(char *env[])
{
	int	i;

	i = 0;
	while (env[i])
	{
		if (ft_strncmp("PATH", ft_substr(env[i], 0, 4), 4) == 0)
			return (ft_substr(env[i], 5, ft_strlen(env[i]) - 5));
		i++;
	}
	return ("error");
}

void	ft_exit(char *sp[])
{
	if (sp[1] != NULL)
	{
		if (!sp[2])
			exit(1);
		else
			put_error("exit: too many arguments\n", 0);
	}
	else
		exit(1);
}