/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:17:22 by pamela            #+#    #+#             */
/*   Updated: 2024/04/25 18:49:02 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int	count;
	int	num;
	int	*pointer;

	count = ft_printf("Hello %-0.10s\n", "Jonh");
	count = printf("Hello [% -10c]\n", 'd');
	printf("Count:%d\n", count);
	count = ft_printf("Hello [% -10c]\n", 'd');
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
	count = printf("MyCount:%d\n", count);
	count = printf("%*c\n", 10, 'g');
	count = printf("Count:%d\n", count);
	count = ft_printf("%*c\n", 10, 'g');
	count = printf("MyCount:%d\n", count);
	count = printf("%*i\n%d\n", 10, 23, 50);
	count = printf("Count:%d\n", count);
	count = ft_printf("%*i\n%d\n", 10, 23, 50);
	count = printf("MyCount:%d\n", count);
	count = printf("%*s\n", 10, "gata");
	count = printf("Count:%d\n", count);
	count = ft_printf("%*s\n", 10, "gata");
	count = printf("MyCount:%d\n", count);
	return (0);
}
