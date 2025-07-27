#include "push_swap.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while(str[i++])
		write(fd, &str[i], 1);
}

int	ft_is_valid_num(char *num)
{
	int	nbr;
	int	i;

	i = 0;
	while (num[i++])
	{
		if (!ft_isdigit(num[i]))
			return (0);
	}
	nbr = ft_itoa(num);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (0);
	return (1);
}

int	ft_parse_error(char *argv)
{
	int	i;

	i = 0;
	while (argv[i++])
	{
		j = i + 1;
		if (!ft_isvalidnum(argv[i]))
			return (0);
		while (argv[j])
		{
			if (argv[i] == argv[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}


int	main(int argc, char **argv)
{
	int	solutions;

	if (argc < 2)
		return (1);
	if (!ft_parse_error(argv[1]) || argc > 2)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	solutions = ft_push_swap(argv[1]);
	ft_putnbr_fd(solutions, 1);
	write(1, "\n", 1);
	return (0);
}

