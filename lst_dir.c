/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:17:06 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/12/01 18:56:43 by dmaznyts         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
**	struct stat { 		
**		dev_t           st_dev;           ID of device containing file
**		mode_t          st_mode;          Mode of file (see below)
**		nlink_t         st_nlink;         Number of hard links
**		ino_t           st_ino;           File serial number
**		uid_t           st_uid;           User ID of the file
**		gid_t           st_gid;           Group ID of the file
**		dev_t           st_rdev;          Device ID
**		struct timespec st_atimespec;     time of last access
**		struct timespec st_mtimespec;     time of last data modification
**		struct timespec st_ctimespec;     time of last status change
**		struct timespec st_birthtimespec; time of file creation(birth)
**		off_t           st_size;          file size, in bytes
**		blkcnt_t        st_blocks;        blocks allocated for file
**		blksize_t       st_blksize;       optimal blocksize for I/O
**		uint32_t        st_flags;         user defined flags for file
**		uint32_t        st_gen;           file generation number
**		int32_t         st_lspare;        RESERVED: DO NOT USE!
**		int64_t         st_qspare[2];     RESERVED: DO NOT USE!
**	};
**	
**	The status information word st_mode has the following bits:
**
**     #define S_IFMT 0170000           type of file
**     #define        S_IFIFO  0010000  named pipe (fifo)
**     #define        S_IFCHR  0020000  character special
**     #define        S_IFDIR  0040000  directory
**     #define        S_IFBLK  0060000  block special
**     #define        S_IFREG  0100000  regular
**     #define        S_IFLNK  0120000  symbolic link
**     #define        S_IFSOCK 0140000  socket
**     #define        S_IFWHT  0160000  whiteout
**     #define S_ISUID 0004000  set user id on execution
**     #define S_ISGID 0002000  set group id on execution
**     #define S_ISVTX 0001000  save swapped text even after use
**     #define S_IRUSR 0000400  read permission, owner
**     #define S_IWUSR 0000200  write permission, owner
**     #define S_IXUSR 0000100  execute/search permission, owner
*/

void	print_dir_elem_stat(char *path)
{
	struct stat		s;
	int				exec_code;

	printf("%d\n", exec_code = lstat(path, &s));
	//check dir /*(mode & S_IFMT) == S_IFDIR*/
	if (exec_code != -1)
	{
		printf("\tName:		%s\n", path);
		printf("\tMode:		%s\n", ft_itoa_base(s.st_mode, 2));
	}
}

/*
**	struct dirent {
**      ino_t          d_ino;       	Inode number
**      off_t          d_off;       	Not an offset; see below
**		unsigned short d_reclen;    	Length of this record
**		unsigned char  d_type;      	Type of file; not supported
**		                               		by all filesystem types
**		char           d_name[256];		Null-terminated filename
**	};
*/

void	print_dir_content(char *dir)
{
	DIR				*dirp;
	struct dirent	*dp;

	dirp = opendir(dir);
	if (dirp == NULL)
	{
		printf("No such directory\n");
		return ;
	}
	while ((dp = readdir(dirp)) != NULL)
	{
		printf("%s\n", dp->d_name);
		if (dp->d_name[0] != '.')
			print_dir_elem_stat(dp->d_name);
	}
	closedir(dirp);
}

int		main(int ac, char **av)
{
	if (ac == 2)
		print_dir_content(av[1]);
	else
		print_dir_content(".");
	return (0);
}
