/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:31:09 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:31:16 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	
#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main(void)
{  
	int	c;

	ft_printf("%c\n", '0');
	ft_printf(" %c \n", '0');
	ft_printf(" %c\n", '0' - 256);
	ft_printf("%c \n", '0' + 256);
	c = ft_printf(" %c %c %c \n", '0', 0, '1');
	printf("\nCount%i\n", c);
	ft_printf(" %c %c %c \n", ' ', ' ', ' ');
	c = ft_printf(" %c %c %c \n", '1', '2', '3');
	printf("\nmyCount%i\n", c);
	ft_printf(" %c %c %c \n", '2', '1', 0);
	ft_printf(" %c %c %c \n", 0, '1', '2');
	c = ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\nmyCount%i\n", c);
	
	printf("\nPrintf standar\n");	
	printf("%c\n", '0');
	printf(" %c \n", '0');
	printf(" %c\n", '0' - 256);
	printf("%c \n", '0' + 256);
	c = printf(" %c %c %c \n", '0', 0, '1');
	printf("\nCount%i\n", c);
	c = printf(" %c %c %c \n", '1', '2', '3');
	printf("\nCount%i\n", c);
	printf(" %c %c %c \n", '2', '1', 0);
	printf(" %c %c %c \n", 0, '1', '2');
	c = printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
	printf("\nCount%i\n", c);
	return (0);
}
