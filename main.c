#include "ft_printf.h"
//cspdiuxX%

int main()
{
//	char	*s = "hello";
//	int 	n = 123456;
	int 	sym = 0;

//	sym = printf("|%c|-|%15p|---|%s|-|%%|-|%d|-|%x|-|%X| >", 'R', s, s, n, n, n);
//	printf("%d<\n", sym);
//	sym = ft_printf("|%c|-|%15p|---|%s|-|%%|-|%d|-|%x|-|%X| >", 'R', s, s, n, n, n);
//	printf("%d<\n", sym);
	sym = ft_printf(NULL);

//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	int sign = 1;
//	int w_sign = 1;
//	int p_sign = 1;
//
//	printf("\n[NUMBERS w PRE]\n\n");
//	printf("|%*.*d|\n", 7 * w_sign, 4 * p_sign, 1234567890 * sign);
//	ft_printf("|%*.*d|\n", 7 * w_sign, 4 * p_sign, 1234567890 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%*.*d|\n", 4 * w_sign, 7 * p_sign, 1234567890 * sign);
//	ft_printf("|%*.*d|\n", 4 * w_sign, 7 * p_sign, 1234567890 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%*.*d|\n", 10 * w_sign, 4 * p_sign, 123456 * sign);
//	ft_printf("|%*.*d|\n", 10 * w_sign, 4 * p_sign, 123456 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%*.*d|\n", 10 * w_sign, 7 * p_sign, 1234 * sign);
//	ft_printf("|%*.*d|\n", 10 * w_sign, 7 * p_sign, 1234 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%*.*d|\n", 4 * w_sign, 10 * p_sign, 123456 * sign);
//	ft_printf("|%*.*d|\n", 4 * w_sign, 10 * p_sign, 123456 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%*.*d|\n", 7 * w_sign, 10 * p_sign, 1234 * sign);
//	ft_printf("|%*.*d|\n", 7 * w_sign, 10 * p_sign, 1234 * sign);
//	printf("~~~~~~~~~\n");
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	int sign = 1;
//	int w_sign = 1;
//	int p_sign = 1;
//
//	printf("\n[NUMBERS w PRE and 0]\n\n");
//	printf("|%0*.*d|\n", 7 * w_sign, 4 * p_sign, 1234567890 * sign);
//	ft_printf("|%0*.*d|\n", 7 * w_sign, 4 * p_sign, 1234567890 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%0*.*d|\n", 4 * w_sign, 7 * p_sign, 1234567890 * sign);
//	ft_printf("|%0*.*d|\n", 4 * w_sign, 7 * p_sign, 1234567890 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%0*.*d|\n", 10 * w_sign, 4 * p_sign, 123456 * sign);
//	ft_printf("|%0*.*d|\n", 10 * w_sign, 4 * p_sign, 123456 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%0*.*d|\n", 10 * w_sign, 7 * p_sign, 1234 * sign);
//	ft_printf("|%0*.*d|\n", 10 * w_sign, 7 * p_sign, 1234 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%0*.*d|\n", 4 * w_sign, 10 * p_sign, 123456 * sign);
//	ft_printf("|%0*.*d|\n", 4 * w_sign, 10 * p_sign, 123456 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%0*.*d|\n", 7 * w_sign, 10 * p_sign, 1234 * sign);
//	ft_printf("|%0*.*d|\n", 7 * w_sign, 10 * p_sign, 1234 * sign);
//	printf("~~~~~~~~~\n");
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	int sign = 1;
//	int w_sign = 1;
//
//	printf("\n[NUMBERS wo PRE]\n\n");
//	printf("|%0*d|\n", 7 * w_sign, 1234567890 * sign);
//	ft_printf("|%0*d|\n", 7 * w_sign, 1234567890 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%0*d|\n", 4 * w_sign, 1234567890 * sign);
//	ft_printf("|%0*d|\n", 4 * w_sign, 1234567890 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%0*d|\n", 10 * w_sign, 123456 * sign);
//	ft_printf("|%0*d|\n", 10 * w_sign, 123456 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%0*d|\n", 10 * w_sign, 1234 * sign);
//	ft_printf("|%0*d|\n", 10 * w_sign, 1234 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%0*d|\n", 4 * w_sign, 123456 * sign);
//	ft_printf("|%0*d|\n", 4 * w_sign, 123456 * sign);
//	printf("~~~~~~~~~\n");
//	printf("|%0*d|\n", 7 * w_sign, 1234 * sign);
//	ft_printf("|%0*d|\n", 7 * w_sign, 1234 * sign);
//	printf("~~~~~~~~~\n");
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//	printf("\n[STRINGS]\n\n");
//	printf("|%*.*s|\n", 7 * w_sign, 4, "1234567890");
//	ft_printf("|%*.*s|\n", 7 * w_sign, 4, "1234567890");
//	printf("~~~~~~~~~\n");
//	printf("|%*.*s|\n", 4 * w_sign, 7, "1234567890");
//	ft_printf("|%*.*s|\n", 4 * w_sign, 7, "1234567890");
//	printf("~~~~~~~~~\n");
//	printf("|%*.*s|\n", 10 * w_sign, 4, "123456");
//	ft_printf("|%*.*s|\n", 10 * w_sign, 4, "123456");
//	printf("~~~~~~~~~\n");
//	printf("|%*.*s|\n", 10 * w_sign, 7, "1234");
//	ft_printf("|%*.*s|\n", 10 * w_sign, 7, "1234");
//	printf("~~~~~~~~~\n");
//	printf("|%*.*s|\n", 4 * w_sign, 10, "123456");
//	ft_printf("|%*.*s|\n", 4 * w_sign, 10, "123456");
//	printf("~~~~~~~~~\n");
//	printf("|%*.*s|\n", 7 * w_sign, 10, "1234");
//	ft_printf("|%*.*s|\n", 7 * w_sign, 10, "1234");
//	return (0);
}
