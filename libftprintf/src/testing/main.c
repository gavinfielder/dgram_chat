/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 22:34:50 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/08 13:34:05 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "test.h"
#include <stdio.h>

void freeform_test(int argc, char **argv)
{
	if (argc == 2)
	{
		ft_printf(argv[1]);
		ft_printf("\n");
	}
	else if (argc == 3)
		ft_printf("%s%s\n", argv[1], argv[2]);
	else if (argc >= 4)
		ft_printf("%s%s%s\n", argv[1], argv[2], argv[3]);
}

int main(int argc, char **argv)
{
	freeform_test(argc, argv);
	(void)argc;
	(void)argv;
	//run_all_tests();
	return (0);
}
