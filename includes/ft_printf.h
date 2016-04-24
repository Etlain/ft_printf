/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 02:24:25 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/25 00:01:00 by mmouhssi         ###   ########.fr       */
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
}		t_format;

void	ft_printf(const char *str, ...);
int	ft_type(va_list lst, char str);
void	ft_format(va_list lst, char *str, int *i);

#endif
