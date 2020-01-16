/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: badwolf <badwolf@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/06 17:18:17 by rkowalsk     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/16 15:25:09 by badwolf     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include "libft.h"

char			*ft_uitoa(unsigned int n);
char			*ft_uitox_lowercase(unsigned long n);
char			*ft_uitox_uppercase(unsigned long n);

typedef struct	s_param
{
	bool	zero;
	bool	precision;
	int		width
}				t_param;

#endif