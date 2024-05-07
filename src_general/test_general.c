/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_general.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:02:47 by pamela            #+#    #+#             */
/*   Updated: 2024/05/07 10:03:49 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int	count;
	int	num;
	int	*pointer;

	count = printf("Hey %r%y-g%y%", "Jonh");
	printf("\nCount:%d\n", count);
	count = ft_printf("Hey %r%y-g%y%", "Jonh");
	printf("\nMy_count:%d\n", count);
	count = 0;
	printf("\n");
	count = printf("Halo [% -10c]\n", 'd');
	printf("Count:%d\n", count);
	count = ft_printf("Hola [% -10c]\n", 'd');
	printf("MyCount:%d\n", count);
	count = printf("Hello %%\n");
	printf("Count:%d\n", count);
	count = ft_printf("Hello %%\n");
	printf("MyCount:%d\n", count);
	count = printf("Buenos %-10.3s\n", "Pamela");
	printf("Count:%d\n", count);
	count = ft_printf("Buenos %-10.3s\n", "Pamela");
	printf("MyCount:%d\n", count);
	count = printf("Buenos %+10d\n", -23);
	printf("Count:%d\n", count);
	count = ft_printf("Buenos %+10d\n", -23);
	printf("MyCount:%d\n", count);
	count = printf("%#x\n", -42);
	printf("Count:%d\n", count);
	count = ft_printf("%#x\n", -42);
	count = printf("%#X\n", -22);
	printf("Count:%d\n", count);
	count = ft_printf("%#X\n", -22);
	printf("MyCount:%d\n", count);
	count = printf("%u\n", -10);
	printf("Count:%d\n", count);
	count = ft_printf("%u\n", -10);
	printf("MyCount:%d\n", count);
	num = 18;
	pointer = &num;
	count = printf("%p\n", pointer);
	printf("Count:%d\n", count);
	count = ft_printf("%p\n", pointer);
	printf("MyCount:%d\n", count);
	count = printf("%*c\n", 10, 'g');
	printf("Count:%d\n", count);
	count = ft_printf("%*c\n", 10, 'g');
	printf("MyCount:%d\n", count);
	count = printf("%*i\n%d\n", 10, 23, 50);
	printf("Count:%d\n", count);
	count = ft_printf("%*i\n%d\n", 10, 23, 50);
	printf("MyCount:%d\n", count);
	count = printf("%*s\n", 10, "gata");
	printf("Count:%d\n", count);
	count = ft_printf("%*s\n", 10, "gata");
	printf("MyCount:%d\n", count);

	printf("\nPruebas desbordamiento\n");
	count = printf("%p\n", (void *)-14523);
	printf("Count:%d\n", count);
	count = ft_printf("%p\n", (void *)-14523);
	printf("MyCount:%d\n", count);
	count = printf("0x%p-\n", (void *)ULONG_MAX);
	printf("Count:%d\n", count);
	count = ft_printf("0x%p-\n", (void *)ULONG_MAX);
	printf("MyCount:%d\n", count);
	count = printf("at\n=sq\v;%pp\n_Mt%xo,T#%diNk+/%%[%it* `4%um{\ny.B8%X$/!1zR#nPy%sjwnO5", (void *)-6506301648355864279, 2141186925, 2043167108, -1243449557, -1345113910, -332442644, "<Qsb)>!,bB|-nt7N\\4f");
	printf("Count:%d\n", count);
	count = ft_printf("at\n=sq\v;%pp\n_Mt%xo,T#%diNk+/%%[%it* `4%um{\ny.B8%X$/!1zR#nPy%sjwnO5", (void *)-6506301648355864279, 2141186925, 2043167108, -1243449557, -1345113910, -332442644, "<Qsb)>!,bB|-nt7N\\4f");
	printf("MyCount:%d\n", count);
	printf(" %+d %+d %+d %+d %+d %+d %+d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %+d %+d %+d %+d %+d %+d %+d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %+d \n", 9223372036854775807LL);
	ft_printf(" %+d \n", 9223372036854775807LL);
	printf(" %+i %+i %+i %+i %+i %+i %+i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %+i %+i %+i %+i %+i %+i %+i\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf(" %+i \n", 9223372036854775807LL);
	ft_printf(" %+i \n", 9223372036854775807LL);
	printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %#X %#X %#X %#X %#X %#X %#X\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	count = printf(" %#X \n", 9223372036854775807LL);
	printf("Count:%d\n", count);
	count  = ft_printf(" %#X \n", 9223372036854775807LL);
	printf("MyCount:%d\n", count);
	printf("\n");
	printf("test pointer");
	count = printf(" %p ", -1);
	printf("Count:%d\n", count);
	count = ft_printf(" %p ", -1);
	printf("MyCount:%d\n", count);
	printf("\n");
	ft_printf(" %p ", 1);
	printf("\n");
	ft_printf(" %p ", 15);
	printf("\n");
	ft_printf(" %p ", 16);
	printf("\n");
	ft_printf(" %p ", 17);
	printf("\n");
	count = printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("Count:%d\n", count);
	count = ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	printf("MyCount:%d\n", count);
	printf("\n");
	count = printf(" %p %p ", INT_MIN, INT_MAX);
	printf("Count:%d\n", count);
	count = ft_printf(" %p %p ", INT_MIN, INT_MAX);
	printf("MyCount:%d\n", count);
	printf("\n");
	count = printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("Count:%d\n", count);
	count = ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	printf("MyCount:%d\n", count);
	printf("\n");
	count = printf(" %p %p ", 0, 0);
	printf("Count:%d\n", count);
	count = ft_printf(" %p %p ", 0, 0);
	printf("MyCount:%d\n", count);
	count = printf(" %s %s ", 0, 0);
	printf("Count:%d\n", count);
	count = ft_printf(" %s %s ", 0, 0);
	printf("MyCount:%d\n", count);
	return (0);
}
