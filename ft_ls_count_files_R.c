/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_count_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:01:31 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/09 15:46:39 by sdurr            ###   ########.fr       */
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
	char *tmp;

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
			tmp = ft_strdup(argv[j]);
			while  ((dirp = opendir(tmp)) != NULL)
			{
				while ((read = readdir(dirp)) != NULL)
				{
					tmp = ft_strdup(read -> d_name);
					if (tmp[0] != '.')
						i++;
				}
			}
			j++;
		}
	}
	ft_putnbr(i);
	return(i);
}
