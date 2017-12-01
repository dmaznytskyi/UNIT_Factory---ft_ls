/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:26:44 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/11/25 17:22:33 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *lit)
{
	int		q;
	int		r;
	char	*str;

	str = (char *)big;
	if (!(*lit))
		return (str);
	while (*str != '\0')
	{
		if (*str == *lit)
		{
			r = 0;
			q = 0;
			while (lit[q])
			{
				if (str[r++] != lit[q++])
					return (ft_strstr(++str, lit));
			}
			return (str);
		}
		str++;
	}
	return (NULL);
}
