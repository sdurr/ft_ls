/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_count_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:01:31 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/12 14:08:26 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

int		ft_ls_count_files_R(char **argv, int nb_argv, int argc)
{
	int i;
	int j;
	DIR *dirp;
	struct dirent *read;
	char *tmp;

	j = 1;
	i = 0;
	if ((nb_argv - argc) == 0)
	{
		if ((dirp = opendir(".")) != NULL)
			while ((read = readdir(dirp)) != NULL)
			{
				i++;
				nb_argv++;
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
	return(i);
}
