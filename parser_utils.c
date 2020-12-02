#include "ft_printf.h"

int is_placeholder_valid(const char *placeholder, t_placeholder *placeholder_values)
{
	while (*placeholder)
		placeholder++;
	return ((placeholder_values->valid = 1));
}

t_placeholder new_placeholder(void)
{
	t_placeholder new;

	new.valid = 1;
	new.flag = '\0';
	new.width = -1;
	new.precision = -1;
	new.type = '\0';
	new.placeholder_length = 0;
	new.arg_length = 0;
	return (new);
}

void	get_flag(const char *placeholder, t_placeholder *placeholder_values)
{
	if (is_int_set(*placeholder, FLAGS))
		placeholder_values->flag = *placeholder;
}

void	get_width(const char *placeholder,
				  t_placeholder *placeholder_values,
				  va_list argptr)
{
	while (is_int_set(*placeholder, FLAGS) && !is_int_set(*placeholder, TYPES))
		placeholder++;
	if ((*placeholder >= '1' && *placeholder <= '9')
		|| *placeholder == '.'
		|| is_int_set(*placeholder, TYPES))
		placeholder_values->width = ft_atoi(placeholder);
	else if (*placeholder == '*')
	{
		if ((placeholder_values->width = va_arg(argptr, int)) < 0)
		{
			placeholder_values->flag = '-';
			placeholder_values->width *= -1;
		}
	}
	else
		placeholder_values->valid = 0;
}

void	get_precision(const char *placeholder,
					  t_placeholder *placeholder_values,
					  va_list argptr)
{
	while ((is_int_set(*placeholder, FLAGS)
			|| (*placeholder >= '1' && *placeholder <= '9')
			|| *placeholder == '*')
		   && !is_int_set(*placeholder, TYPES))
		placeholder++;
	if (*placeholder == '.')
	{
		placeholder++;
		if (*placeholder >= '1' && *placeholder <= '9')
			placeholder_values->precision = ft_atoi(placeholder);
		else if (*placeholder == '*' && placeholder_values->type != '%')
		{
			if ((placeholder_values->precision = va_arg(argptr, int)) < 0)
				placeholder_values->precision = -1;
			else
				if (placeholder_values->flag == '0')
					placeholder_values->flag = '\0';
		}
	}
}

void	get_type(const char *placeholder,
				 t_placeholder *placeholder_values)
{
	while (!is_int_set(*placeholder, TYPES))
		placeholder++;
	placeholder_values->type = *placeholder;
}

void	get_placeholder_length(const char *placeholder, t_placeholder *placeholder_values)
{
	int count;

	count = 0;
	while (!is_int_set(placeholder[count], TYPES))
		count++;
	placeholder_values->placeholder_length = count + 2;
}