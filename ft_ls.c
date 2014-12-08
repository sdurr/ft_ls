/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/08 15:16:09 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	ft_ls(char *argv)
{
	DIR *dirp;
	struct dirent *read;
	int i;

	i = 0;
	if ((dirp = opendir(argv)) != NULL) // ouverture argv[1] pointeur sur flux
	{
		while ((read = readdir(dirp)) != NULL) // lecture argv
			i++;
			printf("%d\n", i);
	}
}
