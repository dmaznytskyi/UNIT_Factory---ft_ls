/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:32:43 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/11/25 11:27:05 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;

	i = ft_strlen(dst);
	if (i >= size)
		return (size + ft_strlen(src));
	else if (i == size - 1)
		return (i + ft_strlen(src));
	while (i < size - 1 && *src)
		dst[i++] = *src++;
	dst[i] = '\0';
	return (ft_strlen(dst) + ft_strlen(src));
}
