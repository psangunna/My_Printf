/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:14:03 by pamela            #+#    #+#             */
/*   Updated: 2024/05/05 19:14:08 by pamela           ###   ########.fr       */
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
