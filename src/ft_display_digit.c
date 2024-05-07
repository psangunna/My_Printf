/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:21:00 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:21:04 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function converts an integer value to a string representation in the 
specified base. It recursively divides the value by the base and stores 
the remainder as digits in the temp array of the t_flags structure. 
It also handles negative values by converting them to positive before recursion.
*/
void	itoa_base(t_format *data, t_type_digit value)
{
	t_type_digit	tmp;

	if (data->base < 2 || data->base > 16)
		return ;
	if (data->is_negative && !data->is_converted)
	{
		value.sig_value = -(value.sig_value);
		data->is_converted = 1;
		itoa_base(data, value);
	}
	else if (value.unsig_value < (unsigned long)data->base)
	{
		if (data->upper_case)
			data->temp[data->nbr_len++] = UP_SYMBOLS[value.unsig_value];
		else
			data->temp[data->nbr_len++] = LOW_SYMBOLS[value.unsig_value];
	}
	else
	{
		tmp.unsig_value = value.unsig_value / data->base;
		itoa_base(data, tmp);
		tmp.unsig_value = value.unsig_value % data->base;
		itoa_base(data, tmp);
	}
}

/*
This function adds the '0x' prefix before pointers.
*/
static void	set_0x(t_format *data)
{
	if (data->specifier == 'p' && data->no_value != 1)
		ft_putstr_written("0x", &(data->chars_written));
}

/*
This function handles the display of signs for numbers. 
If the number is a pointer, it calls put_0x to add the prefix. 
If the number is signed, it displays the negative sign for negative numbers, 
*/
static void	put_sign(t_format *data)
{
	if (data->base == 16)
		set_0x(data);
	else if (data->signed_value)
	{
		if (data->is_negative)
			ft_putchar_written('-', &(data->chars_written));
	}
}

/*
This function orchestrates the display of digits. It first converts the 
integer value to a string representation using ft_itoa_base, it  displays 
the sign too.
*/
void	ft_display_digit(t_format *data, t_type_digit values)
{
	if (data->no_value == 0)
		itoa_base(data, values);
	put_sign(data);
	ft_putstr_written(data->temp, &(data->chars_written));
}
