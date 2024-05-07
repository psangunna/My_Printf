/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:21:21 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:21:27 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 This function displays the string.
 If the string is NULL, it defaults to "(null)".
*/
void	ft_display_str(t_format *data, char *s)
{
	if (s == NULL)
		s = "(null)";
	ft_putstr_written(s, &data->chars_written);
}
