/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_analyze_structure.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 09:59:50 by pamela            #+#    #+#             */
/*   Updated: 2024/05/07 09:59:55 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
This function iterates through the format string to identify and process 
format flags. It sets corresponding flags in the t_format structure based 
on the founded flags.
*/
static void analyze_flags(t_format *data, const char **str)
{
    char flag;

    // Bucle que verifica y analiza las banderas presentes en el formato
    while (ft_strchr((const char *)FLAGS, **str))
    {
        flag = **str;
        // Determina qué bandera está presente y actualiza la estructura de datos correspondiente
        if ('0' == flag)
            data->zero_pad = 1;
        else if ('+' == flag)
            data->plus = 1;
        else if (' ' == flag)
            data->space = 1;
        else if ('#' == flag)
            data->hash = 1;
        else if ('-' == flag)
            data->left_justified = 1;
        (*str)++; // Avanza al siguiente carácter en el formato
    }
}

/*
*This function extracts an integer value from the format string.
It parses numeric characters and constructs the corresponding integer value.
*/
static int get_value_atoi(const char **str)
{
    int value = 0;
    // Bucle que parsea caracteres numéricos y construye el valor entero correspondiente
    while (ft_strchr((char const *)NUMBERS, **str))
    {
        value = (value * 10) + (**str - '0');
        (*str)++; // Avanza al siguiente carácter en la cadena de formato
    }
    return (value); // Retorna el valor entero obtenido
}


/*
This function retrieves a value associated with the format,
such as width or precision. It either extracts the value 
from the format string or retrieves it from the variable 
arguments list using va_arg
*/
static void get_value(int *value, const char **str, va_list *args)
{
    if (**str == '*')
    {
        // Si el carácter es '*', obtiene el valor de la lista de argumentos variables
        *value = va_arg(*args, int);
        ++*str; // Avanza al siguiente carácter en el formato
        return ;
    }
    // Si no es '*', obtiene el valor utilizando la función get_value_atoi
    *value = get_value_atoi(str);
}

/*
This main function orchestrates the analysis of the format string. 
It utilizes the aforementioned functions to process flags and values,
identifies the format specifier, and sets relevant properties in the 
t_format structure.
*/
int ft_analyze_structure(t_format *data, const char **str, va_list *args)
{
    // Inicializa la precisión a -1
    data->precision_value = -1;
    
    // Analiza las banderas de formato presentes en el formato y actualiza la estructura de datos
    analyze_flags(data, str);
    
    // Obtiene el valor de la anchura del campo
    get_value(&data->width_value, str, args);
    
    // Verifica si se indica la precisión y obtiene su valor si está presente
    if (**str == '.' && *(++*str))
        get_value(&data->precision_value, str, args);
    
    // Verifica si el carácter actual no es un especificador válido
    if (!ft_strchr((const char *)SPECIFIERS, **str))
    {
        // Si no es un especificador válido, escribe '%' y el carácter no válido
        ft_putchar_written('%', &data->chars_written);
        //ft_putstr_aux(str, &data->chars_written);
        return (-1); // Retorna -1 indicando un error
    }
    else
    {
        // Si es un especificador válido, guarda el especificador y determina la base numérica si es necesario
        data->specifier = **str;
        if (ft_strchr((const char *)"diu", data->specifier))
            data->base = 10;
        else if (ft_strchr((const char *)"xXp", data->specifier))
        {
            data->base = 16;
            if ('X' == data->specifier)
                data->upper_case = 1; // Indica que se debe imprimir en mayúsculas si el especificador es 'X'
        }
    }
    return (0);
}
