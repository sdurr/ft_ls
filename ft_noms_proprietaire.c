/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_noms_proprietaire.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/15 10:28:02 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/15 16:16:56 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include "libft.h"
#include <pwd.h>
#include <grp.h>
#include <sys/types.h>

void 	ft_noms_proprietaire(char *av)
{
	struct passwd *result;
	struct stat sb;
	struct group *group;
	int c;

	stat(av, &sb);
	result = getpwuid(sb.st_uid);
	ft_putstr(result -> pw_name);
	ft_putstr("  ");
	group = getgrgid(sb.st_gid);
	ft_putstr(group -> gr_name);
	c = sb.st_size;
	if (c > 999999)
		ft_putstr(" ");
	if (c > 99999 && c < 1000000)
		ft_putstr("  ");
	if (c > 9999 && c < 100000)
		ft_putstr("   ");
	if (c > 999 && c < 10000)
		ft_putstr("    ");
	if (c > 99 && c < 1000)
		ft_putstr("     ");
	if (c > 9 && c < 100)
		ft_putstr("      ");
	if (c >= 0 && c < 10)
		ft_putstr("       ");
	ft_putnbr(sb.st_size);
}
