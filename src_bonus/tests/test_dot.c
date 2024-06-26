/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_dot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:14:18 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:14:21 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{
	int c;

	ft_printf("\n%.s", "");
	ft_printf("\n %.1s", "");
	ft_printf("\n%.1s ", "");
	ft_printf("\n %.s ", "");
	ft_printf("\n %.s ", "-");
	ft_printf("\n %.2s %.1s ", "", "-");
	ft_printf("\n %.3s %.2s ", " - ", "");
	ft_printf("\n %.1s %.2s %.3s %.4s ", " - ", "", "4", "");
	ft_printf("\n %.2s %.3s %.4s %.5s %.1s ", " - ", "", "4", "", "2 ");
	ft_printf("\n %.1d ", 0);
	ft_printf("\n %.2d ", -1);
	ft_printf("\n %.2d ", 1);
	ft_printf("\n %.1d ", 9);
	ft_printf("\n %.2d ", 10);
	ft_printf("\n %.3d ", 11);
	ft_printf("\n %.4d ", 15);
	ft_printf("\n %.5d ", 16);
	ft_printf("\n %.6d ", 17);
	ft_printf("\n %.1d ", 99);
	ft_printf("\n %.2d ", 100);
	ft_printf("\n %.3d ", 101);
	ft_printf("\n %.1d ", -9);
	ft_printf("\n %.2d ", -10);
	ft_printf("\n %.3d ", -11);
	ft_printf("\n %.4d ", -14);
	ft_printf("\n %.1d ", -15);
	ft_printf("\n %.2d ", -16);
	ft_printf("\n %.3d ", -99);
	ft_printf("\n %.3d ", -100);
	ft_printf("\n %.4d ", -101);
	ft_printf("\n %.8d ", INT_MAX);
	ft_printf("\n %.9d ", INT_MIN);
	ft_printf("\n %.10d ", LONG_MAX);
	ft_printf("\n %.11d ", LONG_MIN);
	ft_printf("\n %.12d ", UINT_MAX);
	ft_printf("\n %.13d ", ULONG_MAX);
	ft_printf("\n %.14d ", 9223372036854775807LL);
	ft_printf("\n %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n %.8d %.9d %.10d %.11d %.12d %.13d %.14d", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("\n %.1i ", 0);
	ft_printf("\n %.2i ", -1);
	ft_printf("\n %.2i ", 1);
	ft_printf("\n %.1i ", 9);
	ft_printf("\n %.2i ", 10);
	ft_printf("\n %.3i ", 11);
	ft_printf("\n %.4i ", 15);
	ft_printf("\n %.3i ", 101);
	ft_printf("\n %.1i ", -9);
	ft_printf("\n %.2i ", -10);
	ft_printf("\n %.3i ", -11);
	ft_printf("\n %.4i ", -14);
	ft_printf("\n %.3i ", -100);
	ft_printf("\n %.4i ", -101);
	ft_printf("\n %.8i ", INT_MAX);
	ft_printf("\n %.9i ", INT_MIN);
	ft_printf("\n %.10i ", LONG_MAX);
	ft_printf("\n %.11i ", LONG_MIN);
	ft_printf("\n %.12i ", UINT_MAX);
	ft_printf("\n %.13i ", ULONG_MAX);
	ft_printf("\n %.14i ", 9223372036854775807LL);
	ft_printf("\n %.8i %.9i %.10i %.11i %.12i %.13i %.14i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX);
	printf("\n %.8i %.9i %.10i %.11i %.12i %.13i %.14i", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX);
	ft_printf("\n %.1u ", 0);
	ft_printf("\n %.2u ", -1);
	ft_printf("\n %.2u ", 1);
	ft_printf("\n %.1u ", 9);
	ft_printf("\n %.2u ", 10);
	ft_printf("\n %.3u ", 11);
	ft_printf("\n %.4u ", 15);
	ft_printf("\n %.5u ", 16);
	ft_printf("\n %.6u ", 17);
	ft_printf("\n %.1u ", 99);
	ft_printf("\n %.2u ", 100);
	ft_printf("\n %.3u ", 101);
	ft_printf("\n %.1u ", -9);
	ft_printf("\n %.2u ", -10);
	ft_printf("\n %.3u ", -11);
	ft_printf("\n %.4u ", -14);
	ft_printf("\n %.1u ", -15);
	ft_printf("\n %.2u ", -16);
	ft_printf("\n %.3u ", -99);
	ft_printf("\n %.3u ", -100);
	ft_printf("\n %.4u ", -101);
	ft_printf("\n %.8u ", INT_MAX);
	ft_printf("\n %.9u ", INT_MIN);
	ft_printf("\n %.10u ", LONG_MAX);
	ft_printf("\n %.11u ", LONG_MIN);
	ft_printf("\n %.12u ", UINT_MAX);
	ft_printf("\n %.13u ", ULONG_MAX);
	ft_printf("\n %.14u ", 9223372036854775807LL);
	ft_printf("\n %.8u %.9u %.10u %.11u %.12u %.13u %.14u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX);
	printf("\n %.8u %.9u %.10u %.11u %.12u %.13u %.14u", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX);
	ft_printf("\n %.2x ", -1);
	ft_printf("\n %.2x ", 1);
	ft_printf("\n %.1x ", 9);
	ft_printf("\n %.2x ", 10);
	ft_printf("\n %.3x ", 11);
	ft_printf("\n %.4x ", 15);
	ft_printf("\n %.5x ", 16);
	ft_printf("\n %.6x ", 17);
	ft_printf("\n %.1x ", 99);
	ft_printf("\n %.2x ", 100);
	ft_printf("\n %.3x ", 101);
	ft_printf("\n %.1x ", -9);
	ft_printf("\n %.2x ", -10);
	ft_printf("\n %.3x ", -11);
	ft_printf("\n %.4x ", -14);
	ft_printf("\n %.1x ", -15);
	ft_printf("\n %.2x ", -16);
	ft_printf("\n %.3x ", -99);
	ft_printf("\n %.3x ", -100);
	ft_printf("\n %.4x ", -101);
	ft_printf("\n %.8x ", INT_MAX);
	ft_printf("\n %.9x ", INT_MIN);
	ft_printf("\n %.10x ", LONG_MAX);
	ft_printf("\n %.11x ", LONG_MIN);
	ft_printf("\n %.12x ", UINT_MAX); 
	ft_printf("\n %.13x ", ULONG_MAX); 
	ft_printf("\n %.14x ", 9223372036854775807LL); 
	ft_printf("\n %.8x %.9x %.10x %.11x %.12x %.13x %.14x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n %.8x %.9x %.10x %.11x %.12x %.13x %.14x", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf("\n %.1X ", 0);
	ft_printf("\n %.2X ", -1);
	ft_printf("\n %.2X ", 1);
	ft_printf("\n %.1X ", 9);
	ft_printf("\n %.2X ", 10);
	ft_printf("\n %.3X ", 11);
	ft_printf("\n %.4X ", 15);
	ft_printf("\n %.5X ", 16);
	ft_printf("\n %.6X ", 17);
	ft_printf("\n %.1X ", 99);
	ft_printf("\n %.2X ", 100);
	ft_printf("\n %.3X ", 101);
	ft_printf("\n %.1X ", -9);
	ft_printf("\n %.2X ", -10);
	ft_printf("\n %.3X ", -11);
	ft_printf("\n %.4X ", -14);
	ft_printf("\n %.1X ", -15);
	ft_printf("\n %.2X ", -16);
	ft_printf("\n %.3X ", -99);
	ft_printf("\n %.3X ", -100);
	ft_printf("\n %.4X ", -101);
	ft_printf("\n %.8X ", INT_MAX);
	ft_printf("\n %.9X ", INT_MIN);
	ft_printf("\n %.10X ", LONG_MAX);
	ft_printf("\n %.11X ", LONG_MIN);
	ft_printf("\n %.12X ", UINT_MAX);
	ft_printf("\n %.13X ", ULONG_MAX);
	ft_printf("\n %.14X ", 9223372036854775807LL);
	ft_printf("\n %.8X %.9X %.10X %.11X %.12X %.13X %.14X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	printf("\n %.8X %.9X %.10X %.11X %.12X %.13X %.14X", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	return (0);
}
