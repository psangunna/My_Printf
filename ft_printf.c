/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 17:17:14 by pamela            #+#    #+#             */
/*   Updated: 2024/05/03 14:19:39 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function initializes a structure t_flags which contains various flags and
values used for formatting output in the ft_printf function.
*/
static void	init_flags(t_flags *flags)
{
	flags->left_justified = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero_pad = 0;
	flags->specifier = 0;
	flags->width_value = 0;
	flags->precision_value = -1;
	flags->upper_case = 0;
	flags->base = 0;
	flags->padding_spaces = 0;
	flags->padding_zeros = 0;
	flags->signed_value = 0;
	flags->is_negative = 0;
	flags->is_converted = 0;
	flags->nbr_len = 0;
	flags->no_value = 0;
	ft_memset(flags->temp, 0, sizeof(flags->temp));
}

/*
This is the main ft_printf function. 
It iterates through the input string str, processing it character by character. 
When it encounters a '%' character, it assumes a format specifier is coming up
next and calls init_flags to initialize the flags structure. Then it analyzes 
the format specifier using ft_analyze_structure, which updates the flags 
structure based on the specifier and additional arguments. 
Finally, it displays the formatted output using ft_display_structure. 
If it encounters a character that is not a '%', it simply outputs it. 
After processing the entire input string, it returns the total number of 
characters written.
*/
int	ft_printf(const char *str, ...)
{
	t_flags	flags;
	va_list	args;

	flags.chars_written = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && (*(str + 1) != '\0'))
		{
			str++;
			init_flags(&flags);
			if (!ft_analyze_structure(&flags, &str, &args))
				ft_display_structure(&flags, &args);
			else
				ft_putchar_written(*str, &flags.chars_written);
		}
		else
		{
			ft_putchar_written(*str, &flags.chars_written);
		}
		str++;
	}
	va_end(args);
	return (flags.chars_written);
}
