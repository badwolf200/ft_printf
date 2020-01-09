/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: rkowalsk <rkowalsk@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/10/10 15:58:14 by rkowalsk     #+#   ##    ##    #+#       */
/*   Updated: 2019/10/17 13:17:53 by rkowalsk    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		part_of_set(const char *set, char c)
{
	int i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char		*empty_str_alloc(void)
{
	char *str;

	if (!(str = (char *)malloc(1 * sizeof(char))))
		return (NULL);
	str[0] = '\0';
	return (str);
}

char			*ft_strtrim(const char *s1, char const *set)
{
	int		s1_len;
	int		start;
	int		end;
	char	*str;
	int		i;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	end = s1_len - 1;
	while (part_of_set(set, s1[start]) && s1[start])
		start++;
	while (part_of_set(set, s1[end]) && end > 0)
		end--;
	if (end == 0)
		return (empty_str_alloc());
	if (!(str = (char *)malloc((end - start + 2) * sizeof(char))))
		return (NULL);
	i = 0;
	while (start <= end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
