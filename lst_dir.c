/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_dir.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaznyts <dmaznyts@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:17:06 by dmaznyts          #+#    #+#             */
/*   Updated: 2017/12/04 13:52:19 by dmaznyts         ###   ########.fr       */
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

/*
**	struct passwd {
**		char    *pw_name;       user name
**		char    *pw_passwd;     encrypted password
**		uid_t   pw_uid;         user uid
**		gid_t   pw_gid;         user gid
**		time_t  pw_change;      password change time
**		char    *pw_class;      user access class
**		char    *pw_gecos;      Honeywell login info
**		char    *pw_dir;        home directory
**		char    *pw_shell;      default shell
**		time_t  pw_expire;      account expiration
**		int     pw_fields;      internal: fields filled in
**	};
*/

/*
**	struct group {
**		char    *gr_name;       group name
**		char    *gr_passwd;     group password
**		gid_t   gr_gid;         group id
**		char    **gr_mem;       group members
**	};
*/

void	print_dir_elem_stat(char *path)
{
	struct stat		s;
	int				exec_code;
	struct passwd	*p;
	struct group	*g;

	printf("[%d | %s]\n", exec_code = lstat(path, &s), path);
	//check dir /*(mode & S_IFMT) == S_IFDIR*/
	if (exec_code != -1)
	{
		printf("\tName			: %s\n", path);
		printf("\tMode			: %s\n", ft_itoa_base(s.st_mode, 2));
		printf("\tSize			: %lld octets\n", s.st_size);
		printf("\tLast modification date	: %s", ctime((time_t*)&s.st_mtimespec));
		if ((s.st_mode & S_IFMT) == S_IFDIR)
			printf("\tType:		Directory\n");
		else if ((s.st_mode & S_IFMT) == S_IFREG)
			printf("\tType			: File\n");
		p = getpwuid(s.st_uid);
		printf("\tOwner			: %s\n", p->pw_name);
		g = getgrgid(s.st_gid);
		printf("\tGroup			: %s\n", g->gr_name);
		printf("\tNumber of hard-links	: %u\n", s.st_nlink);
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
	char			*path;

	dirp = opendir(dir);
	if (dirp == NULL)
	{
		dirp = opendir(".");
		while ((dp = readdir(dirp)) != NULL)
		{
			if (ft_strequ(dp->d_name, dir))
			{
				print_dir_elem_stat(ft_strjoin("./", dir));
				return ;
			}
		}
		printf("ft_ls: %s: No such file or directory\n", dir);
		return ;
	}
	while ((dp = readdir(dirp)) != NULL)
	{
		// printf("%s|[%c]\n", dp->d_name, dir[ft_strlen(dir) - 1]);
		if (dir[ft_strlen(dir) - 1] != '/')
			path = ft_strjoin(dir, "/");
		else
			path = ft_strdup(dir);
		// printf("%s\n", path);
		if (dp->d_name[0] != '.')
			print_dir_elem_stat(ft_strjoin(path, dp->d_name));
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
