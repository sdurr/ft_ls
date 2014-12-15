/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/15 11:18:34 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>
#include <sys/stat.h>

void 		ft_ls_option_l_permissions(char **tab)
{
	struct stat sb;
	int count;
	int c;

	count = 0;
	while (tab[count])
	{
		stat(tab[count], &sb);
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
		c = ft_count_sous_dossiers(tab[count]);
		if (c < 10)
			ft_putstr("   ");
		else if (c < 99 && c > 9)
			ft_putstr("  ");
		else if (c < 999 && c > 99)
			ft_putstr(" ");
		ft_putnbr(c);
		ft_putstr(" ");
		ft_noms_proprietaire(tab[count]);
		ft_putstr(" ");
		ft_time(tab[count]);
		ft_putstr(tab[count]);
		ft_putchar('\n');
		count++;
	}
}
