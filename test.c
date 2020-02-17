/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   test.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/14 16:30:53 by rkowalsk     #+#   ##    ##    #+#       */
/*   Updated: 2020/02/12 13:49:02 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdio.h>
int	main(void)
{
	//int i = 50;
	char str[1];
	*str = 'p';

	//ft_printf("%d\n", ft_printf("prank |%s| |%p| |%c| |%d| |%u| |%x| |%X| |%%|\n", "bite", &i, '<', i, 1234567891, 31, 31));
	//printf("%d\n", printf("prank |%s| |%p| |%c| |%d| |%u| |%x| |%X| |%%|\n", "bite", &i, '<', i, 1234567891, 31, 31));
	dprintf(1, "| %d\n", dprintf(1, "00|%.*s|\n", 2, "bite"));
	dprintf(1, "| %d\n", dprintf(1, "01|%.2s|\n", "bite"));
	dprintf(1, "| %d\n", dprintf(1, "02|%p|\n", (void*)0));
	dprintf(1, "| %d\n", dprintf(1, "03|%12s|\n", "prank"));
	dprintf(1, "| %d\n", dprintf(1, "04|%1s|\n", "prank"));
	dprintf(1, "| %d\n", dprintf(1, "05|%-12.3s|\n", "prank"));
	dprintf(1, "| %d\n", dprintf(1, "06|%12s|\n", "prank"));
	dprintf(1, "| %d\n", dprintf(1, "07|%6s|\n", "prank"));
	dprintf(1, "| %d\n", dprintf(1, "08|%-6s|\n","tonpere"));
	// dprintf(1, "09|%12s|\n", "prank");
	// dprintf(1, "10|%3s|\n", "prank");
	// dprintf(1, "12|%-12s|\n", "prank");
	// dprintf(1, "13|%.12s|\n", "prank");
	// dprintf(1, "14|%.03s|\n", "prank");
	// dprintf(1, "15|%.*s|\n", 3, "prank");
	// dprintf(1, "16|%.s|\n", "prank");
	// dprintf(1, "17|%p|\n", (void *)42);
	// dprintf(1, "18|%12.p|\n", (void *)42);
	// dprintf(1, "19|%12c|\n", 'a');
	// dprintf(1, "20|%-12c|\n", 'a');
	// dprintf(1, "21|%*i|\n", 12, 123);
	// dprintf(1, "22|%12.6u|\n", 123);
	// dprintf(1, "23|%.2X|\n", 10);
	// dprintf(1, "24|%-2X|\n", 10);
	// dprintf(1, "25|%-12p|\n", (void*)42);
	// dprintf(1, "26|%3c|\n", 'b');
	// dprintf(1, "27|%012.12d|\n", 123);
	// dprintf(1, "28|%06.d|\n", 123);
	// dprintf(1, "29|%0.06d|\n", 123);
	// dprintf(1, "30|%12s|\n", "prank");
	// dprintf(1, "31|%3s|\n", "prank");
	// dprintf(1, "32|%-12s|\n", "prank");
	// dprintf(1, "33|%.12s|\n", "prank");
	// dprintf(1, "34|%.03s|\n", "prank");
	// dprintf(1, "35|%.*s|\n", 3, "prank");
	// dprintf(1, "36|%.s|\n", "prank");
	// dprintf(1, "37|%p|\n", (void *)42);
	// dprintf(1, "38|%12.p|\n", (void *)42);
	// dprintf(1, "39|%12c|\n", 'a');
	// dprintf(1, "40|%-12c|\n", 'a');
	//printf("%lu|%lu|%lu\n", sizeof(long int), sizeof(int), sizeof(long long));
	return (0);
}
