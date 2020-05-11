#include "ft_printf.h"

int	main(void)
{
	unsigned int a = 12;
	ft_printf("%d\n", ft_printf("%c|%s|%p|%d|%i|%u|%x|%X|%%\n", 'd', "lol", &a, a, a, a, a, a));
}