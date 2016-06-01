/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/01 16:08:29 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		add_umodifier(t_format format, va_list lst)
{
	int length;

	length = 0;
	if (format.modifier == NULL)
		return (0);
	if (ft_strcmp(format.modifier, "hh") == 0)
		length = write_nbr(format, (long long)(unsigned char)va_arg(lst, int));
	else if (format.modifier[0] == 'h')
		length = write_nbr(format, (long long)(unsigned short)va_arg(lst, int));
	else if (format.modifier[0] == 'l')
		length = write_nbr(format, (long long)va_arg(lst, unsigned long));
	else if (ft_strcmp(format.modifier, "ll") == 0)
		length = write_nbr(format, va_arg(lst, unsigned long long));
	else if (format.modifier[0] == 'j')
		length = write_nbr(format, (long long)va_arg(lst, uintmax_t));
	else if (format.modifier[0] == 'z')
		length = write_nbr(format, (long long)va_arg(lst, size_t));
	return (length);
}

int		add_modifier(t_format format, va_list lst)
{
	int length;

	length = 0;
	if (format.modifier == NULL)
		return (0);
	if (format.type == 'u' || format.type == 'o' ||
			format.type == 'x' || format.type == 'X')
		length = add_umodifier(format, lst);
	else if (ft_strcmp(format.modifier, "hh") == 0)
		length = write_nbr(format, (long long)(char)va_arg(lst, int));
	else if (format.modifier[0] == 'h')
		length = write_nbr(format, (long long)(short)va_arg(lst, int));
	else if (format.modifier[0] == 'l')
		length = write_nbr(format, (long long)va_arg(lst, long));
	else if (ft_strcmp(format.modifier, "ll") == 0)
		length = write_nbr(format, va_arg(lst, long long));
	else if (format.modifier[0] == 'j')
		length = write_nbr(format, (long long)va_arg(lst, intmax_t));
	else if (format.modifier[0] == 'z')
		length = write_nbr(format, (long long)va_arg(lst, size_t));
	return (length);
}

int		ft_dioux(t_format format, va_list lst, char str) // ajout p et b
{
	int length;

	length = 0;
	if (str == 'd' || str == 'i')
		length = write_nbr(format, (long long)va_arg(lst, int));
	else if (str == 'D')
		length = write_nbr(format, (long long)va_arg(lst, long int));
	else if (str == 'u' || str == 'x' || str == 'X' || str == 'o' || str == 'b')
		length = write_nbr(format, (long long)va_arg(lst, unsigned int));
	else if (str == 'U' || str == 'O' || str == 'p')
		length = write_nbr(format, (long long)va_arg(lst, unsigned long));
	else
		return (-1);
	return (length);
}

int ft_c(t_format format, va_list lst, char str)
{
	wchar_t c;
	int width;

	width = 0;
	if (format.modifier != NULL && format.modifier[0] == 'l')
		str == 'c' ? str = 'C' : 0;
	format.flags != '-' ? add_width(format, L"1", &width) : 0;
	if (str == 'c')
		ft_putchar((char)va_arg(lst, int));
	else
		ft_putwchar((c = va_arg(lst, wchar_t)));
	format.flags == '-' ? add_width(format, L"1", &width) : 0;
	if (str == 'C')
		width = ft_sizewchar((long)c);
	else
		width++;
	return (width);
}

void	s_empty(t_format format, wchar_t **word)
{
	if (format.precision != NULL && (format.precision[0] == '.'))
	{
		if (format.type == 's')
			*word =(wchar_t *)"";
		else
			*word = L"";
	}
	else if (*word == NULL)
	{
		format.type == 's' ? (*word =(wchar_t *)"(null)") : 0;
		format.type == 'S' ? (*word = L"(null)") : 0;
	}
}

char ft_s(t_format format, va_list lst, wchar_t **word, int *width)
{
	if (format.modifier != NULL && format.modifier[0] == 'l')
		format.type == 's' ? format.type = 'S' : 0;
	if (format.type == 'S')
		*word = va_arg(lst, wchar_t *);
	else if (format.type == 's')
		*word = (wchar_t *)va_arg(lst, char *);
	s_empty(format, word);
	if (word != NULL)
	{
		format.flags != '-' ? add_width(format, *word, width) : 0;
		if (format.precision != NULL)
		{
			if (format.type == 's' && format.precision[0] != '.')
				ft_putnstr((char *)*word, ft_atoi(format.precision));
			else if (format.type == 'S' && format.precision[0] != '.')
				ft_putnwstr(*word, ft_atoi(format.precision));
		}
		else if (format.type == 's')
			ft_putstr((char *)*word);
		else
			ft_putwstr(*word);
		format.flags == '-' ? add_width(format, *word, width) : 0;
	}
	return (format.type);
}

int	ft_sc(t_format format, va_list lst, char str)
{
	wchar_t *word;
	int width;

	width = 0;
	word = NULL;
	if (str == 'c' || str == 'C')
		return (ft_c(format, lst, str));
	else if (str == 'S' || str == 's')
		str = ft_s(format, lst, &word, &width);
	if (format.precision != NULL && format.precision[0] != '.' &&
			(str == 's' || str == 'S') && ft_atoi(format.precision)
			< (int)ft_strlen((char *)word))
		width = ft_atoi(format.precision) + width;
	else if (word != NULL && str == 's')
		width = ft_strlen((char *)word) + width;
	else if (str == 'S' && word != NULL && format.precision != NULL)
		width = ft_wnstrlen(word, ft_atoi(format.precision)) + width;
	else if (word != NULL && str == 'S')
		width = ft_wstrlen(word) + width;
	if ((str == 's' || str == 'S') && width == 0)
		width = -1;
	return (width);
}

int		write_type(t_format format, char str, int length)
{
	format.type = 's';
	format.flags != '-' ? add_width(format, L"%", &length) : 0;
	ft_putchar(str);
	format.flags == '-' ? add_width(format, L"%", &length) : 0;
	length++;
	return (length);
}

int		ft_type(t_format *format, va_list lst, char str)
{
	int length;

	length = 0;
	if (is_dioux(str) > 0 || str == 'p' || str == 'b')
	{
		format->type = str;
		if (format->modifier != NULL && is_dioux(str) == 1)
			length = add_modifier(*format, lst);
		else
			length = ft_dioux(*format, lst, str);
	}
	else if (str == '%')
		return (write_type(*format, str, length));
	else if (is_str(str) > 0)
	{
		format->type = str;
		length = ft_sc(*format, lst, str);
	}
	else if (is_dioux(str) == 0 && is_str(str) == 0 && str != 'p' && str != 'b'
			&& is_flags(str) == 0 && ft_isprint(str) == 1 && str != '.')
		length = write_type(*format, str, length);
	return (length);
}
