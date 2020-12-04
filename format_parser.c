#include "ft_printf.h"

t_format new_format_object(void)
{
	t_format new;

	new.valid		= 1;
	new.flag_minus	= 0;
	new.flag_null	= 0;
	new.width		= 0;
	new.precision	= -1;
	new.type		= '\0';
	new.format_len	= 0;
	new.arg_length	= 0;
	new.negative	= 0;
	return (new);
}

void	get_flag(const char *string, t_format *format)
{
	int count;

	count = 0;
	while (*string && ft_strchr(FLAGS, *string))
	{
		if (*string == '-')
			format->flag_minus = 1;
		if (*string == '0')
			format->flag_null = 1;
		string++;
		count++;
	}
	format->format_len += count;
}

void	get_width(const char *string, t_format *format, va_list ap)
{
	int count;

	count = 0;
	if (*string >= '0' && *string <= '9')
		format->width = ft_atoi(string);
	else if (*string == '*')
		format->width = va_arg(ap, int);
	while (*string && ((*string >= '0' && *string <= '9') || *string == '*'))
	{
		count++;
		string++;
	}
	if (format->width < 0)
	{
		format->flag_minus = 1;
		format->width = -format->width;
	}
	format->format_len += count;
}

void	get_precision(const char *string, t_format *format, va_list ap)
{
	int count;

	count = 0;
	if (*string++ == '.')
	{
		count++;
		if (*string >= '0' && *string <= '9')
			format->precision = ft_atoi(string);
		else if (*string == '*')
			format->precision = va_arg(ap, int);
		while (*string && ((*string >= '0' && *string <= '9') || *string == '*'))
		{
			count++;
			string++;
		}
	}
	format->format_len += count;
}

void	get_type(const char *string, t_format *format)
{
	if (*string && ft_strchr(TYPES, *string))
		format->type = *string;
	format->format_len += 1;
}

void	get_arg_length(t_format *format, va_list ap)
{
	va_list ap_copy;

	va_copy(ap_copy, ap);
	if (format->type == 'c' || format->type == '%')
		format->arg_length = 1;
	else if (format->type == 's')
		format->arg_length = ft_strlen(va_arg(ap_copy, char *));
	else if (format->type == 'd' || format->type == 'i')
		format->arg_length = ft_numlen(va_arg(ap_copy, int), 10);
	else if (format->type == 'u')
		format->arg_length = ft_numlen(va_arg(ap_copy, unsigned int), 10);
	else if (format->type == 'x' || format->type == 'X')
		format->arg_length = ft_numlen(va_arg(ap_copy, unsigned int), 16);
	else if (format->type == 'p')
		format->arg_length = ft_numlen_p(va_arg(ap_copy, unsigned long), 16);
}

void	arg_length_correction(t_format *format, va_list ap)
{
	(void)ap;
	va_list ap_copy;

	va_copy(ap_copy, ap);
	if (va_arg(ap_copy, int) < 0)
	{
		if (format->type == 'd' || format->type == 'i')
		{
			format->negative = 1;
		}
	}
	if ((ft_strchr("pdiuxX", format->type)))
	{
		if (format->arg_length < format->precision)
			format->arg_length = format->precision;
	}
	if ((ft_strchr("s", format->type)))
	{
		if ((format->arg_length > format->precision) && format->precision >= 0)
			format->arg_length = format->precision;
	}
}

void	format_parser(const char *string, t_format *format, va_list ap)
{
	get_flag(string + format->format_len, format);
	get_width(string + format->format_len, format, ap);
	get_precision(string + format->format_len, format, ap);
	get_type(string + format->format_len, format);
	get_arg_length(format, ap);
	arg_length_correction(format, ap);
}