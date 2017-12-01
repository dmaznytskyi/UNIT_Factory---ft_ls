/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 19:25:42 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/11/29 12:59:37 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int		r;
	char	*str;

	str = (char *)big;
	if (!(*little))
		return (str);
	while (*str != '\0' && len != 0)
	{
		if (*str == *little)
		{
			r = 0;
			while (str[r] == little[r] && r < (int)len && little[r] != '\0')
				r++;
			if (little[r] == '\0')
				return (str);
		}
		str++;
		len--;
	}
	return (NULL);
}
