/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_count_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:01:31 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 12:27:15 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

int		ft_ls_count_files(char **argv)
{
	int				i;
	int				j;
	DIR				*dirp;
	struct dirent	*read;

	j = 1;
	i = 0;
	if ((dirp = opendir(".")) != NULL)
		while ((read = readdir(dirp)) != NULL)
			i++;
	else
		while (argv[j])
		{
			if ((dirp = opendir(argv[j])) != NULL)
				while ((read = readdir(dirp)) != NULL)
					i++;
			j++;
		}
	ft_putnbr(i);
	ft_putchar ('\n');
	return (i);
}
