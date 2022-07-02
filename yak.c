#include "pipex.h"
#include "get_next_line/get_next_line.h"

int	here_doc(char *str)
{
	int fd[2];
	pipe(fd);
	char *buf;
	char *s;
	s = NULL;

	buf = get_next_line(0);
	while (buf != NULL)
	{
		buf[ft_strlen(buf)] = 0;
		if (ft_strncmp(buf, str, ft_strlen(buf) - 1) == 0 && ft_strlen(buf) - 1 == ft_strlen(str))
			break ;
		s = ft_strjoin(s, buf);
		free(buf);
		buf = get_next_line(0);
	}

	int id = fork();
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], s, ft_strlen(s));
		close(fd[1]);
		exit(1);
	}
	else
	{
		close(fd[1]);
		wait(NULL);
		return (fd[0]);
	}
}