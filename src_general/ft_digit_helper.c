/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:00:35 by pamela            #+#    #+#             */
/*   Updated: 2024/05/07 10:00:38 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function converts an integer value to a string representation in the 
specified base. It recursively divides the value by the base and stores 
the remainder as digits in the temp array of the t_format structure. 
It also handles negative values by converting them to positive before recursion.
*/
void	ft_itoa_base(t_format *data, t_type_digit value)
{
    t_type_digit tmp;

    // Verifica si la base está en el rango permitido
    if (data->base < 2 || data->base > 16)
        return;
    
    // Si el valor es negativo y aún no se ha convertido
    if (data->is_negative && !data->is_converted)
    {
        // Convierte el valor a positivo y marca que se ha convertido
        value.sig_value = -(value.sig_value);
        data->is_converted = 1;
        ft_itoa_base(data, value);
    }
    else if (value.unsig_value < (unsigned long)data->base)
    {
        // Si el valor es menor que la base, simplemente añade el dígito a la cadena resultante
        if (data->upper_case)
            data->temp[data->nbr_len++] = UP_SYMBOLS[value.unsig_value];
        else
            data->temp[data->nbr_len++] = LOW_SYMBOLS[value.unsig_value];
    }
    else
    {
        // Si el valor es mayor o igual que la base, divide y continúa convirtiendo recursivamente
        tmp.unsig_value = value.unsig_value / data->base;
        ft_itoa_base(data, tmp);
        tmp.unsig_value = value.unsig_value % data->base;
        ft_itoa_base(data, tmp);
    }
}
/*
256 
256/10 -->25--> 25/10 -->2 --> 2 < 10 -->pinta 2 |
256%10 -->6     25%10 --> 5 <--------------------| 
*/

/*
This function calculates the number of zero padding digits required based
on various conditions such as left justification, width, hash flags ('#'), 
and whether the number is negative.
*/
static void	set_zero_pad(t_format *data)
{
    // Si está habilitada la justificación izquierda, no se realiza ningún ajuste de ceros
    if (data->left_justified)
        return;

    // Calcula la cantidad de ceros de relleno basados en la longitud de la cadena y la anchura especificada
    if (data->width_value > data->nbr_len)
        data->padding_zeros = data->width_value - data->nbr_len;
    
    // Ajusta la cantidad de ceros de relleno para casos especiales como números hexadecimales con prefijo "0x" o "0X"
    if (data->specifier == 'u')
        return;
    else if ((ft_strchr((const char *)"xX", data->specifier) && data->hash && data->temp[0] != '0') || (data->specifier == 'p' && data->no_value == 0))
        data->padding_zeros -= 2;
    else if (data->is_negative || (!data->is_negative && (data->plus || data->space)))
        data->padding_zeros--;
}

/*
This function determines the number of zero padding digits required based 
on the precision value and zero padding flag. It calls set_zero_pad if zero
padding is enabled.
*/
void	ft_set_padding_zeros(t_format *data)
{
    // Si se especifica una precisión y es mayor que la longitud de la cadena, calcula la cantidad de ceros de relleno necesarios
    if (data->precision_value >= 0)
    {
        if (data->precision_value >= data->nbr_len)
        {
            data->padding_zeros = data->precision_value - data->nbr_len;
            return;
        }
    }

    // Si está habilitado el relleno con ceros, ajusta la cantidad de ceros de relleno
    if (data->zero_pad)
    {
        set_zero_pad(data);
    }

    // Asegura que la cantidad de ceros de relleno no sea negativa
    if (data->padding_zeros < 0)
        data->padding_zeros = 0;
}

/*
This function calculates the number of space characters needed for padding 
based on the width value, zero padding digits, and other conditions such as 
the presence of hash flags, negative numbers, and special cases like pointers.
*/
void ft_set_padding_spaces(t_format *data)
{
    // Calcula la cantidad de espacios de relleno basados en la anchura especificada, los ceros de relleno y otras condiciones
    data->padding_spaces = data->width_value - data->padding_zeros - data->nbr_len;

    // Ajusta la cantidad de espacios de relleno para casos especiales como números hexadecimales con prefijo "0x" o "0X"
    if (ft_strchr((const char *)"uxXp", data->specifier))
    {
        if ((ft_strchr((const char *)"xX", data->specifier) && data->hash && data->temp[0] != '0') || (data->specifier == 'p' && data->no_value == 0))
        return;
    }

    // Ajusta la cantidad de espacios de relleno para números negativos o números positivos con signo '+' o espacio en blanco
    if (data->is_negative)
    {
        data->padding_spaces--;
        return;
    }
    if (!data->is_negative && data->plus)
    {
        data->padding_spaces--;
        return;
    }
    if (!data->is_negative && data->space)
    {
        data->padding_spaces--;
        return;
    }
}
