/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 14:40:30 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/12/02 17:14:02 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	begin(char const *s)
{
	size_t	i;
	size_t	n;

	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		{
			n++;
			i++;
		}
		else
			break ;
	}
	return (n);
}

static size_t	end(const char *s)
{
	size_t	i;
	size_t	n;

	if ((n = ft_strlen(s)) == 0)
		return (n);
	i = n - 1;
	while (i > 0)
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i--;
		else
			return (i);
	}
	return (n);
}

char			*ft_strtrim(char const *s)
{
	size_t	i;
	size_t	n;
	size_t	j;
	char	*str;

	if (!(s))
		return (NULL);
	n = end(s) - begin(s) + 1;
	if (!(str = ft_strnew(n)))
		return (NULL);
	i = begin(s);
	j = 0;
	while (s[i] && i <= end(s))
	{
		str[j] = s[i];
		j++;
		i++;
	}
	str[j] = '\0';
	return (str);
}
