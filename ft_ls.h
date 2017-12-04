/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 17:51:43 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/12/01 17:07:33 by dmaznyts         ###   ########.fr       */
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

#include <stdio.h>////////////////////////////////////////////////////////////////////////

typedef struct  s_ftls
{
    /*--- flags ---*/
    /*--- directories paths for recursive calling ---*/
    /*--- think, what else ---*/
}               t_ftls;

#endif
