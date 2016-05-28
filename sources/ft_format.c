/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/28 18:56:12 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>
void	ft_flags(t_format *format, char *str, int *i)
{
	while (str[*i] != '\0' && is_flags(str[*i]) == 1)
	{
		if (str[*i] == '+')
			format->sign = '+';
		else if (str[*i] == ' ' && format->sign != '+')
			format->sign = ' ';
		else if (str[*i] == '-')
			format->flags = '-';
		else if (str[*i] == '0' && format->flags != '-')
			format->flags = '0';
		else if (str[*i] == '#')
			format->pre = '#';
		(*i)++;
	}
}

void	ft_wp(t_format *format, va_list lst, char *str, int *i)
{
	int j;
	int lgt;
	int b;
	char *tmp;

	str[*i] == '.' ? b = 1 : (b = 0);
	while (str[*i] == '.')
		(*i)++;
	if (str[*i] >= '0' && str[*i] <= '9')
	{
		j = *i;
		lgt = 0;
		while (str[j] >= '0' && str[j] <= '9')
		{
			lgt++;
			j++;
		}
		tmp = (char *)ft_memalloc(lgt + 1);
		ft_strncat(tmp, &str[*i], j - *i);
		*i = j;
	}
	else if (str[*i] == '*')
	{
		//tmp = "*";
		(*i)++;
		j = va_arg(lst, int);
		if (j < 0)
		{
			if (b == 1)
				return ;
			j = j * (-1);
			format->flags = '-';
		}
		tmp = ft_itoa(j);
	}
	else
	{
		b == 1 ? (format->precision = ".") : 0;
		return ;
	}
	b == 1 ? format->precision = tmp : (format->width = tmp);
}

int			is_modifier(char *str)
{
	if (str == NULL)
		return (0);
	else if (ft_strncmp(str, "ll", 2) == 0 || str[0] == 'z')
		return (5);
	else if (str[0] == 'l')
		return (4);
	else if (str[0] == 'j')
		return (3);
	else if (ft_strncmp(str, "hh", 2) == 0)
		return (1);
	else if (str[0] == 'h')
		return (2);
	return (0);
}

void		ft_modifier(t_format *format, char *str, int *i)
{
	while (str[*i] != '\0' && is_modifier(&str[*i]) > 0)
	{
		if (is_modifier(&str[*i]) == 1 && is_modifier(format->modifier) <= 1)
		{
			format->modifier = "hh";
			(*i)++;
		}
		else if (str[*i] == 'h' && is_modifier(format->modifier) <= 2)
			format->modifier = "h";
		else if (str[*i] == 'l' && str[*i + 1] == 'l')
		{
			format->modifier = "ll";
			(*i)++;
		}
		else if (str[*i] == 'l' && is_modifier(format->modifier) != 5)
			format->modifier = "l";
		else if (str[*i] == 'j' && is_modifier(format->modifier) <= 3)
			format->modifier = "j";
		else if (str[*i] == 'z')
			format->modifier = "z";
		(*i)++;
	}
}

t_format	*format_init()
{
	t_format *format;

	format = (t_format *)malloc(sizeof(t_format));
	format->flags = '\0';
	format->sign = '\0';
	format->pre = '\0';
	format->width = NULL;
	format->precision = NULL;
	format->modifier = NULL;
	format->type = '\0';
	return (format);
}

void	ft_putformat(t_format *format) // a effacer
{
	ft_putchar('\n');
	ft_putendl("format :");
	ft_putstr("flags : ");
	ft_putchar(format->flags);
	ft_putchar('\n');
	ft_putstr("sign : ");
	ft_putchar(format->sign);
	ft_putchar('\n');
	ft_putstr("pre : ");
	ft_putchar(format->pre);
	ft_putchar('\n');
	ft_putstr("width : ");
	ft_putendl(format->width);
	ft_putstr("precision : ");
	ft_putendl(format->precision);
	ft_putstr("modifier : ");
	ft_putendl(format->modifier);
	ft_putstr("type : ");
	ft_putchar(format->type);
	ft_putchar('\n');
}

void	free_format(t_format *format)
{
	if (format->precision != NULL && format->precision[0] >= '0' && format->precision[0] <= '9')
		free(format->precision);
	if (format->width != NULL && format->width[0] >= '0' && format->width[0] <= '9')
		free(format->width);
	free(format);
}

int		ft_format(va_list lst, const char *s, int *i)
{
	t_format *format;
	int	length;
	char *str;

	str = (char *)s;
	length = 0;
	format = format_init();
	/*ft_flags(format, str, i);
	ft_putstr("here");
	ft_putchar(str[*i]);
	ft_wp(format, lst, str, i);
	ft_putchar(str[*i]);
	ft_putchar('\n');*/
	while (str[*i] != '\0')
	{
		ft_flags(format, str, i);
		ft_wp(format, lst, str, i);
		ft_wp(format, lst, str, i);
		ft_modifier(format, str, i);
		if ((length = ft_type(format, lst, str[*i])) != 0)
		{
			(*i)++;
			break ;
		}
	}
	free_format(format);
	//ft_putformat(format);
	return (length);
}
