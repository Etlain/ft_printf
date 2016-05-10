/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/10 20:15:04 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

//#include <stdio.h>
int		ft_printf(const char *str, ...)
{
	va_list lst;
	int i;
	int length;
	int format;

	va_start(lst, str);
	i = 0;
	format = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			//if (str[i] != '%')
			format = ft_format(lst, (char *)str, &i);
			length = length + format;
			//else
			//	ft_putchar(str[i]);
			i++;
		}
		else
		{
			ft_putchar(str[i]);
			length++;
			/*printf("lgt : %d\n", format);
			printf("lgt : %d\n", length);*/
			i++;		// avec ce i ici n affiche plus de plus
		}
	}
	va_end(lst);
	return (length);
}
