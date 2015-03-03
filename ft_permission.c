/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_perm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/17 13:08:07 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/03 11:17:48 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>

void		ft_permission(char *tab)
{
	struct stat sb;

	lstat(tab, &sb);
	if (S_ISREG(sb.st_mode))
		ft_putchar('-');
	if (S_ISLNK(sb.st_mode))
		ft_putchar('l');
	if (S_ISDIR(sb.st_mode))
		ft_putchar ('d');
	if (S_ISBLK(sb.st_mode))
		ft_putchar('b');
	if (S_ISCHR(sb.st_mode))
		ft_putchar('c');
	if (S_ISFIFO(sb.st_mode))
		ft_putchar('|');
	if (sb.st_mode & S_IRUSR)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IWUSR)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IRGRP)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IWGRP)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IROTH)
		ft_putchar('r');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IWOTH)
		ft_putchar('w');
	else
		ft_putchar('-');
	if (sb.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');
}
