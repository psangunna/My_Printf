/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:14:09 by pamela            #+#    #+#             */
/*   Updated: 2024/05/05 22:16:35 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
This function initializes a structure t_format which contains various format and
values used for formatting output in the ft_printf function.
*/
static void	init_format(t_format *format)
{
	format->left_justified = 0;
	format->plus = 0;
	format->space = 0;
	format->hash = 0;
	format->zero_pad = 0;
	format->specifier = 0;
	format->width_value = 0;
	format->precision_value = -1;
	format->upper_case = 0;
	format->base = 0;
	format->padding_spaces = 0;
	format->padding_zeros = 0;
	format->signed_value = 0;
	format->is_negative = 0;
	format->is_converted = 0;
	format->nbr_len = 0;
	format->no_value = 0;
	ft_memset(format->temp, 0, sizeof(format->temp));
}

/*
This is the main ft_printf function. 
It iterates through the input string str, processing it character by character. 
When it encounters a '%' character, it assumes a format specifier is coming up
next and calls init_format to initialize the format structure. Then it analyzes 
the format specifier using ft_analyze_structure, which updates the format 
structure based on the specifier and additional arguments. 
Finally, it displays the formatted output using ft_display_structure. 
If it encounters a character that is not a '%', it simply outputs it. 
After processing the entire input string, it returns the total number of 
characters written.
*/
int	ft_printf(const char *str, ...)
{
	t_format	format;
	va_list		args;

	format.chars_written = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && (*(str + 1) != '\0'))
		{
			str++;
			init_format(&format);
			if (!ft_analyze_structure(&format, &str, &args))
				ft_display_structure(&format, &args);
			else
				ft_putchar_written(*str, &format.chars_written);
		}
		else
		{
			ft_putchar_written(*str, &format.chars_written);
		}
		str++;
	}
	va_end(args);
	return (format.chars_written);
}
