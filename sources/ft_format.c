/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/03 20:12:06 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flags(t_format *format, char str, int *i)
{
	int b;

	b = 1;
	if (str == '+')
		format->flags = "+";
	else if (str == ' ' && (format->flags == NULL || (b = ft_strcmp(format->flags, "+")) == 1))
		format->flags = " ";
	else if (str == '-')
		format->flags = "-";
	else if (str == '0' && (format->flags == NULL || (b = ft_strcmp(format->flags, "-")) == 1)) //0 - important precision
		format->flags = "0";
	else if (str == '#')
		format->flags = "#";
	else if (b == 0);
	else
		return ;
	(*i)++;
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
		tmp = (char *)malloc(lgt + 1);
		ft_strncat(tmp, &str[*i], j - *i);
		*i = j;
	}
	else if (str[*i] == '*')
		tmp = "*";
	else
		return ;
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
	format->flags = NULL;
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
	ft_putendl(format->flags);
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

void	ft_format(va_list lst, char *str, int *i)
{
	t_format *format;
	
	format = format_init();
	while (str[*i] != '\0')
	{
		ft_flags(format, str[*i], i);
		ft_wp(format, str, i);
		ft_wp(format, str, i);
		ft_modifier(format, str, i);
		if (ft_type(format, lst, str[*i]) == 1)
			break ;
		(*i)++;
	}
	//ft_putformat(format);
}
