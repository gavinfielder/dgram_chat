/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfielder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 18:53:02 by gfielder          #+#    #+#             */
/*   Updated: 2019/03/07 21:37:20 by gfielder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include "ftpf_backend.h"
#include "test.h"
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int				test_num;

/*
void	printf_right_pad(const char *str, int field_width)
{
	int len = strlen(str);
	printf("%s", str);
	for (int i = len; i < field_width; i++)
		printf(" ");
}*/

void	run_all_tests(void)
{
	static int initialized = 0;
	if (!(initialized))
	{
		test_num = 0;
		initialized = 1;
	}
	int fail = 0;
	int num_fails = 0;
	for (int i = 0; g_unit_tests[i] != NULL; i++)
	{
		printf("Test %3i:  %-42s [",test_num, g_unit_test_names[i]);
		fail = g_unit_tests[i]();
		if (fail)
			printf(RED "FAIL" RESET);
		else
			printf(GRN "PASS" RESET);
		printf("]\n");
		num_fails += fail;
	}
	printf("Tests completed. %i/%i tests passed.\n",
			test_num - num_fails, test_num);
	if (test_num - num_fails != test_num)
		printf("See %s for details.\n", TEST_OUTPUT_FILENAME);
}

int		test(const char *fmt, ...)
{
	va_list			args;
	va_list			args_copy;
	t_stringbuilder	*sb;
	char			*ret_mine;
	char			*ret_sys;
	int				ret_val_mine;
	int				ret_val_sys;
	int				failed = 0;
	int				fd;
	
	//initialize test
	sb = ft_sbnew();
	va_start(args, fmt);
	va_copy(args_copy, args);
	//get mine
	ret_val_mine = ft_vsbprintf(sb, fmt, args);
	ret_mine = ft_sbtostr(sb);
	//get system
	ret_val_sys = vasprintf(&ret_sys, fmt, args_copy);
	//compare
	if (ret_val_mine != ret_val_sys || strcmp(ret_mine, ret_sys) != 0)
		failed = 1;
	if (failed)
	{
		fd = open(TEST_OUTPUT_FILENAME, O_CREAT | O_WRONLY | O_APPEND,
				S_IRWXU | S_IRWXG | S_IRWXO);
		dprintf(fd, "Test %3i (%s) : FAILED.\n", test_num, g_unit_test_names[test_num]);
		dprintf(fd, "    Returned expected %i, actual %i\n",
				ret_val_sys, ret_val_mine);
		dprintf(fd, "    Resulting string expected \"%s\", actual \"%s\"\n",
				ret_sys, ret_mine);
		close(fd);
	}
	//clean up
	ft_sbdel(&sb);
	free(ret_mine);
	free(ret_sys);
	va_end(args);
	va_end(args_copy);
	test_num++;
	return (failed);
}
