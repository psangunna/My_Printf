/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:22:08 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:22:11 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function initializes a structure t_data which contains various data and
values used for formatting output in the ft_printf function.
*/
static void	init_data(t_format *data)
{
	data->specifier = 0;
	data->upper_case = 0;
	data->base = 0;
	data->signed_value = 0;
	data->is_negative = 0;
	data->is_converted = 0;
	data->nbr_len = 0;
	data->no_value = 0;
	ft_memset(data->temp, 0, sizeof(data->temp));
}

/*
This is the main ft_printf function. 
It iterates through the input string str, processing it character by character. 
When it encounters a '%' character, it assumes a format specifier is coming up
next and calls init_data to initialize the data structure. Then it analyzes 
the format specifier using ft_analyze_structure, which updates the data 
structure. 
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
			init_data(&format);
			if (!ft_analyze_structure(&format, &str))
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
