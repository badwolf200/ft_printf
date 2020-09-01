#include "ft_printf.h"

int main (void)
{
	char *str1;
	char *str2;
	char *str3;

	str2 = malloc(sizeof(char)* 3);
	str3 = malloc(sizeof(char)* 3);
	str1 = malloc(sizeof(char)* 3);
	ft_free_all(3, str1, str2, str3);
}