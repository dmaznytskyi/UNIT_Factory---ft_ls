/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 18:14:12 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/11/29 12:34:48 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*q;

	q = (char *)s;
	i = ft_strlen(s);
	while (i >= 0)
	{
		if (q[i] == (char)c)
			return (q + i);
		i--;
	}
	return (NULL);
}
