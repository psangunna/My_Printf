/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_px.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:31:37 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:31:40 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{
	int	c;
	int	num;

	printf("\nTEST p\n");
	c = ft_printf(" %p ", -1);
	printf("\nMyCount:%d\n", c);
	ft_printf(" %p ", 1);
	ft_printf(" %p ", 15);
	ft_printf(" %p ", 16);
	ft_printf(" %p ", 17);
	ft_printf(" %p %p ", LONG_MIN, LONG_MAX);
	c = ft_printf(" %p %p ", INT_MIN, INT_MAX);
	printf("\nMyCount:%d\n", c);
	ft_printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	c = ft_printf(" %p %p ", 0, 0);
	printf("\nMyCount:%d\n", c);
	
	printf("\nPrintf standar\n", c);
	c = printf(" %p ", -1);
	printf("\nCount:%d\n", c);
	printf(" %p ", 1);
	printf(" %p ", 15);
	printf(" %p ", 16);
	printf(" %p ", 17);
	printf(" %p %p ", LONG_MIN, LONG_MAX);
	c = printf(" %p %p ", INT_MIN, INT_MAX);
	printf("\nCount:%d\n", c);
	printf(" %p %p ", ULONG_MAX, -ULONG_MAX);
	c = printf(" %p %p ", 0, 0);
	printf("\nCount:%d\n", c);

	printf("\nTEST x\n");
	ft_printf(" %x ", 0);
	ft_printf(" %x ", -1);
	ft_printf(" %x ", 1);
	ft_printf(" %x ", 9);
	ft_printf(" %x ", 10);
	ft_printf(" %x ", 11);
	ft_printf(" %x ", 15);
	ft_printf(" %x ", 16);
	ft_printf(" %x ", 17);
	ft_printf(" %x ", 99);
	c = ft_printf(" %x ", 100);
	printf("\nMyCount:%d\n", c);
	ft_printf(" %x ", 101);
	ft_printf(" %x ", -9);
	ft_printf(" %x ", -10);
	ft_printf(" %x ", -11);
	ft_printf(" %x ", -14);
	ft_printf(" %x ", -15);
	ft_printf(" %x ", -16);
	ft_printf(" %x ", -99);
	ft_printf(" %x ", -100);
	ft_printf(" %x ", -101);
	ft_printf(" %x ", INT_MAX);
	ft_printf(" %x ", INT_MIN);
	ft_printf(" %x ", LONG_MAX);
	ft_printf(" %x ", LONG_MIN);
	ft_printf(" %x ", UINT_MAX);
	ft_printf(" %x ", ULONG_MAX);
	ft_printf(" %x ", 9223372036854775807LL);
	c = ft_printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nMyCount:%d\n", c);
	ft_printf(" %x ", 42);
	ft_printf(" %x ", -42);

	printf("\nPrintf standar\n");
	printf(" %x ", 0);
	printf(" %x ", -1);
	printf(" %x ", 1);
	printf(" %x ", 9);
	printf(" %x ", 10);
	printf(" %x ", 11);
	printf(" %x ", 15);
	printf(" %x ", 16);
	printf(" %x ", 17);
	printf(" %x ", 99);
	c = printf(" %x ", 100);
	printf("\nCount:%d\n", c);
	printf(" %x ", 101);
	printf(" %x ", -9);
	printf(" %x ", -10);
	printf(" %x ", -11);
	printf(" %x ", -14);
	printf(" %x ", -15);
	printf(" %x ", -16);
	printf(" %x ", -99);
	printf(" %x ", -100);
	printf(" %x ", -101);
	printf(" %x ", INT_MAX);
	printf(" %x ", INT_MIN);
	printf(" %x ", LONG_MAX);
	printf(" %x ", LONG_MIN);
	printf(" %x ", UINT_MAX);
	printf(" %x ", ULONG_MAX);
	printf(" %x ", 9223372036854775807LL);
	c = printf(" %x %x %x %x %x %x %x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nCount:%d\n", c);
	printf(" %x ", 42);
	printf(" %x ", -42);

	printf("\nTEST X\n");
	ft_printf(" %X ", 0);
	ft_printf(" %X ", -1);
	ft_printf(" %X ", 1);
	ft_printf(" %X ", 9);
	ft_printf(" %X ", 10);
	ft_printf(" %X ", 11);
	ft_printf(" %X ", 15);
	ft_printf(" %X ", 16);
	ft_printf(" %X ", 17);
	ft_printf(" %X ", 99);
	ft_printf(" %X ", 100);
	ft_printf(" %X ", 101);
	ft_printf(" %X ", -9);
	ft_printf(" %X ", -10);
	ft_printf(" %X ", -11);
	ft_printf(" %X ", -14);
	ft_printf(" %X ", -15);
	ft_printf(" %X ", -16);
	ft_printf(" %X ", -99);
	c = ft_printf(" %X ", -100);
	printf("\nMyCount:%d\n", c);
	ft_printf(" %X ", -101);
	ft_printf(" %X ", INT_MAX);
	ft_printf(" %X ", INT_MIN);
	ft_printf(" %X ", LONG_MAX);
	ft_printf(" %X ", LONG_MIN);
	ft_printf(" %X ", UINT_MAX);
	ft_printf(" %X ", ULONG_MAX);
	ft_printf(" %X ", 9223372036854775807LL);
	c = ft_printf(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nMyCount:%d\n", c);
	ft_printf(" %X ", 42);
	ft_printf(" %X ", -42);

	printf("\nPrintf standar\n", c);	
	printf(" %X ", 0);
	printf(" %X ", -1);
	printf(" %X ", 1);
	printf(" %X ", 9);
	printf(" %X ", 10);
	printf(" %X ", 11);
	printf(" %X ", 15);
	printf(" %X ", 16);
	printf(" %X ", 17);
	printf(" %X ", 99);
	printf(" %X ", 100);
	printf(" %X ", 101);
	printf(" %X ", -9);
	printf(" %X ", -10);
	printf(" %X ", -11);
	printf(" %X ", -14);
	printf(" %X ", -15);
	printf(" %X ", -16);
	printf(" %X ", -99);
	c = printf(" %X ", -100);
	printf("\nCount:%d\n", c);
	printf(" %X ", -101);
	printf(" %X ", INT_MAX);
	printf(" %X ", INT_MIN);
	printf(" %X ", LONG_MAX);
	printf(" %X ", LONG_MIN);
	printf(" %X ", UINT_MAX);
	printf(" %X ", ULONG_MAX);
	printf(" %X ", 9223372036854775807LL);
	c = printf(" %X %X %X %X %X %X %X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\nCount:%d\n", c);
	printf(" %X ", 42);
	printf(" %X ", -42);
	return (0);
}
