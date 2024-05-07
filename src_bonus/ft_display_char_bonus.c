/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:10:05 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:10:11 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
*	 [-][width]
This function displays a single character with proper padding spaces. 
It first retrieves the width value from the t_format structure. If the width 
is greater than 1, it calculates the number of padding spaces needed based 
on whether left justification is enabled. Then, it either displays the 
character followed by padding spaces if left-justified or padding spaces 
followed by the character if right-justified. If the width is 1 or less, 
it simply displays the character without any padding.
*/
void	ft_display_char(t_format *data, int c)
{
	int	width;

	width = data->width_value;
	if (width > 1)
	{
		if (data->left_justified)
		{
			ft_putchar_n((char)c, 1, &(data->chars_written));
			ft_putchar_n(' ', width - 1, &(data->chars_written));
		}
		else
		{
			ft_putchar_n(' ', width - 1, &(data->chars_written));
			ft_putchar_n((char)c, 1, &(data->chars_written));
		}
	}
	else
		ft_putchar_n((char)c, 1, &(data->chars_written));
}
