#include <stdio.h>
#include <unistd.h>
#include <limits.h>

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (2048);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	long int	n;

	n = 0;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr++ == '-')
		{
			while (ft_isdigit(*nptr))
			{
				n = (n * 10) - (*nptr++ - '0');
				if (n < INT_MIN)
					return (0);
			}
		}
	}
	while (ft_isdigit(*nptr))
	{
		n = (n * 10) + (*nptr++ - '0');
		if (n > INT_MAX)
			return (-1);
	}
	return (n);
}

int main(void)
{
	printf("%d\n", ft_atoi("0000000111"));
	return (0);
}
