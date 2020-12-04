#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include "libft/libft.h"
#include <unistd.h>
#include <stdarg.h>

#define FLAGS "-0"
#define TYPES "cspdiuxX%"

typedef struct	s_format
{
	int		valid;
	int		flag_minus;
	int 	flag_null;
	int 	width;
	int 	precision;
	char 	type;
	int 	format_len;
	int 	arg_length;
	int 	negative;
}				t_format;

/*
 * DEBAG
 */
#include <stdio.h>
/*
 * END DEBAG
 */


int 			ft_printf(const char *string, ...);
int 			format_processor(const char *string, t_format *format, va_list ap);
/*
 * arg_print_out
 */
void			arg_print_out(t_format *format, va_list ap);
void			ft_putstr_precision(char *s, t_format *format);
void			print_char(char c, int num);
/*
 * print_numbers
 */
int 			ft_numlen(long number, int base);
int 			ft_numlen_p(unsigned long number, int base);
unsigned long	exp_of_ten(int exp, int base);
void			put_number_iter(long number, int base, t_format *format);
void			print_unsigned_number_iter(unsigned long number, int base, t_format *format);

/*
 * format_parser
 */
t_format		new_format_object(void);
void			get_flag(const char *string, t_format *format);
void			get_width(const char *string, t_format *format, va_list ap);
void			get_precision(const char *string, t_format *format, va_list ap);
void			get_type(const char *string, t_format *format);
void			get_arg_length(t_format *format, va_list ap);
void			format_parser(const char *string, t_format *format, va_list ap);

#endif
