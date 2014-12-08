/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_count_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:01:31 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/08 16:07:43 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>

int		ft_count_files(char **argv)
{
	int i;
	DIR *dirp;
	struct dirent *read;

	i = 0;
	if (argc == 1)
	{
		if ((dirp = opendir(".")) != NULL)
			while ((read = readdir(dirp)) != NULL)
				i++;
	}
	return(i);
}
