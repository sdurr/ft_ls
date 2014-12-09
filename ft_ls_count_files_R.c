/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_count_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:01:31 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/09 15:04:24 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

int		ft_ls_count_files_R(char **argv)
{
	int i;
	int j;
	DIR *dirp;
	struct dirent *read;

	j = 1;
	i = 0;
	if (!argv[j+1])
	{
		if ((dirp = opendir(".")) != NULL)
			while ((read = readdir(dirp)) != NULL)
				i++;
	}
	else
	{
		i = 0;
		while (argv[j])
		{
			if ((dirp = opendir(argv[j])) != NULL)
			{
				while ((read = readdir(dirp)) != NULL)
				{
					ft_putstr(read -> d_name);
					ft_putchar ('\n');
					i++;
				}
			}
			j++;
		}
	}
	ft_putnbr(i);
	return(i);
}
