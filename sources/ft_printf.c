/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/30 02:00:38 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>
int	ft_getcolor(char *s, int b)
{
	if (b == 0)
		ft_putstr("\033[0m");
	else if (ft_strcmp("cyan", s) == 0)
		ft_putstr("\033[36m");
	else if (ft_strcmp("magenta", s) == 0)
		ft_putstr("\033[35m");
	else if (ft_strcmp("blue", s) == 0)
		ft_putstr("\033[34m");
	else if (ft_strcmp("yellow", s) == 0)
		ft_putstr("\033[33m");
	else if (ft_strcmp("green", s) == 0)
		ft_putstr("\033[32m");
	else if (ft_strcmp("red", s) == 0)
		ft_putstr("\033[31m");
	else if (ft_strcmp("black", s) == 0)
		ft_putstr("\033[30m");
	else
		return (0);
	return (1);
}

int	ft_color(char *str, int i)
{
	static int b;
	int j;
	char *s;

	if (b == 0 || !b)
		b = 1;
	else if (b == 1)
		b = 0;
	j = i;
	while (str[j] != '}')
		j++;
	s = (char *)malloc(j + 1);
	s[j + 1] = '\0';
	ft_strncat(s, &str[i], j - i);
	if (ft_getcolor(s, b) == 0)
	{
		free(s);
		i--;
		return (i);
	}
	free(s);
	j++;
	return (j);
}

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
		/*if (str[i] == '{')
		{
			i++;
			i = ft_color((char *)str, i);
		}*/
		if (str[i] == '%')
		{
			i++;
			format = ft_format(lst, (char *)str, &i);
			format < 0 ? (format = 0) : 0;
			length = length + format;
		}
		else
		{
			ft_putchar(str[i]);
			length++;
			i++;
		}
	}
	va_end(lst);
	return (length);
}
