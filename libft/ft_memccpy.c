/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/07 17:28:14 by rkowalsk     #+#   ##    ##    #+#       */
/*   Updated: 2019/11/13 11:18:21 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dst_str;
	unsigned char	*src_str;

	dst_str = (unsigned char *)dst;
	src_str = (unsigned char *)src;
	i = 0;
	while (i < n && src_str[i] != (unsigned char)c)
	{
		dst_str[i] = src_str[i];
		i++;
	}
	if (src_str[i] == (unsigned char)c)
	{
		dst_str[i] = src_str[i];
		i++;
		return (dst + i);
	}
	return (NULL);
}
