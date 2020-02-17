/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 17:18:17 by rkowalsk          #+#    #+#             */
/*   Updated: 2020/02/17 15:48:16 by rkowalsk         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

typedef struct	s_flag
{
	bool	error;
	bool	zero;
	bool	precision;
	bool	minus;
	bool	width;
	int		nb_width;
	int		nb_precisions;
	char	conv;
}				t_flag;

int				ft_printf(const char *str, ...);
char			*ft_uitox_lowercase(unsigned long n);
char			*ft_uitox_uppercase(unsigned long n);
int				ft_print_param(va_list params, t_flag flags);
int				ft_print_di(va_list params, t_flag flags);
int				ft_print_u(va_list params, t_flag flags);
int				ft_print_x_low(va_list params, t_flag flags);
int				ft_print_x_up(va_list params, t_flag flags);
int				ft_print_p(va_list params, t_flag flags);
int				ft_print_s(va_list params, t_flag flags);

#endif