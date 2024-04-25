/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pamela <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 18:41:41 by pamela            #+#    #+#             */
/*   Updated: 2024/04/25 18:52:02 by pamela           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# define FLAGS		"+ 0-#"
# define SPECIFIERS	"cspdiuxX%"
# define NUMBERS	"0123456789"
# define LOW_SYMBOLS	"0123456789abcdef"
# define UP_SYMBOLS	"0123456789ABCDEF"

/*
 *Defining a data type t_format, it saves all the flags gived to 
 *the function printf.
 *This structure will be used as a field of the structure t_data defined below.
*/

typedef struct s_flags
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
	int		chars_written;

}	t_flags;

/*
 *main functions
*/
int		ft_printf(char const *str, ...);
int		ft_analyze_structure(t_flags *data, const char **str, va_list *args);
void	ft_display_structure(t_flags *data, va_list *args);
void	ft_display_digit(t_flags *data, long value);
/*
 *helper functions
*/
char	*ft_strchr(const char *str, int c);
void	ft_putchar_written(char c, int *chars_written);
void	ft_putchar_n(char c, int precision, int *chars_written);
void	ft_display_char(t_flags *data, int c);
void	ft_putstr_n(char *s, int precision, int *chars_written);
void	ft_display_str(t_flags *data, char *s);
size_t	ft_strlen(const char *str);
void	ft_itoa_base(t_flags *data, long value);
void	ft_set_padding_zeros(t_flags *data);
void	ft_set_padding_spaces(t_flags *data);

#endif
