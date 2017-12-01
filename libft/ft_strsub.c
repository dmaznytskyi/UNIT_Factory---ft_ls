/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:40:15 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/11/29 14:40:17 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	ret = (char *)malloc(len + 1);
	if (!ret || !s)
		return (NULL);
	ret[len] = 0;
	while (len)
	{
		ret[len - 1] = s[start + len - 1];
		len--;
	}
	return (ret);
}
