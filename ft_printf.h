#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>

#define FLAGS "-0"
#define TYPES "cspdiuxX%"

typedef struct	s_placeholder
{
	int		valid;
	char	flag;
	int 	width;
	int 	precision;
	char 	type;
	int 	placeholder_length;
	int 	arg_length;
}				t_placeholder;

/*
** DEBAG
*/
#include <stdio.h>

/*
**	printf
*/
int 			ft_printf(const char *string, ...);
t_placeholder	parser(const char *placeholder, va_list argptr);
void			placeholder_print(t_placeholder *placeholder_values, va_list argptr);
int				placeholder_processor(const char *placeholder, va_list argptr, t_placeholder *placeholder_values);

/*
**	printf_utils
*/
int				ft_atoi(const char *str);
int 			is_int_set(char c, const char *set);
int 			string_len(const char *string);

/*
** parser_utils.c
*/
int 			is_placeholder_valid(const char *placeholder, t_placeholder *placeholder_values);
t_placeholder	new_placeholder(void);
void			get_flag(const char *placeholder, t_placeholder *placeholder_values);
void			get_width(const char *placeholder,
				  t_placeholder *placeholder_values,
				  va_list argptr);
void			get_precision(const char *placeholder,
					  t_placeholder *placeholder_values,
					  va_list argptr);
void			get_type(const char *placeholder,
				 t_placeholder *placeholder_values);
void			get_placeholder_length(const char *placeholder, t_placeholder *placeholder_values);

/*
** placeholder_print_utils.c
*/
int				put_char(char c);
int				put_string(const char *string, t_placeholder *placeholder_values);
int 			num_len(long number, int base);
long 			exp_of_ten(int exp, int base);
void			print_width(t_placeholder *placeholder_values);
int				put_number_iter(long number, int base, t_placeholder *placeholder_values);
int				put_pointer_iter(unsigned long number, int base, t_placeholder *placeholder_values);
int				put_percent_iter(t_placeholder *placeholder_values);
#endif