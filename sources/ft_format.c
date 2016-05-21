/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/21 20:38:39 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

#include <stdio.h>
int	is_flags(char str)
{
	if (str == '+' || str == ' ' || str == '-' || str == '0' || str == '#')
		return (1);
	return (0);
}
void	ft_flags(t_format *format, char *str, int *i)
{
	//int b;
	int j;

	//b = 1;
	j = *i;
	while (str[j] != '\0' && is_flags(str[j]) == 1)
	{
		if (str[j] == '+')
		{
			format->sign = '+';
			(*i)++;
		}
		else if (str[j] == ' ' && (format->sign == '\0' || format->sign != '+'))
		{
			format->sign = ' ';
			(*i)++;
		}
		else if (str[j] == '-')
		{
			format->flags = '-';
			(*i)++;
		}
		else if (str[j] == '0' && (format->flags == '\0' || format->flags != '-'/*(b = ft_strcmp(format->flags, "-")) == 1*/)) //0 - important precision
		{
			format->flags = '0';
			(*i)++;
		}
		else if (str[j] == '#')
		{
			format->pre = '#';
			(*i)++;
		}
	/*else if (b == 0);*/
		else
			return ;
		j++;
	}
	/*format->sign != '\0' ? (*i)++ : 0;
	format->pre != '\0' ? (*i)++ : 0;
	format->flags != '\0' ? (*i)++ : 0;*/
}

void	ft_wp(t_format *format, char *str, int *i) //ajout condition '.' pour precis
{
	int j;
	int lgt;
	int b;
	char *tmp;

	str[*i] == '.' ? b = 1 : (b = 0);
	str[*i] == '.' ? (*i)++ : 0;
	if (str[*i] >= '0' && str[*i] <= '9')
	{
		j = *i;
		lgt = 0;
		while (str[j] >= '0' && str[j] <= '9')
		{
			lgt++;
			j++;
		}
		/*tmp = (char *)malloc(lgt + 1);
		ft_bzero(tmp, lgt + 1);*/
		tmp = (char *)ft_memalloc(lgt + 1);
		ft_strncat(tmp, &str[*i], j - *i);
		*i = j;
	}
	else if (str[*i] == '*')
		tmp = "*";
	else
	{
		b == 1 ? (format->precision = ".") : 0;
		return ;
	}
	b == 1 ? format->precision = tmp : (format->width = tmp);
}

int	ft_modifier(t_format *format, char *str, int *i)
{
	if (str[*i] == 'h' && str[*i + 1] == 'h')
	{
		format->modifier = "hh";
		(*i)++;
	}
	else if (str[*i] == 'h')
		format->modifier = "h";
	else if (str[*i] == 'l' && str[*i + 1] == 'l')
	{
		format->modifier = "ll";
		(*i)++;
	}
	else if (str[*i] == 'l')
		format->modifier = "l";
	else if (str[*i] == 'j')
		format->modifier = "j";
	else if (str[*i] == 'z')
		format->modifier = "z";
	else
		return (0);
	(*i)++;
	return (1);
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

int		ft_format(va_list lst, const char *s, int *i)
{
	t_format *format;
	int	length;
	char *str;

	str = (char *)s;
	length = 0;
	format = format_init();
	while (str[*i] != '\0')
	{
		/*ft_putnbr(*i);
		ft_putchar(' ');*/
		ft_flags(format, str, i);
		ft_wp(format, str, i);
		ft_wp(format, str, i);
		ft_modifier(format, str, i);
		/*if (str[*i]== '%')
		{
			ft_putchar(str[*i]);
			//length++;
			return (1);
		}*/
		if ((length = ft_type(format, lst, str[*i])) != 0)
		{
			(*i)++;
			break ;
		}
		(*i)++;
	}
	//ft_putformat(format);
	return (length);
}
