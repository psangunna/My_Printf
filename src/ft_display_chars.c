/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_chars.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:16:04 by pamela            #+#    #+#             */
/*   Updated: 2024/05/05 19:17:05 by pamela           ###   ########.fr       */
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
