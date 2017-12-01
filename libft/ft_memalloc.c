/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:34:47 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/11/29 14:34:48 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*buf;
	size_t	i;

	i = -1;
	buf = (void *)malloc(size);
	if (buf == NULL)
		return (NULL);
	else
	{
		while (++i < size)
			*((unsigned char *)buf + i) = 0;
		return (buf);
	}
}
