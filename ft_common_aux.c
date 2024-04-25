/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_common_aux.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:22:53 by pamela            #+#    #+#             */
/*   Updated: 2024/04/25 18:44:09 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != (char)c)
	{
		str++;
	}
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter] != '\0')
	{
		counter++;
	}
	return (counter);
}

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
