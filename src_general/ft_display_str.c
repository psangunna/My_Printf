/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:34:49 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:34:55 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function calculates the number of space characters needed for padding
before the string. It considers the width and precision values specified in 
the t_format structure. If precision is specified and is less than the length 
of the string, it calculates padding spaces based on the precision value. 
Otherwise, it calculates padding spaces based on the length of the string.
*/
static void	set_str_padding_spaces(t_format *data, char *s)
{
    int len;

    // Obtiene la longitud de la cadena
    len = ft_strlen(s);
    
    // Si se especifica una anchura
    if (data->width_value > 0)
    {
        // Si se especifica una precisión
        if (data->precision_value >= 0)
        {
            // Si la precisión es mayor que la longitud de la cadena
            if (data->precision_value > len)
            {
                // Calcula el padding de espacios como la diferencia entre la anchura y la longitud de la cadena
                data->padding_spaces = data->width_value - len;
            }
            // Si la precisión es menor que la longitud de la cadena
            else if (data->precision_value < len)
            {
                // Calcula el padding de espacios como la diferencia entre la anchura y la precisión
                data->padding_spaces = data->width_value - data->precision_value;
            }
        }
        else // Si no se especifica una precisión
        {
            // Calcula el padding de espacios como la diferencia entre la anchura y la longitud de la cadena
            data->padding_spaces = data->width_value - len;
        }
    }
}

/*
* [0+ #] 
 *  
 *	I care about these:
 *  	[-]   [width]    [.precision]
 This function displays the string with proper padding spaces.
 If the string is NULL, it defaults to "(null)". It first calculates 
 the padding spaces using set_str_padding_spaces. Depending on whether 
 left justification is enabled, it either displays the string followed 
 by padding spaces, or padding spaces followed by the string
*/
void	ft_display_str(t_format *data, char *s)
{
    // Si la cadena es NULL, la asigna a "(null)"
    if (s == NULL)
        s = "(null)";
    
    // Calcula el padding de espacios
    set_str_padding_spaces(data, s);
    
    // Si la justificación izquierda está activada
    if (data->left_justified)
    {
        // Si se especifica una precisión, muestra la cadena truncada según la precisión
        if (data->precision_value >= 0)
            ft_putstr_n(s, data->precision_value, &(data->chars_written));
        else // Si no se especifica una precisión, muestra la cadena completa
            ft_putstr_n(s, ft_strlen(s), &(data->chars_written));
        
        // Muestra el padding de espacios después de la cadena
        ft_putchar_n(' ', data->padding_spaces, &(data->chars_written));
    }
    else // Si la justificación derecha está activada
    {
        // Muestra el padding de espacios antes de la cadena
        ft_putchar_n(' ', data->padding_spaces, &(data->chars_written));
        
        // Si se especifica una precisión, muestra la cadena truncada según la precisión
        if (data->precision_value >= 0)
            ft_putstr_n(s, data->precision_value, &(data->chars_written));
        else // Si no se especifica una precisión, muestra la cadena completa
            ft_putstr_n(s, ft_strlen(s), &(data->chars_written));
    }
}
