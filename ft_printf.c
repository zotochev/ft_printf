#include "ft_printf.h"

t_placeholder parser(const char *placeholder, va_list argptr)
{
	t_placeholder placeholder_values;

	placeholder_values = new_placeholder();
	if (is_placeholder_valid(placeholder, &placeholder_values))
	{
		get_flag(placeholder, &placeholder_values);
		get_type(placeholder, &placeholder_values);
		get_width(placeholder, &placeholder_values, argptr);
		get_precision(placeholder, &placeholder_values, argptr);
		get_placeholder_length(placeholder, &placeholder_values);
	}
//	printf("\nvalid:		%d\n", placeholder_values.valid);
//	printf("flag:		%c\n", placeholder_values.flag);
//	printf("width:		%d\n", placeholder_values.width);
//	printf("precision:	%d\n", placeholder_values.precision);
//	printf("type:		%c\n", placeholder_values.type);
//	printf("length:		%d\n", placeholder_values.placeholder_length);
	return (placeholder_values);
}

void	placeholder_print(t_placeholder *placeholder_values, va_list argptr)
{
	if (placeholder_values->type == 'c')
		placeholder_values->arg_length = put_char(va_arg(argptr, int));
	else if (placeholder_values->type == 's')
		placeholder_values->arg_length = put_string(va_arg(argptr, char *), placeholder_values);
	else if (placeholder_values->type == 'd'
			|| placeholder_values->type == 'i')
		placeholder_values->arg_length = put_number_iter(va_arg(argptr, int), 10, placeholder_values);
	else if (placeholder_values->type == 'u')
		placeholder_values->arg_length = put_number_iter(va_arg(argptr, unsigned int), 10, placeholder_values);
	else if (placeholder_values->type == 'x'
			|| placeholder_values->type == 'X')
		placeholder_values->arg_length = put_number_iter(va_arg(argptr, unsigned int), 16, placeholder_values);
	else if (placeholder_values->type == 'p')
		placeholder_values->arg_length = put_pointer_iter(va_arg(argptr, unsigned long), 16, placeholder_values);
	else if (placeholder_values->type == '%')
		placeholder_values->arg_length = put_percent_iter(placeholder_values);
}

int placeholder_processor(const char *placeholder, va_list argptr, t_placeholder *placeholder_values)
{
	*placeholder_values = parser(placeholder, argptr);
	placeholder_print(placeholder_values, argptr);
	return (placeholder_values->placeholder_length);
}

int ft_printf(const char *string, ...)
{
	int		count;
	int 	return_value;
	t_placeholder	placeholder_values;
	va_list	argptr;

	count = 0;
	return_value = 0;
	va_start(argptr, string);
	while (*string)
	{
		if (*string == '%')
		{
			string += placeholder_processor(&string[count + 1], argptr, &placeholder_values);
			return_value += placeholder_values.arg_length;
			continue ;
		}
		write(1, string, 1);
		string++;
		return_value++;
	}
	va_end(argptr);
	return (return_value);
}