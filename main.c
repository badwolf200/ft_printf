/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 16:33:30 by rkowalsk     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/07 15:45:58 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	afich_d_chifr(size_t nb_val, ...)
{
	va_list param;
	size_t	i;

	va_start(param, nb_val);
	i = 0;
	while (i < nb_val)
	{
		ft_putnbr_fd(va_arg(param, int), 1);
		i++;
	}
	va_end(param);
}



void	ft_print_param(va_list params, char conv);

int		ft_printf(const char *str, ...)
{
	va_list params;
	size_t	i;

	va_start(params, str);
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			ft_print_param(params, )
		}
	}
}

int	main(void)
{
	afich_d_chifr(6, 1, 2, 3, 4, 5, 1000);
}
