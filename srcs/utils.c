#include "pushswap.h"

t_slack	*ft_init_slack(int size)
{
	t_slack	*slack;

	slack = NULL;
	slack = malloc(sizeof(t_slack));
	if (!slack)
		return (NULL);
	slack->size = size;
	slack->lst = NULL;
	return (slack);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		n = -n;
		ft_putchar('-');
		ft_putnbr(n);
	}
	else if (n <= 9)
	{
		ft_putchar(n + '0');
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void	ft_exec_operation(int operation, t_slack *a, t_slack *b)
{
	if (operation == 0)
		swap(a);
	else if (operation == 1)
		swap(b);
	else if (operation == 2)
		swap_a_b(a, b);
	else if (operation == 3)
		push(a, b);
	else if (operation == 4)
		push(b, a);
	else if (operation == 5)
		rotate(a);
	else if (operation == 6)
		rotate(b);
	else if (operation == 7)
		rotate_a_b(a, b);
	else if (operation == 8)
		reverse_rotate(a);
	else if (operation == 9)
		reverse_rotate(b);
	else if (operation == 10)
		reverse_rotate_a_b(a, b);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((s1[i] || s2[i]) && i < n - 1 && (unsigned char)s1[i]
		== (unsigned char)s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
