/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: badwolf <badwolf@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 16:33:30 by rkowalsk     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 15:25:12 by badwolf     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

t_param	ft_pars_flags(char *str)
{
	int	i;
	
}

int		ft_print_param(va_list params, char conv)
{
	char	*str;
	int		
	if (conv == 'c')
	{
		ft_putchar_fd(va_arg(params, int), 1);
		return (1);
	}
	else if (conv == 's')
	{
		str = va_arg(params, char*);
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	else if (conv == 'd' || conv == 'i')
	{
		str = ft_itoa(va_arg(params, int));
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	else if (conv == 'u')
	{
		str = ft_uitoa(va_arg(params, unsigned int));
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	else if (conv == 'x')
	{
		str = ft_uitox_lowercase(va_arg(params, unsigned int));
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	else if (conv == 'X')
	{
		str = ft_uitox_uppercase(va_arg(params, unsigned int));
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	else if (conv == 'p')
	{
		str = ft_uitox_lowercase(va_arg(params, uintptr_t));
		str = ft_strjoin("0x", str);
		ft_putstr_fd(str, 1);
		return (ft_strlen(str));
	}
	else if (conv == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (-1);
}

int		ft_printf(const char *str, ...)
{
	va_list params;
	size_t	i;
	int		ret;

	va_start(params, str);
	ret = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
			ret = ret + ft_print_param(params, str[++i]);
		else
		{
			ft_putchar_fd(str[i], 1);
			ret++;
		}
		i++;
	}
	va_end(params);
	return (ret);
}
