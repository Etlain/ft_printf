/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 02:24:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/02 16:44:41 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "../libft/libft.h"
# include <stdarg.h>

typedef struct	s_format
{
	char	*flags;
	char 	*width;
	char 	*precision;
	char	*modifier;
	char	type;
}				t_format;

void	ft_printf(const char *str, ...);
int		ft_type(t_format *format, va_list lst, char str);
void	ft_format(va_list lst, char *str, int *i);

#endif
