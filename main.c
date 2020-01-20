/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 16:30:53 by rkowalsk     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/14 17:45:44 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

//#include "ft_printf.h"
#include <stdio.h>
int	main(void)
{
	int i = 50;
	char str[1];
	*str = 'p';

	//ft_printf("%d\n", ft_printf("prank |%s| |%p| |%c| |%d| |%u| |%x| |%X| |%%|\n", "bite", &i, '<', i, 1234567891, 31, 31));
	printf("%d\n", printf("prank |%s| |%p| |%c| |%d| |%u| |%x| |%X| |%%|\n", "bite", &i, '<', i, 1234567891, 31, 31));

	dprintf(1, "|%12d|\n", 123);
	dprintf(1, "|%-12d|\n", 123);
	dprintf(1, "|%.12d|\n", 123);
	dprintf(1, "|%.d|\n", 123);
	dprintf(1, "|%012d|\n", 123);
	dprintf(1, "|%06.6d|\n", 123);
	dprintf(1, "|%06.d|\n", 123);
	dprintf(1, "|%0.6d|\n", 123);
	dprintf(1, "|%12s|\n", "prank");
	dprintf(1, "|%3s|\n", "prank");
	dprintf(1, "|%-12s|\n", "prank");
	dprintf(1, "|%.12s|\n", "prank");
	dprintf(1, "|%.3s|\n", "prank");
	dprintf(1, "|%.s|\n", "prank");
	dprintf(1, "|%012s|\n", "prank");

	return (0);
}
