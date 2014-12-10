/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdurr <sdurr@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/10 13:07:32 by sdurr             #+#    #+#             */
/*   Updated: 2014/12/10 13:53:36 by sdurr            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "stdio.h"

int main(int argc, char **argv)
{
	int i;
	char **tab;
	int j;

	j = 0;
	if (argc > 1)
		i = test_option(argv);
	printf ("%d\n", i);
	if (OPT_A & i)
	{
		tab = ft_ls_option_a(argv, argc);
		while (tab[j])
			printf("%s\n", tab[j++]);
	}
	if (OPT_L & i)
		printf("\noption_L");
	if (OPT_R & i)
		printf("\noption_r");
	if (OPT_T & i)
		printf("\noption_t");
	if (OPT_R_R & i)
		printf("\noption_R");
	return (0);
}
