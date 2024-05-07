/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psanguna <psanguna@student.42madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 16:12:37 by psanguna          #+#    #+#             */
/*   Updated: 2024/05/07 16:12:41 by psanguna         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

# define FLAGS		"+ 0-#"
# define SPECIFIERS	"cspdiuxX%"
# define NUMBERS	"0123456789"
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
	int		left_justified;
	int		plus;
	int		space;
	int		hash;
	int		zero_pad;
	int		width_value;
	int		precision_value;
	int		upper_case;
	int		base;
	int		padding_spaces;
	int		padding_zeros;
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
int		ft_analyze_structure(t_format *data, const char **str, va_list *args);
void	ft_display_structure(t_format *data, va_list *args);
void	ft_display_digit(t_format *data, t_type_digit values);
/*
 *helper functions
*/
char	*ft_strchr(const char *str, int c);
size_t	ft_strlen(const char *str);
void	*ft_memset(void *ptr, int c, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	ft_putchar_written(char c, int *chars_written);
void	ft_putchar_n(char c, int precision, int *chars_written);
void	ft_display_char(t_format *data, int c);
void	ft_putstr_n(char *s, int precision, int *chars_written);
void	ft_display_str(t_format *data, char *s);
void	ft_itoa_base(t_format *data, t_type_digit value);
void	ft_set_padding_zeros(t_format *data);
void	ft_set_padding_spaces(t_format *data);

#endif
