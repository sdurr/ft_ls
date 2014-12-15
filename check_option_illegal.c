/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 10:39:21 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/15 10:10:34 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>
#include "libft.h"

void		check_option_illegal(char *argv)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(argv[1]);
	ft_putstr("\nusage: ls [-ABCFGHLOPRSTUWabcdefghijklmnopqrstuwx1] [file ...]");
	ft_putchar ('\n');
}
