/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 22:10:42 by pamela            #+#    #+#             */
/*   Updated: 2024/05/05 22:10:45 by pamela           ###   ########.fr       */
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
