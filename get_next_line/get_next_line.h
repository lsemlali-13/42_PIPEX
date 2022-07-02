/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsemlali <lsemlali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 19:57:34 by lsemlali          #+#    #+#             */
/*   Updated: 2022/07/01 16:51:28 by lsemlali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFUER_SIZE 1
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*str_join(char *s1, char *s2);
size_t	str_len(const char *s);
int		ft_search(const char *s);
char	*sub_str(char *s, unsigned int start, size_t len);
void	ft_cut(char *buff);

#endif
