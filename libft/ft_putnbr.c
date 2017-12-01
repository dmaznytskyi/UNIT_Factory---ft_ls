/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:58:52 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/07/13 23:00:10 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		lengths(int n, size_t *len, int *weight)
{
	*len = 1;
	if (n >= 0)
	{
		*len = 0;
		n = -n;
	}
	*weight = 1;
	while (n / *weight < -9)
	{
		*weight *= 10;
		*len += 1;
	}
}

static void		my_itoa(int n)
{
	size_t	len;
	size_t	cur;
	char	c;
	int		weight;

	lengths(n, &len, &weight);
	cur = 0;
	if (n < 0)
	{
		write(1, "-", 1);
		cur++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		c = -(n / (int)weight % 10) + 48;
		write(1, &c, 1);
		weight /= 10;
	}
}

void			ft_putnbr(int n)
{
	my_itoa(n);
}
