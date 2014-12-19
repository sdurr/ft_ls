/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_directory.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 08:51:42 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/19 13:59:07 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>
#include "libft.h"

char	*test_directory(char *tab)
{
	DIR *dirp;


	if ((dirp = opendir(tab)) != NULL)
	{
		return ("ok");
	}
	else
		return (NULL);
	return (NULL);
}
