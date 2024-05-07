/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:01:00 by pamela            #+#    #+#             */
/*   Updated: 2024/05/07 10:01:05 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
 * Set zeros to pad
 * Spaces are in function of zeros
 * so i will count zeros before hand
 * 
This function adds the '0x' or '0X' prefix before hexadecimal numbers or
pointers if the hash flag ('#') is set.
*/
static void	set_0x(t_format *data)
{
    // Si el especificador es 'x' o 'X' y la bandera hash está activada y el valor no es cero, o si el especificador es 'p'
    if ((ft_strchr((const char *)"xX", data->specifier) && data->hash && data->temp[0] != '0') || (data->specifier == 'p' && data->no_value == 0))
    {
        // Si el especificador está en mayúsculas, muestra "0X", de lo contrario, muestra "0x"
        if (data->upper_case)
            ft_putstr_n("0X", 2, &(data->chars_written));
        else
            ft_putstr_n("0x", 2, &(data->chars_written));
    }
}

/*
This function handles the display of signs for numbers. 
If the number is hexadecimal, it calls put_0x to add the prefix. 
If the number is signed, it displays the negative sign for negative numbers, 
or '+' for positive numbers if the plus flag ('+') is set, or space padding 
if the space flag (' ') is set.
*/
static void	put_sign(t_format *data)
{
    // Si la base es 16, llama a put_0x para agregar el prefijo '0x' o '0X'
    if (data->base == 16)
        set_0x(data);
    // Si el valor es con signo
    else if (data->signed_value)
    {
        // Si es negativo, muestra el signo '-'
        if (data->is_negative)
            ft_putchar_n('-', 1, &(data->chars_written));
        // Si no es negativo
        else if (!data->is_negative)
        {
            // Si está activada la bandera de signo '+', muestra '+'
            if (data->plus)
                ft_putchar_n('+', 1, &(data->chars_written));
            // Si no está activada la bandera de signo '+' y está activada la bandera de espacio, muestra un espacio en blanco
            else if (!data->plus && data->space)
                ft_putchar_n(' ', 1, &(data->chars_written));
        }
    }
}
/*
This function orchestrates the display of digits. It first converts the 
integer value to a string representation using ft_itoa_base, then calculates
zero padding and space padding using ft_set_padding_zeros and 
ft_set_padding_spaces, respectively. Depending on whether left justification 
is enabled, it then displays the sign, zero padding, the digit itself, and 
finally space padding.
*/
void	ft_display_digit(t_format *data, t_type_digit values)
{
    // Convierte el valor entero a una representación de cadena y almacena el resultado en data->temp
    
    if (data->no_value == 0)
        ft_itoa_base(data, values);
    // Calcula el padding de ceros
    ft_set_padding_zeros(data);
    // Calcula el padding de espacios
    ft_set_padding_spaces(data);
    
    // Si la justificación izquierda está activada
    if (data->left_justified)
    {
        // Muestra el signo, el padding de ceros, el dígito y el padding de espacios
        put_sign(data);
        ft_putchar_n('0', data->padding_zeros, &(data->chars_written));
        ft_putstr_n(data->temp, data->nbr_len, &(data->chars_written));
        ft_putchar_n(' ', data->padding_spaces, &(data->chars_written));
    }
    else // Si la justificación derecha está activada
    {
        // Muestra el padding de espacios, el signo, el padding de ceros, y el dígito
        ft_putchar_n(' ', data->padding_spaces, &(data->chars_written));
        put_sign(data);
        ft_putchar_n('0', data->padding_zeros, &(data->chars_written));
        ft_putstr_n(data->temp, data->nbr_len, &(data->chars_written));
    }
}
