/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_files_or_directory.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 15:42:54 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/19 15:47:47 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

char	**ft_no_files_or_directory(char **argv, int j, char ***tab_argv)
{
	ft_putstr("ft_ls: ");
	ft_putstr(argv[j]);
	ft_putstr(":");
	ft_putstr(" No such file or directory");
	ft_putstr("\n");
	argv = ft_rm_argv(argv, j);
	rm_tab_argv(tab_argv, j);
	return (argv);
}
