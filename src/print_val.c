# include "ft_printf.h"

void	print_val(t_value val, char specifier, int fd)
{
	if (specifier == 'i' || specifier == 'd')
		ft_putnbr_fd(val.i, fd);
	else if (specifier == 'u')
		ft_putnbr_base_unsigned_fd(val.u, DECIMAL, fd);
	else if (specifier == 'x')
		ft_putnbr_base_unsigned_fd(val.u, HEX_LOWER, fd);
	else if (specifier == 'X')
		ft_putnbr_base_unsigned_fd(val.u, HEX_UPPER, fd);
	else if (specifier == 'c')
		ft_putchar_fd((unsigned char)val.i, fd);
	else if (specifier == 's')
	{
		if (val.s)
			ft_putstr_fd(val.s, fd);
		else
			ft_putstr_fd("(null)", fd);
	}
	else if (specifier == 'p')
	{
		ft_putstr_fd("0x", fd);
		ft_putnbr_base_unsigned_fd((unsigned int)val.p, HEX_LOWER, fd);
	}
}