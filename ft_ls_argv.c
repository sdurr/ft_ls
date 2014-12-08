/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_argv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 09:35:51 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/08 15:47:54 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <dirent.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

void	ft_ls_argv(char *argv, int argc)
{
	DIR *dirp;
	struct dirent *read;

	if (argc > 2)
	{
		ft_putstr(argv);
		ft_putstr (":\n");
	}
	if ((dirp = opendir(argv)) != NULL) // ouverture argv[1] pointeur sur flux
		// opendir(".")
	{

		while ((read = readdir(dirp)) != NULL) // lecture argv
		{
			ft_putstr(read -> d_name); // print name
			ft_putchar ('\n');
		}
	}
}
