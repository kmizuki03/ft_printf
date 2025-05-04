#include "ft_printf.h"

int	ft_printf(const char *format, ...);

int	main(void)
{
	ft_printf("Hello%p,!\n", "world");
	return (0);
}
