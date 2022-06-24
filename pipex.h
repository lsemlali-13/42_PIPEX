/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:23 by lsemlali          #+#    #+#             */
/*   Updated: 2022/06/23 16:44:05 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "lbft/libft.h"
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_pipe
{
	int	file1;
	int	file2;
	int	pid1;
	int	pid2;
}	t_pipe;

char	*get_path(char *s, char *cmd);
void	frst_cmd(char **env, int *fd, char *cmd, int file1);
void	next_cmd(char **env, int **fd, int i, char *cmd);
void	last_cmd(char **env, int *fd, char *cmd, int file);

#endif