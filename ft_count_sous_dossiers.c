/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_sous_dossiers.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 14:09:12 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/12 16:06:02 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "libft.h"
#include <dirent.h>
#include <stdlib.h>

char 		*ft_count_sous_dossiers(char *tab)
{
	int i;
	DIR *dirp;
	struct dirent *read;
	char *ret;

	i = 1;
	if ((dirp = opendir(tab)) != NULL)
	{
		while ((read = readdir(dirp)) != NULL)
			i++;
	}
	ret = ft_itoa(i);
	return (ret);
}
