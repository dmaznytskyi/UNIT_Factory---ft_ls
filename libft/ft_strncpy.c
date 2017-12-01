/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:02:12 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/11/25 15:22:12 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (len != 0 && src[i])
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len != 0)
	{
		dst[i++] = '\0';
		len--;
	}
	return (dst);
}
