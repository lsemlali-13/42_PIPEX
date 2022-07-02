/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:42:23 by lsemlali          #+#    #+#             */
/*   Updated: 2022/07/02 03:22:15 by lsemlali         ###   ########.fr       */
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
# include "get_next_line/get_next_line.h"
# define BUFFER_SIZE 1
typedef struct s_pipe
{
	int	file1;
	int	file2;
	int	pid1;
	int	pid2;
	int	**fd;
	int id[99];
	int	check;
	int cm;
}	t_pipe;

char	*get_path(char *s, char *cmd);
void	frst_cmd(char **env, int *fd, char *cmd, int file1);
void	next_cmd(char **env, t_pipe *p, int i, char *cmd);
void	last_cmd(char **env, int *fd, char *cmd, int file);
void	put_error(char *s, int h);
int		sea_rch(char *s, int a);
char	*handle_env(char *env[]);
char	*skip_sl(char	*cmd);
char	*get_path(char *s, char *cmd);
void	ft_exit(char *sp[]);
int		here_doc(char *str);

#endif