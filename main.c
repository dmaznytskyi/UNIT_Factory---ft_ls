/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:28:54 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/11/30 17:51:05 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_usage(char *pn)
{
	ft_putstr("usage: ");
	ft_putstr(pn);
	ft_putstr(" [-lRart] [file ...]\n");
}

void	il_opt(char a, t_ftls *s)
{
	ft_putstr("ft_ls: illegal option -- ");
	ft_putchar(a);
	ft_putchar('\n');
	s->error = 1;
}

void	take_flags(char *a, t_ftls *s)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(a);
	while (++i < len)
	{
		if (a[i] == 'l')
			s->f_l = 1;
		else if (a[i] == 'R')
			s->f_rb = 1;
		else if (a[i] == 'a')
			s->f_a = 1;
		else if (a[i] == 'r')
			s->f_rs = 1;
		else if (a[i] == 't')
			s->f_t = 1;
		else
			return (il_opt(a[i], s));
	}
}

void	add_dir(char *a, t_ftls *s)
{
	t_dirs	*tmp;

	s->is_dir = 1;
	if (!s->dirs)
	{
		s->dirs = (t_dirs *)malloc(sizeof(t_dirs));
		s->dirs->dir_name = ft_strdup(a);
		s->dirs->next = NULL;
	}
	else
	{
		tmp = s->dirs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = (t_dirs *)malloc(sizeof(t_dirs));
		tmp->next->dir_name = ft_strdup(a);
		tmp->next->next = NULL;
	}
}

void	parse_flags(int ac, char **av, t_ftls *s)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (av[i][0] == '-' && av[i][1] != '\0' && s->is_dir == 0)
			take_flags(av[i], s);
		else
			add_dir(av[i], s);
		if (s->error)
			return (print_usage(av[0]));
		else
			outputter(s);
	}
}

void	init_struct(t_ftls *s)
{
	s = (t_ftls *)malloc(sizeof(t_ftls));
	s->is_dir = 0;
	s->dirs = NULL;
	s->f_l = 0;
    s->f_rb = 0;
    s->f_a = 0;
    s->f_rs = 0;
    s->f_t = 0;
	s->error = 0;
}

int		main(int ac, char **av)
{
	t_ftls	s;

	if (ac >= 2)
	{
		init_struct(&s);
		parse_flags(ac, av, &s);
		// free_struct(&s);
	}
	else
		print_usage(av[0]);
	return (0);
}
