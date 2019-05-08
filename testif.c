#include <unistd.h>

void	ft_putnbr(int n)
{
	char c;

	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n == -2147483648)
	{
		write(1, "2", 1);
		n %= 1000000000;
		n = -n;
	}
	if (n > 9)
		ft_putnbr(n / 10);
	c = n % 10 + '0';
	write(1, &c, 1);
}

void	ft_putstr(char const *s)
{
	int i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

int     intzero()
{
    return (0);
}

int     intone()
{
    return (1);
}

int     main()
{
    int     i = 1;
    int     max = 5;

    while ((i = intzero()) && max > 0)
    {
        ft_putstr("zero");
		ft_putstr(" ");
		ft_putnbr(max);
		ft_putstr(" ");
		max--;
    }
    while ((i = intone()) && max > 0)
    {
        ft_putstr("one");
		ft_putstr(" ");
		ft_putnbr(max);
		ft_putstr(" ");
		max--;
    }
    return (0);
}
