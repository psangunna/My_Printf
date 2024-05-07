/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_structure.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:35:08 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:35:12 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void     set_nil(t_format *data)
{
	data->no_value = 1;
	data->precision_value = -1;
	data->nbr_len = 5;
	ft_memcpy(&(data->temp), "(nil)", 5);
}
/*
This function processes integer and pointer types.
If the specifier is 'd' or 'i', it handles signed integers, checking for 
negativity and passing the digit to ft_display_digit for display. 
For 'x', 'X', and 'u' specifiers, it handles unsigned integers. 
For the 'p' specifier (pointer), it treats the argument as a pointer 
and displays it.
*/
static void	treat_digit(t_format *data, va_list *args)
{
	char specifier;
	t_type_digit values;

	specifier = data->specifier;
	// Si el especificador es 'd' o 'i', trata un valor con signo
	if ('d' == specifier || 'i' == specifier)
	{
		data->signed_value = 1;
		// Obtiene el valor del argumento variable como un entero y lo almacena en values.sig_value
		values.sig_value = (long)(va_arg(*args, int));
		// Si el valor es negativo, establece la bandera is_negative en 1
		if (values.sig_value < 0)
			data->is_negative = 1;
		// Llama a ft_display_digit para mostrar el valor
		ft_display_digit(data, values);
	}
	// Si el especificador es 'x', 'X' o 'u', trata un valor sin signo
	else if ('x' == specifier || 'X' == specifier || 'u' == specifier)
	{
		// Obtiene el valor del argumento variable como un entero sin signo y lo almacena en values.unsig_value
		values.unsig_value = (unsigned long)(va_arg(*args, unsigned int));
		// Llama a ft_display_digit para mostrar el valor
		ft_display_digit(data, values);
	}
	// Si el especificador es 'p', trata un puntero
	else if ('p' == specifier)
	{
		// Obtiene el valor del argumento variable como un puntero y lo almacena en values.unsig_value
		values.unsig_value = (unsigned long)(va_arg(*args, void *));
		if (values.unsig_value == 0)
            set_nil(data);
		// Llama a ft_display_digit para mostrar el valor
		ft_display_digit(data, values);
	}
}

/*
This function determines the type of data to display based on the format 
specifier. If the specifier is '%', it displays a '%' character. For 'c',
it displays a single character. For 's', it displays a string. If the 
specifier corresponds to a digit or pointer type ('d', 'i', 'u', 'x', 'X',
'p'), it calls treat_digit to handle the display. Otherwise, it writes the
specifier directly to the output.
*/
void	ft_display_structure(t_format *data, va_list *args)
{
	char specifier;

	specifier = data->specifier;
	// Determina qué tipo de dato se va a mostrar según el especificador
	if ('%' == specifier)
	{
		// Si el especificador es '%', muestra un carácter '%'
		data->width_value = 0;
		ft_display_char(data, '%');
	}
	else if ('c' == specifier)
		// Si el especificador es 'c', muestra un carácter obtenido de los argumentos variables
		ft_display_char(data, va_arg(*args, int));
	else if ('s' == specifier)
		// Si el especificador es 's', muestra una cadena obtenida de los argumentos variables
		ft_display_str(data, va_arg(*args, char *));
	else if (ft_strchr((const char *)"diupxX", data->specifier))
		// Si el especificador corresponde a un dígito ('d', 'i', 'u', 'x', 'X', 'p'), llama a treat_digit para manejar su visualización
		treat_digit(data, args);
	else
		// Si el especificador no corresponde a ninguno de los anteriores, escribe directamente el especificador en la salida
		write(1, &specifier, 1);
}
