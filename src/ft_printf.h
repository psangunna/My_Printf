/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:23:54 by pamela            #+#    #+#             */
/*   Updated: 2024/05/05 19:24:00 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define SPECIFIERS	"cspdiuxX%"
# define LOW_SYMBOLS	"0123456789abcdef"
# define UP_SYMBOLS	"0123456789ABCDEF"

/*
 *Defining a data type t_type_digit, it stores both unsigned long
 *and long values. Long is used to manage integer values, both positives 
 *and negatives. Unsigned long is used to manage unsigned values,such as
 *pointer values.
*/
typedef union s_type_digit
{
	long			sig_value;
	unsigned long	unsig_value;
}	t_type_digit;

/*
 *Defining a data type t_format, it saves all the flags gived to 
 *the function printf.
 *This structure will be used as a field of the structure t_data defined below.
*/

typedef struct s_format
{
	int		upper_case;
	int		base;
	int		signed_value;
	int		is_negative;
	int		is_converted;
	int		nbr_len;
	char	specifier;
	char	temp[64];
	int		no_value;
	int		chars_written;

}	t_format;

/*
 *main functions
*/
int		ft_printf(char const *str, ...);
int		ft_analyze_structure(t_format *data, const char **str);
void	ft_display_structure(t_format *data, va_list *args);
void	ft_display_digit(t_format *data, t_type_digit values);
void	ft_display_str(t_format *data, char *s);
void	ft_putchar_written(char c, int *chars_written);
void	ft_putstr_written(char *s, int *chars_written);
/*
 *helper functions
*/
char	*ft_strchr(const char *str, int c);
void	*ft_memset(void *ptr, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
#endif
