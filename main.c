#include "ft_printf.h"

int main()
{
//	char *p 			= "hello";

	ft_printf("test|%-10.*s|test\ntest|%-15.10x|test\n", 5, "string", -12345);
	printf("~~~~~~~\ntest|%-10.*s|test\ntest|%-15.10x|test\n", 5, "string", -12345);
	printf("~~~~~~~\ntest|%*.*%|test\n", 15, 5);
	ft_printf("test|%*.*%|test\n", 15, 5);
	return 0;
}
