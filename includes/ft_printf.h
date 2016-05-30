/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 02:24:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/30 21:22:13 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_format
{
	char	flags;
	char	pre;
	char	sign;
	char 	*width;
	char 	*precision;
	char	*modifier;
	char	type;
}				t_format;

int		ft_printf(const char *str, ...);
int		ft_type(t_format *format, va_list lst, char str);
int		ft_format(va_list lst, const char *s, int *i);
void	ft_wp(t_format *format, va_list lst, char *str, int *i);
int		write_nbr(t_format format, long long nbr);
char	*add_width(t_format format, wchar_t *type, int *width);
char	*fill_zero(t_format format, char *type, int width);
int		is_dioux(char type);
int		is_flags(char str);
int		is_str(char type);
int		is_unsigned(char type);
int		is_modifier(char *str);

#endif
