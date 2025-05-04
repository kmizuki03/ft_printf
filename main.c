#include "ft_printf.h"

int	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("Hello, %s!\n", "world");
	return (0);
}
