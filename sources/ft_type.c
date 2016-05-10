/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/10 21:39:10 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// appliquer modificateur de longueur puis largeur du champs puis precision puis attribut

/*
void	ft_spc()
{

	if (str == 's')
		ft_putstr(va_arg(lst, char *));
	else if (str == 'S')
		ft_putwstr(va_arg(lst, wchar_t *));
	else if (str == 'p')
	{
		ft_putstr("0x"); //ptet ajouter un 10
		ft_putstr(ft_itoah(va_arg(lst, int), 1));
	}
	else if (str == 'c')
		ft_putchar((char)va_arg(lst, int));
	else if (str == 'C')
		ft_putwchar(va_arg(lst, wchar_t));
}
*/
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

char	*fill_zero(t_format format, char *type, int width)
{
	char	*str;
	char	*str2;
	int		i;

	if (format.flags == '\0' || format.flags != '0' || width <= 0)
		return (NULL);
	else if (is_dioux(format) == 0 || type == NULL)
		return (NULL);
	i = 0;
	str = type;
	while (i < width)
	{
		str2 = str;
		str = ft_strjoin("0", str2);
		free(str2);
		i++;
	}
	return (str);
}

char	*add_width(t_format format, va_list lst, char *type, int *width) // reflechir pour wchat_t // penser condition -
{
	//int width;
	int i;
	char *str;

	//width = 0;
	str = NULL;
	if (format.width == NULL)
		return (type);
	else if (format.width[0] == '*')
		*width = va_arg(lst, int) - ft_strlen(type);
	else if (format.width[0] >= '0' && format.width[0] <= '9')
		*width = ft_atoi(format.width) - ft_strlen(type);
	else
		return (type);
	str = fill_zero(format, type, *width);
	if (str != NULL)
		return (str);
	i = 0;
	while (i < *width && *width > 0)
	{
		ft_putchar(' ');
		i++;
	}
	return (type);
}

char	*add_prenbr(t_format format, char *nbr)
{
	char *pre;
	char *str;

	pre = NULL;
	if (format.flags == '#' && ft_strcmp(nbr, "0") != 0)
	{
		format.type == 'x' ? (pre = "0x") : 0;
		format.type == 'X' ? (pre = "0X") : 0;
	}
	if (format.flags == '#' && (format.type == 'o' || format.type == 'O'))
		nbr[0] != '0' ? (pre = "0") : 0;
	else if (format.flags == ' ' && nbr[0] != '-')
		pre = " ";
	else if (format.flags == '+' && nbr[0] != '-')
		pre = "+";
	if (pre != NULL)
	{
		str = nbr;
		nbr = ft_strjoin(pre, str);
		free(str);
	}
	return (nbr);
}

int		write_nbr(t_format format, va_list lst, long long nbr)
{
	char *word;
	int width;

	word = NULL;
	width = 0;
	if (format.type == 'x')
		word = ft_lltoah(nbr, 1);
	else if (format.type == 'X')
		word = ft_lltoah(nbr, 2);
	else if (format.type == 'o' || format.type == 'O')
		word = ft_lltoao(nbr);
	else
		word = ft_lltoa(nbr);
	if (format.flags == '\0' || format.flags != '-')
		word = add_width(format, lst, word, &width);
	word = add_prenbr(format, word);
	ft_putstr(word);
	if (format.flags != '\0' && format.flags == '-')
		add_width(format, lst, word, &width);
	if (word == NULL)
		return (0);
	width = width + ft_strlen(word);
	return (width);
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

int		ft_dioux(t_format format, va_list lst, char str)
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
	else if (str == 'X')
		length = write_nbr(format, lst, (long long)va_arg(lst, unsigned int));
	else
		return (-1);
	//ft_putendl("here");
	return (length);
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
	/*if (ft_dioux(format, lst, str) == 0)// && seconde fonction type)
	{
		ft_putchar(str);
		return (0);
	}*/
	//ft_putendl("here");
	if (str == 's')
		ft_putstr(va_arg(lst, char *));
	else if (str == 'S')
		ft_putwstr(va_arg(lst, wchar_t *));
	else if (str == 'p')
	{
		ft_putstr("0x"); //ptet ajouter un 10
		ft_putstr(ft_itoah(va_arg(lst, int), 1));
	}
	/*else if (str == 'd' || str == 'i')
		ft_dioux(format, &nbr, lst, str);
	else if (str == 'D')
		ft_putnbr(va_arg(lst, long int));*/
	/*else if (str == 'o')
		ft_putstr(ft_itoao(va_arg(lst, unsigned int)));
	else if (str == 'O')
		ft_putstr(ft_itoao(va_arg(lst, unsigned long)));*/
	/*else if (str == 'u')
		ft_putnbr(va_arg(lst, unsigned int));
	else if (str == 'U')
		ft_putnbr(va_arg(lst, unsigned long));*/
	/*else if (str == 'x')
		ft_putstr(ft_itoah(va_arg(lst, int), 1));
	else if (str == 'X')
		ft_putstr(ft_itoah(va_arg(lst, unsigned int), 2));*/
	else if (str == 'c')
		ft_putchar((char)va_arg(lst, int));
	else if (str == 'C')
		ft_putwchar(va_arg(lst, wchar_t));
	else if (str == 'b')				// bonus pas integrer
		ft_putstr(ft_itoab(va_arg(lst, unsigned int)));
	if (str == '%')
	{
		// repetion de ce bout de code dans write nbr
		length = 0;
		/*if (format->flags == NULL || format->flags[0] != '-')
			add_width(*format, lst, NULL, &length);*/
		ft_putchar(str);
		/*if (format->flags != NULL && format->flags[0] == '-')
			add_width(*format, lst, NULL, &length);*/
		return (1 + length);
	}
	/*else
	{
		ft_putchar(str); //affiche le type ?
		return (0);
	}*/
	return (length);
}
