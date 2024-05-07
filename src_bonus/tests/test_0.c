/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_0.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:09:22 by pamela            #+#    #+#             */
/*   Updated: 2024/05/07 10:12:00 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{  
	int c;

    printf("\n TEST d \n");
    ft_printf(" %01d ", 0);
    ft_printf(" %02d ", -1);
    ft_printf(" %04d ", 9);
    ft_printf(" %04d ", 16);
    ft_printf(" %05d ", 17);
    ft_printf(" %09d ", INT_MAX);
    ft_printf(" %010d ", INT_MIN);
    ft_printf(" %011d ", LONG_MAX);
    ft_printf(" %012d ", LONG_MIN);
    ft_printf(" %013d ", UINT_MAX);
    ft_printf(" %014d ", ULONG_MAX);
    ft_printf(" %015d ", 9223372036854775807LL);
    ft_printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\nprintf standar\n");
    printf(" %01d ", 0);
    printf(" %02d ", -1);
    printf(" %04d ", 9);
    printf(" %04d ", 16);
    printf(" %05d ", 17);
    printf(" %09d ", INT_MAX);
    printf(" %010d ", INT_MIN);
    printf(" %011d ", LONG_MAX);
    printf(" %012d ", LONG_MIN);
    printf(" %013d ", UINT_MAX);
    printf(" %014d ", ULONG_MAX);
    printf(" %015d ", 9223372036854775807LL);
    printf(" %09d %010d %011d %012d %013d %014d %015d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n TEST i \n");
    ft_printf(" %01i ", 0);
    ft_printf(" %02i ", -1);
    ft_printf(" %03i ", 1);
    ft_printf(" %04i ", 9);
    ft_printf(" %01i ", 10);
    ft_printf(" %02i ", -100);
    ft_printf(" %03i ", -101);
    ft_printf(" %09i ", INT_MAX);
    ft_printf(" %010i ", INT_MIN);
    ft_printf(" %011i ", LONG_MAX);
    ft_printf(" %012i ", LONG_MIN);
    ft_printf(" %013i ", UINT_MAX);
    ft_printf(" %014i ", ULONG_MAX);
    ft_printf(" %015i ", 9223372036854775807LL);
    ft_printf(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n prinft standar\n");
    printf(" %01i ", 0);
    printf(" %02i ", -1);
    printf(" %03i ", 1);
    printf(" %04i ", 9);
    printf(" %01i ", 10);
    printf(" %02i ", -100);
    printf(" %03i ", -101);
    printf(" %09i ", INT_MAX);
    printf(" %010i ", INT_MIN);
    printf(" %011i ", LONG_MAX);
    printf(" %012i ", LONG_MIN);
    printf(" %013i ", UINT_MAX);
    printf(" %014i ", ULONG_MAX);
    printf(" %015i ", 9223372036854775807LL);
    printf(" %09i %010i %011i %012i %013i %014i %015i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n TEST u \n");
    ft_printf(" %01u ", 0);
    ft_printf(" %02u ", -1);
    ft_printf(" %03u ", 1);
    ft_printf(" %04u ", 9);
    ft_printf(" %01u ", 10);
    ft_printf(" %02u ", 11);
    ft_printf(" %03u ", 15);
    ft_printf(" %03u ", -101);
    ft_printf(" %09u ", INT_MAX);
    ft_printf(" %010u ", INT_MIN);
    ft_printf(" %011u ", LONG_MAX);
    ft_printf(" %012u ", LONG_MIN);
    ft_printf(" %013u ", UINT_MAX);
    ft_printf(" %014u ", ULONG_MAX);
    ft_printf(" %015u ", 9223372036854775807LL);
    ft_printf(" %09u %010u %011u %012u %013u %014u %015u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n printf standar\n");
    printf(" %01u ", 0);
    printf(" %02u ", -1);
    printf(" %03u ", 1);
    printf(" %04u ", 9);
    printf(" %01u ", 10);
    printf(" %02u ", 11);
    printf(" %03u ", 15);
    printf(" %03u ", -101);
    printf(" %09u ", INT_MAX);
    printf(" %010u ", INT_MIN);
    printf(" %011u ", LONG_MAX);
    printf(" %012u ", LONG_MIN);
    printf(" %013u ", UINT_MAX);
    printf(" %014u ", ULONG_MAX);
    printf(" %015u ", 9223372036854775807LL);
    printf(" %09u %010u %011u %012u %013u %014u %015u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\nTEST x \n");
    ft_printf(" %02x ", -1);
    ft_printf(" %03x ", 1);
    ft_printf(" %010x ", INT_MIN);
    ft_printf(" %011x ", LONG_MAX);
    ft_printf(" %012x ", LONG_MIN);
    ft_printf(" %013x ", UINT_MAX);
    ft_printf(" %014x ", ULONG_MAX);
    ft_printf(" %015x ", 9223372036854775807LL);
    ft_printf(" %09x %010x %011x %012x %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\n printf standar\n");
    printf(" %02x ", -1);
    printf(" %03x ", 1);
    printf(" %010x ", INT_MIN);
    printf(" %011x ", LONG_MAX);
    printf(" %012x ", LONG_MIN);
    printf(" %013x ", UINT_MAX);
    printf(" %014x ", ULONG_MAX);
    printf(" %015x ", 9223372036854775807LL);
    printf(" %09x %010x %011x %012x %013x %014x %015x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);

    printf("\nTEST X \n");
    ft_printf(" %01X ", 0);
    ft_printf(" %02X ", -1);
    ft_printf(" %03X ", 1);
    ft_printf(" %04X ", 9);
    ft_printf(" %01X ", 10);
    ft_printf(" %02X ", 11);
    ft_printf(" %03X ", 15);
    ft_printf(" %03X ", -101);
    ft_printf(" %09X ", INT_MAX);
    ft_printf(" %010X ", INT_MIN);
    ft_printf(" %011X ", LONG_MAX);
    ft_printf(" %012X ", LONG_MIN);
    ft_printf(" %013X ", UINT_MAX);
    ft_printf(" %014X ", ULONG_MAX);
    ft_printf(" %015X ", 9223372036854775807LL);
    ft_printf(" %09X %010X %011X %012X %013X %014X %015X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
    printf("\nprintf standar\n");
    printf(" %01X ", 0);
    printf(" %02X ", -1);
    printf(" %03X ", 1);
    printf(" %04X ", 9);
    printf(" %01X ", 10);
    printf(" %02X ", 11);
    printf(" %03X ", 15);
    printf(" %03X ", -101);
    printf(" %09X ", INT_MAX);
    printf(" %010X ", INT_MIN);
    printf(" %011X ", LONG_MAX);
    printf(" %012X ", LONG_MIN);
    printf(" %013X ", UINT_MAX);
    printf(" %014X ", ULONG_MAX);
    printf(" %015X ", 9223372036854775807LL);
    printf(" %09X %010X %011X %012X %013X %014X %015X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
}
