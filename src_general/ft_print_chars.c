/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_chars.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:35:55 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:35:57 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
 * Function to write a char n when
 * the flag are not the expected values
*/
/*void	ft_putstr_aux(const char **s, int *chars_written)
{
	const char	*temp;

	temp = *s;
	while (*temp && *temp != '%')
	{
		ft_putchar_written(*temp, chars_written);
		temp++;
	}
	if (*temp == '%')
	{
		if (*(temp + 1) != '\0')
		{
			temp--;
		}
		else
		{
			ft_putchar_written('%', chars_written);
		}
	}
	*s = temp;
}*/

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
