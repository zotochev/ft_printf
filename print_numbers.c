#include "ft_printf.h"

int ft_numlen(long number, int base)
{
	int number_len;

	number_len = 1;
	while (number /= base)
		number_len++;
	return (number_len);
}

int ft_numlen_p(unsigned long number, int base)
{
	int number_len;

	number_len = 1;
	while (number /= base)
		number_len++;
	return (number_len);
}

unsigned long exp_of_ten(int exp, int base)
{
	long result;

	result = 1;
	while (exp--)
		result *= base;
	return (result);
}

void	put_number_iter(long number, int base, t_format *format)
{
	int 			number_len;
	unsigned long	delimiter;
	long 			temp;

	number_len	= format->arg_length;
	number = (number > 0) ? number : -number;
	delimiter	= exp_of_ten(number_len, base);
	print_char('0', format->precision - format->arg_length + 0); //format->negative
	while (number_len--)
	{
		temp = (((number / (delimiter /= base)) % base));
		if (temp < 10)
			ft_putchar_fd((temp + '0'), 1);
		else
			ft_putchar_fd((temp + format->type - 33), 1);
	}
}

void	print_unsigned_number_iter(unsigned long number, int base, t_format *format)
{
	int 			number_len;
	unsigned long	delimiter;
	unsigned long 	temp;

	number_len	= format->arg_length;
	delimiter	= exp_of_ten(number_len, base);
	ft_putstr_fd("0x", 1);
	print_char('0', format->precision - format->arg_length);
	while (number_len--)
	{
		temp = ((number / (delimiter /= base)) % base);
		if (temp < 10)
			ft_putchar_fd((temp + '0'), 1);
		else
			ft_putchar_fd((temp + 'x' - 33), 1);
	}
}