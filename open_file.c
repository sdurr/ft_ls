/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/04 08:42:32 by sdurr             #+#    #+#             */
/*   Updated: 2015/03/04 08:51:52 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdlib.h>

int		open_file(char *path)
{
	DIR *dirp;

	if ((dirp = opendir(path)) != NULL)
		return (1);
	return (0);
}
