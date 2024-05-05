/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:13:49 by pamela            #+#    #+#             */
/*   Updated: 2024/05/05 22:13:53 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putchar_written(char c, int	*chars_written)
{
	*chars_written += write(1, &c, 1);
}

/*
 * Function to write a char n times
 * useful for padding with '0' or ' '
*/
void	ft_putchar_n(char c, int precision, int *chars_written)
{
	if (precision <= 0)
		return ;
	while (precision--)
		ft_putchar_written(c, chars_written);
}

/*
 *Function to write a str with a refined control
 *over precision
 */
void	ft_putstr_n(char *s, int precision, int *chars_written)
{
	if (precision <= 0)
		return ;
	while (precision-- && *s)
		ft_putchar_written(*s++, chars_written);
}
