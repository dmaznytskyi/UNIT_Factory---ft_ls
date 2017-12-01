/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 18:05:25 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/12/06 13:57:40 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	cnt_prts(char const *s, char c)
{
	size_t	cnt;
	size_t	in_substring;

	in_substring = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (in_substring == 1 && *s == c)
			in_substring = 0;
		if (in_substring == 0 && *s != c)
		{
			in_substring = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static size_t	wlen(char const *s, char c)
{
	size_t	len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		len++;
		s++;
	}
	return (len);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	size_t	nb_word;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	nb_word = cnt_prts(s, c);
	ret = (char **)malloc(sizeof(*ret) * (cnt_prts(s, c) + 1));
	if (ret == NULL)
		return (NULL);
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			s++;
		ret[i] = ft_strsub(s, 0, wlen(s, c));
		if (ret[i] == NULL)
			return (NULL);
		s = s + wlen(s, c);
		i++;
	}
	ret[i] = NULL;
	return (ret);
}
