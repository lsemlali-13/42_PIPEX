#include <unistd.h>
#include <stdio.h>
#include "pipex.h"
int main(int ac, char *av[], char *env[])
{
	char *s;
	s = NULL;
	while (1)
	{
		char *buf;
		buf = malloc(6);
		buf[5] = '\0';
		read(0, buf, 5);
		s = ft_strjoin(s, buf);
		fprintf(stderr, "%s\n", s);
	}
}