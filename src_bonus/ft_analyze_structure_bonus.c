/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_structure_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:09:20 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:09:25 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
This function iterates through the format string to identify and process 
format flags. It sets corresponding flags in the t_fomat structure based 
on the founded flags.
*/
static void	analyze_flags(t_format *data, const char **str)
{
	char	flag;

	while (ft_strchr((const char *)FLAGS, **str))
	{
		flag = **str;
		if (flag == '0')
			data->zero_pad = 1;
		else if (flag == '+')
			data->plus = 1;
		else if (flag == ' ')
			data->space = 1;
		else if (flag == '#')
			data->hash = 1;
		else if (flag == '-')
			data->left_justified = 1;
		(*str)++;
	}
}

/*
*This function extracts an integer value from the format string.
It parses numeric characters and constructs the corresponding integer value.
*/
static int	get_value_atoi(const char **str)
{
	int	value;

	value = 0;
	while (ft_strchr((char const *)NUMBERS, **str))
	{
		value = (value * 10) + (**str - '0');
		(*str)++;
	}
	return (value);
}

/*
This function retrieves a value associated with the format,
such as width or precision. It either extracts the value 
from the format string or retrieves it from the variable 
arguments list using va_arg
*/
static void	get_value(int *value, const char **str, va_list *args)
{
	if (**str == '*')
	{
		*value = va_arg(*args, int);
		(*str)++;
		return ;
	}
	*value = get_value_atoi(str);
}

/*
This main function orchestrates the analysis of the format string. 
It utilizes the aforementioned functions to process flags and values,
identifies the format specifier, and sets relevant properties in the 
t_fomat structure.
*/
int	ft_analyze_structure(t_format *data, const char **str, va_list *args)
{
	data->precision_value = -1;
	analyze_flags(data, str);
	get_value(&data->width_value, str, args);
	if (**str == '.' && *(++*str))
		get_value(&data->precision_value, str, args);
	if (!ft_strchr((const char *)SPECIFIERS, **str))
	{
		ft_putchar_written('%', &data->chars_written);
		return (-1);
	}
	else
	{
		data->specifier = **str;
		if (ft_strchr((const char *)"diu", data->specifier))
			data->base = 10;
		else if (ft_strchr((const char *)"xXp", data->specifier))
		{
			data->base = 16;
			if ('X' == data->specifier)
				data->upper_case = 1;
		}
	}
	return (0);
}
