#include "ft_printf.h"

int	put_char(char c)				// точность и флаг 0 не обрабатываются
{
	write(1, &c, 1);
	return (1);
}

int	put_string(const char *string, t_placeholder *placeholder_values)	// флаг 0 не обрабатывается
{
	int count;
	int len;

	count = 0;
	len = string_len(string);
	if (placeholder_values->precision >= 0)
		len = (len <= placeholder_values->precision) ? len : placeholder_values->precision;
	placeholder_values->width -= len;
	print_width(placeholder_values);
	while (string[count] && placeholder_values->precision--)
		put_char(string[count++]);
	print_width(placeholder_values);
	return (count);
}

int num_len(long number, int base)
{
	int number_len;

	number_len = 1;
	while (number /= base)
		number_len++;
	return (number_len);
}

long exp_of_ten(int exp, int base)
{
	long result;

	result = 1;
	while (exp--)
		result *= base;
	return (result);
}

void	print_width(t_placeholder *placeholder_values)
{
	char	fill_char;

	fill_char = (placeholder_values->flag == '0' && placeholder_values->precision < 0) ? '0' : ' ';
	if (placeholder_values->flag != '-')
		while (placeholder_values->width-- > 0)
			put_char(fill_char);
	else
		placeholder_values->flag = '\0';
}

int	put_number_iter(long number, int base, t_placeholder *placeholder_values)
{
	int 	number_len;
	int 	number_len_return;
	long	delimiter;
	int 	negative;
	int 	temp;

	number_len	= num_len(number, base);
	number_len_return = number_len;
	delimiter	= exp_of_ten(number_len, base);
	negative = number > 0 ? 1 : -1;
	placeholder_values->precision -= number_len;
	if (placeholder_values->precision > 0)
		placeholder_values->width = placeholder_values->width - placeholder_values->precision - number_len - (negative < 0);
	else
		placeholder_values->width = placeholder_values->width - number_len - (negative < 0);
	print_width(placeholder_values);
	if (negative < 0)
		put_char('-');
	while (placeholder_values->precision-- > 0)
		put_char('0');
	while (number_len--)
	{
		temp = ((number / (delimiter /= base)) % base) * negative;
		if (temp < 10)
			put_char(temp + '0');
		else
			put_char(temp + placeholder_values->type - 33);
	}
	print_width(placeholder_values);
	return (number_len_return);
}

int	put_pointer_iter(unsigned long number, int base, t_placeholder *placeholder_values)
{
	int 	number_len;
	int 	number_len_return;				// FIXME не учитывает ширину
	long	delimiter;
	int 	negative;
	int 	temp;

	number_len	= num_len(number, base);	// FIXME функция num_len не умеет работать с unsigned long
	number_len_return = number_len;
	delimiter	= exp_of_ten(number_len, base);
	negative = number > 0 ? 1 : -1;
	placeholder_values->width = placeholder_values->width - number_len - (negative < 0) - 2;
	print_width(placeholder_values);
	write(1, "0x", 2);
	while (placeholder_values->precision-- > 0)
		put_char('0');
	while (number_len--)
	{
		temp = ((number / (delimiter /= base)) % base) * negative;
		if (temp < 10)
			put_char(temp + '0');
		else
			put_char(temp - 10 + 'a');
	}
	print_width(placeholder_values);
	return (number_len_return);
}

int	put_percent_iter(t_placeholder *placeholder_values)
{
	int 	number_len_return;

	number_len_return = 1;

	placeholder_values->width = placeholder_values->width - 1;
	print_width(placeholder_values);
	put_char('%');
	print_width(placeholder_values);
	return (number_len_return);
}
