
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*con_cat(char *p, const char *s1, const char *s2)
{	
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (s1[y])
	{
		p[x] = s1[y];
		x++;
		y++;
	}
	y = 0;
	while (s2[y])
	{
		p[x] = s2[y];
		x++;
		y++;
	}
	p[x] = '\0';
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;
	int		y;

	if (!s1 || !s2)
		return (0);
	y = ft_strlen(s1) + ft_strlen(s2);
	p = malloc(y + 1);
	if (p == NULL)
		return (0);
	p = con_cat(p, (char *)s1, (char *)s2);
	return (p);
}


int main(int ac, char **av)
{
	while (1)
	{
		int fd[2];
		char *s;
		pipe(fd);
		dup2(fd[1], 1);
		read(fd[0], s, 2222);
		close(fd[0]);
		close(fd[1]);
		fprintf(stderr, "%s\n", s);
	}
}