/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disdigit_aux.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:24:39 by pamela            #+#    #+#             */
/*   Updated: 2024/04/27 14:56:25 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function converts an integer value to a string representation in the 
specified base. It recursively divides the value by the base and stores 
the remainder as digits in the temp array of the t_flags structure. 
It also handles negative values by converting them to positive before recursion.
*/
void	ft_itoa_base(t_flags *data, t_type_digit value)
{
	t_type_digit	tmp;

	if (data->base < 2 || data->base > 16)
		return ;
	if (data->is_negative && !data->is_converted)
	{
		value.sig_value = -(value.sig_value);
		data->is_converted = 1;
		ft_itoa_base(data, value);
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
		ft_itoa_base(data, tmp);
		tmp.unsig_value = value.unsig_value % data->base;
		ft_itoa_base(data, tmp);
	}
}

/*
This function calculates the number of zero padding digits required based
on various conditions such as left justification, width, hash flags ('#'), 
and whether the number is negative.
*/
static void	set_zero_pad(t_flags *data)
{
	if (data->left_justified)
		return ;
	if (data->width_value > data->nbr_len)
		data->padding_zeros = data->width_value - data->nbr_len;
	if (data->specifier == 'u')
		return ;
	else if ((ft_strchr((const char *)"xX", data->specifier) && \
		data->hash && data->temp[0] != '0') || \
		data->specifier == 'p')
		data->padding_zeros -= 2;
	else if (data->is_negative || (!data->is_negative && \
				(data->plus || data->space)))
		data->padding_zeros--;
}

/*
This function determines the number of zero padding digits required based 
on the precision value and zero padding flag. It calls set_zero_pad if zero
padding is enabled.
*/
void	ft_set_padding_zeros(t_flags *data)
{
	if (data->precision_value >= 0)
	{
		if (data->precision_value >= data->nbr_len)
		{
			data->padding_zeros = data->precision_value - data->nbr_len;
			return ;
		}
	}
	if (data->zero_pad)
	{
		set_zero_pad(data);
	}
	if (data->padding_zeros < 0)
		data->padding_zeros = 0;
}

/*
This function calculates the number of space characters needed for padding 
based on the width value, zero padding digits, and other conditions such as 
the presence of hash flags, negative numbers, and special cases like pointers.
*/
void	ft_set_padding_spaces(t_flags *data)
{
	data->padding_spaces = data->width_value - data->padding_zeros - \
			data->nbr_len;
	if (ft_strchr((const char *)"uxXp", data->specifier))
	{
		if ((ft_strchr((const char *)"xX", data->specifier) && data->hash \
					&& data->temp[0] != '0') || data->specifier == 'p')
			data->padding_spaces -= 2;
		return ;
	}
	if (data->is_negative)
	{
		data->padding_spaces--;
		return ;
	}
	if (!data->is_negative && data->plus)
	{
		data->padding_spaces--;
		return ;
	}
	if (!data->is_negative && data->space)
	{
		data->padding_spaces--;
		return ;
	}
}
