#include "ft_printf.h"

void	ft_putstr_precision(char *s, t_format *format)
{
	int precision;

	precision = format->precision;
	if (!s)
		return ;
	while (*s && precision--)
	{
		ft_putchar_fd(*s, 1);
		s++;
	}
}

void	arg_print_out(t_format *format, va_list ap)
{
	if (format->type == 'c')
		ft_putchar_fd(va_arg(ap, int), 1);
	else if (format->type == '%')
		ft_putchar_fd('%', 1);
	else if (format->type == 's')
		ft_putstr_precision(va_arg(ap, char *), format);
	else if (format->type == 'd' || format->type == 'i')
		put_number_iter(va_arg(ap, int), 10, format);
	else if (format->type == 'u')
		put_number_iter(va_arg(ap, unsigned int), 10, format);
	else if (format->type == 'x' || format->type == 'X')
		put_number_iter(va_arg(ap, unsigned int), 16, format);
	else if (format->type == 'p')
		print_unsigned_number_iter(va_arg(ap, unsigned long), 16, format);
}