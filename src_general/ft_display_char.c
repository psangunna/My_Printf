/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:34:12 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:34:16 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
    int width;

    // Obtiene la anchura especificada
    width = data->width_value;

    // Si la anchura es mayor que 1
    if (width > 1)
    {
        // Si la justificación izquierda está activada
        if (data->left_justified)
        {
            // Muestra el carácter y luego rellena con espacios en blanco hasta alcanzar la anchura especificada
            ft_putchar_n((char)c, 1, &(data->chars_written));
            ft_putchar_n(' ', width - 1, &(data->chars_written));
        }
        else // Si la justificación derecha está activada
        {
            // Rellena con espacios en blanco hasta alcanzar la anchura especificada y luego muestra el carácter
            ft_putchar_n(' ', width - 1, &(data->chars_written));
            ft_putchar_n((char)c, 1, &(data->chars_written));
        }
    }
    else // Si la anchura es 1 o menos
    {
        // Simplemente muestra el carácter
        ft_putchar_n((char)c, 1, &(data->chars_written));
    }
}
