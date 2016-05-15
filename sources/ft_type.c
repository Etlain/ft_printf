/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/14 19:21:58 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// appliquer modificateur de longueur puis largeur du champs puis precision puis attribut

int		is_dioux(t_format format)
{
	if (format.type == 'd' || format.type == 'i' || format.type == 'o')
		return (1);
	if (format.type == 'u' || format.type == 'x' || format.type == 'X')
		return (1);
	if (format.type == 'D' || format.type == 'O' || format.type == 'U')
		return (2);
	return (0);
}

int		add_modifier(t_format format, va_list lst)
{
	int length;

	length = 0;
	if (format.modifier == NULL || is_dioux(format) == 0)
		return (0);
	if (ft_strcmp(format.modifier, "hh") == 0)
		length = write_nbr(format, lst, (long long)va_arg(lst, int));
	else if (format.modifier[0] == 'h')
		length = write_nbr(format, lst, (long long)(short)va_arg(lst, int));
	else if (format.modifier[0] == 'l')
		length = write_nbr(format, lst, (long long)va_arg(lst, long));
	else if (ft_strcmp(format.modifier, "ll") == 0)
		length = write_nbr(format, lst, va_arg(lst, long long));
	else if (format.modifier[0] == 'j')
		length = write_nbr(format, lst, (long long)va_arg(lst, intmax_t));
	else if (format.modifier[0] == 'z')
		length = write_nbr(format, lst, (long long)va_arg(lst, size_t));
	return (length);
}

int		ft_dioux(t_format format, va_list lst, char str) // ajout p
{
	int length;

	length = 0;
	if (str == 'd' || str == 'i')
		length = write_nbr(format, lst, (long long)va_arg(lst, int));
	else if (str == 'D')
		length = write_nbr(format, lst, (long long)va_arg(lst, long int));
	else if (str == 'o')
		length = write_nbr(format, lst, (long long)va_arg(lst, unsigned int));
	else if (str == 'O')
		length = write_nbr(format, lst, (long long)va_arg(lst, unsigned long));
	else if (str == 'u')
		length = write_nbr(format, lst, (long long)va_arg(lst, unsigned int));
	else if (str == 'U')
		length = write_nbr(format, lst, (long long)va_arg(lst, unsigned long));
	else if (str == 'x')
		length = write_nbr(format, lst, (long long)va_arg(lst, unsigned int));
		//ft_putendl("hehe");
		//ft_putnbr(length);
	else if (str == 'X')
		length = write_nbr(format, lst, (long long)va_arg(lst, unsigned int));
	else if (str == 'p')
	{
		//ft_putstr("0x");
		length = write_nbr(format, lst, (long long)va_arg(lst, int));
		//length = length + 2;
	}
	else
		return (-1);
	//ft_putendl("here");
	return (length);
}


int	ft_sc(t_format format, va_list lst, char str)
{
	wchar_t *word;
	int width;

	width = 0;
	word = NULL;
	if (str == 's' && format.modifier != NULL && format.modifier[0] == 'l')
		str = 'S';
	if (str == 'S')
		word = va_arg(lst, wchar_t *);
	else if (str == 's')
		word = (wchar_t *)va_arg(lst, char *);
	if (str == 'c' || str == 'C')
	{
		format.flags != '-' ? add_width(format, lst, "1", &width) : 0;
		str == 'c' ? ft_putchar((char)va_arg(lst, int)) : 0;
		str == 'C' ? ft_putwchar(va_arg(lst, wchar_t)) : 0;
		format.flags == '-' ? add_width(format, lst, "1", &width) : 0;
		width++;
	}
	if (word != NULL)
	{
		format.flags != '-' ? add_width(format, lst, (char *)word, &width) : 0;
		if (format.precision != NULL)
		{
			if (str == 's')
				ft_putnstr((char *)word, ft_atoi(format.precision));
			else if (str == 'S')
				ft_putnwstr(word, ft_atoi(format.precision));
		}
		else if (str == 's')
			ft_putstr((char *)word);
		else
			ft_putwstr(word);
		format.flags == '-' ? add_width(format, lst, (char *)word, &width) : 0;
	}
	if (word != NULL && str == 's')
		width = ft_strlen((char *)word) + width;
	else if (word != NULL && str == 'S')
		width = ft_wstrlen(word) + width;
	return (width);
}


int		ft_type(t_format *format, va_list lst, char str)
{
	int length;

	//printf("c : %c\n", str);
	length = 0;
	format->type = str;
	if (format->modifier != NULL)
		length = add_modifier(*format, lst);
	else
		length = ft_dioux(*format, lst, str);
	length <= 0 ? (length = ft_sc(*format, lst, str)) : 0;
	/*if (ft_dioux(format, lst, str) == 0)// && seconde fonction type)
	{
		ft_putchar(str);
		return (0);
	}*/
	//ft_putendl("here");
	if (str == 'b')				// bonus pas integrer float et double fonction
		ft_putstr(ft_itoab(va_arg(lst, unsigned int)));
	if (str == '%')
	{
		// repetion de ce bout de code dans write nbr
		length = 0;
		if (format->flags != '-')
			add_width(*format, lst, "%", &length);
		ft_putchar(str);
		if (format->flags == '-')
			add_width(*format, lst, "%", &length);
		return (1 + length);
	}
	/*else
	{
		ft_putchar(str); //affiche le type ?
		return (0);
	}*/
	return (length);
}
