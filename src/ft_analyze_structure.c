/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_structure.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:16:26 by pamela            #+#    #+#             */
/*   Updated: 2024/05/05 19:16:38 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
The function ft_analyze_structure examines a format string, checking if the 
current character is a valid specifier. If it's not, it prints '%' and updates
a count, returning -1. If it is, it records the specifier and determines the 
base (either 10 or 16) for numerical conversions. If the specifier is 'X', 
it sets a flag for uppercase formatting. The function returns 0 upon successful 
analysis
*/
int	ft_analyze_structure(t_format *data, const char **str)
{
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
