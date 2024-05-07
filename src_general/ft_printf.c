/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 10:02:16 by pamela            #+#    #+#             */
/*   Updated: 2024/05/07 10:02:18 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function initializes a structure t_format which contains various flags and
values used for formatting output in the ft_printf function.
*/
static void	init_format(t_format *flags)
{
	flags->left_justified = 0;
	flags->plus = 0;
	flags->space = 0;
	flags->hash = 0;
	flags->zero_pad = 0;
	flags->specifier = 0;
	flags->width_value = 0;
	flags->precision_value = -1;
	flags->upper_case = 0;
	flags->base = 0;
	flags->padding_spaces = 0;
	flags->padding_zeros = 0;
	flags->signed_value = 0;
	flags->is_negative = 0;
	flags->is_converted = 0;
	flags->nbr_len = 0;
	ft_memset(flags->temp, 0, sizeof(flags->temp));
}

/*
This is the main ft_printf function. 
It iterates through the input string str, processing it character by character. 
When it encounters a '%' character, it assumes a format specifier is coming up
next and calls init_format to initialize the flags structure. Then it analyzes 
the format specifier using ft_analyze_structure, which updates the flags 
structure based on the specifier and additional arguments. 
Finally, it displays the formatted output using ft_display_structure. 
If it encounters a character that is not a '%', it simply outputs it. 
After processing the entire input string, it returns the total number of 
characters written.
*/
int ft_printf(const char *str, ...)
{
    // Declaración de variables locales
    t_format flags;  // Estructura que contiene información sobre las banderas de formato
    va_list args;   // Lista de argumentos variables

    // Inicialización del contador de caracteres escritos
    flags.chars_written = 0;
    // Inicialización de la lista de argumentos variables
    va_start(args, str);

    // Bucle principal que recorre la cadena de formato
    while (*str)
    {
        if (*str == '%' && (*(str + 1) != '\0')) // Si encontramos un indicador de formato
        {
            str++;  // Avanza un carácter para analizar el siguiente después del '%'
            init_format(&flags);  // Inicializa la estructura de banderas para el formato actual
            // Analiza la estructura del formato y actualiza las banderas correspondientes
            if (!ft_analyze_structure(&flags, &str, &args))
                // Si la estructura del formato es válida, muestra el formato tal cual
                ft_display_structure(&flags, &args);
            else
                ft_putchar_written(*str, &flags.chars_written);
        }
        else
        {
            // Si no es un indicador de formato, simplemente escribe el carácter
            ft_putchar_written(*str, &flags.chars_written);
        }
        str++;  // Avanza al siguiente carácter en la cadena de formato
    }

    // Finalización del uso de la lista de argumentos variables
    va_end(args);

    // Devuelve el número total de caracteres escritos
    return (flags.chars_written);
}
