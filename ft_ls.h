/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:51:43 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/12/14 17:03:09 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include <dirent.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>

#include <stdio.h>////////////////////////////////////////////////////////////////////////

typedef struct  s_dirs
{
	char            *dir_name;
	struct s_dirs   *next;
}               t_dirs;

typedef struct  s_ftls
{
	t_dirs  *dirs;
	int     is_dir;
	int     f_l;
	int     f_rb;
	int     f_a;
	int     f_rs;
	int     f_t;
    int     error;
	/*--- directories paths for recursive calling ---*/
	/*--- think, what else ---*/
}               t_ftls;

void	print_dir_content(char *dir);
void    parse_flags(int ac, char **av, t_ftls *s);

#endif
