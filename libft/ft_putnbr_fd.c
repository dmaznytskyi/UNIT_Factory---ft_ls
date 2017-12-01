/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 13:58:48 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/12/06 13:59:03 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	lengths(int n, size_t *len, int *weight)
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

static void	my_itoa(int n, int fd)
{
	size_t	len;
	size_t	cur;
	char	c;
	int		weight;

	lengths(n, &len, &weight);
	cur = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		cur++;
	}
	if (n > 0)
		n = -n;
	while (weight >= 1)
	{
		c = -(n / (int)weight % 10) + 48;
		write(fd, &c, 1);
		weight /= 10;
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	my_itoa(n, fd);
}
