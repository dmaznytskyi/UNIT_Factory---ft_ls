/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 19:04:55 by dmaznyts          #+#    #+#             */
/*   Updated: 2016/12/03 13:38:02 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp1;
	t_list	*tmp2;

	if (!alst)
		return ;
	tmp1 = *alst;
	tmp2 = NULL;
	while (tmp1 != NULL)
	{
		del(tmp1->content, tmp1->content_size);
		tmp2 = tmp1->next;
		free(tmp1);
		tmp1 = tmp2;
	}
	*alst = NULL;
}
