/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_files_or_directory.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/19 15:42:54 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/29 22:21:13 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_ls.h"

char	**ft_no_files_or_directory(char **argv, int j, char ***tab_argv)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(argv[j], 2);
	ft_putstr_fd(":", 2);
	ft_putstr_fd(" No such file or directory", 2);
	ft_putstr_fd("\n", 2);
	argv = ft_rm_argv(argv, j);
	rm_tab_argv(tab_argv, j);
	return (argv);
}
