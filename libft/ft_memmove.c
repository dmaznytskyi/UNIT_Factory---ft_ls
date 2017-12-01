/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:35:20 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/11/29 14:35:21 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*cs;
	unsigned char	*cd;

	cs = (unsigned char *)src;
	cd = (unsigned char *)dst;
	if (dst > src)
		while (len-- > 0)
			cd[len] = cs[len];
	else
		while (len-- > 0)
			*cd++ = *cs++;
	return (dst);
}
