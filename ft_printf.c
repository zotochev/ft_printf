#include "ft_printf.h"

// cspdiuxX%

void	print_char(char c, int num)
{
	while (num-- > 0)
		write(1, &c, 1);
}

void	format_print_out(t_format *format)
{
	char	fill_symbol;

	if (!format->flag_minus && format->flag_null
	&& ft_strchr("diuxX%", format->type) && (format->arg_length > format->width))
		fill_symbol = '0';
	else if (format->type == '%' && format->flag_null)
		fill_symbol = '0';
	else
		fill_symbol = ' ';
	if (!format->flag_minus)
	{
		if ((format->width > format->arg_length) && format->type == 'p')
			print_char(fill_symbol, format->width - format->arg_length - 2);
		if ((format->width > format->arg_length) && format->type != 'p')
			print_char(fill_symbol, format->width - format->arg_length - format->negative);
	}
	if (format->negative)
		ft_putchar_fd('-', 1);
}

void	format_print_out_after(t_format *format)
{
	char	fill_symbol;

	fill_symbol = ' ';
	if (format->flag_minus)
	{
		if ((format->width > format->arg_length) && format->type == 'p')
			print_char(fill_symbol, format->width - format->arg_length - 2);
		if ((format->width > format->arg_length) && format->type != 'p')
			print_char(fill_symbol, format->width - format->arg_length - format->negative);
	}
}

int format_processor(const char *string, t_format *format, va_list ap)
{
	if (*string)
	{
		*format = new_format_object();
		format_parser(string, format, ap);

		format_print_out(format);
		arg_print_out(format, ap);
		format_print_out_after(format);
		if (format->arg_length > format->width)
			return (format->arg_length + 0);
		else
			return (format->width + 0);
	}
}

int 	ft_printf(const char *string, ...)
{
	int 		sym_printed;
	va_list 	ap;
	t_format	format;

	sym_printed = 0;
	if (!string)
		return (0);
	va_start(ap, string);

	while (*string)
	{
		if (*string == '%')
		{
			sym_printed += format_processor(++string, &format, ap);
			string += format.format_len + 0;
		}
		if (*string)
		{
			ft_putchar_fd(*string, 1);
			sym_printed++;
			string++;
		}
	}
	va_end(ap);
	return (sym_printed);
}