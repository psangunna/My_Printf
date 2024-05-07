/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:20:45 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:20:48 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar_written(char c, int	*chars_written)
{
	*chars_written += write(1, &c, 1);
}

void	ft_putstr_written(char *s, int *chars_written)
{
	while (*s)
		ft_putchar_written(*s++, chars_written);
}
