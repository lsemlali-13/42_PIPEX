/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 12:24:44 by lsemlali          #+#    #+#             */
/*   Updated: 2022/07/02 19:58:43 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	sea_rch(char *s, int a)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != ' ')
	{
		if (s[i] == a)
			return (1);
		i++;
	}
	return (0);
}

void	put_error(char *s, int h)
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
	if (h == 0)
		exit(1);
}
