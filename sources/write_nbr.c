/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/24 14:14:48 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"


int		no_print(t_format format, char *word)
{
	if (format.precision == NULL)
		return (0);
	if (format.precision[0] == '0' || format.precision[0] == '.')
	{
		if (format.pre == '#' && (format.type == 'o' || format.type == 'O'))
			return (0);
		if (ft_strcmp(word, "0") == 0)
			return (1);
	}
	return (0);
}

char	*fill_zero(t_format format, char *type, int width)
{
	char	*str;
	char	*str2;
	int	i;
	int 	j;

	if (type == NULL || width <= 0)
		return (NULL);
	if (is_dioux(format.type) == 0 && format.type != 'p' && format.type != 'S')
		return (NULL);
	i = 0;
	j = 0;
	/*ft_putnbr(width);
	ft_putchar('\n');*/
	//str = type;
	//str = (char *)malloc(ft_strlen(type) + width);
	str = (char *)ft_memalloc(ft_strlen(type) + width);
	//ft_putstr(str);
	if (type[j] == '-' || type[j] == '+' || type[j] == ' ')
	{
		str[i] = type[j];
		i++;
		width++;
		j++;
	}
	else if (type[j] == '0' && (type[j + 1] == 'x' || type[j + 1] == 'X'))
	{
		type[j + 1] == 'x' ? ft_strcat(str, "0x") : 0;
		type[j + 1] == 'X' ? ft_strcat(str, "0X") : 0;
		j = 2;
		i = 2;
		width = width + 2;
	}
	while (i < width)
	{
		//str2 = str;
		//str = ft_strjoin("0", str2);
		//free(str2);
		ft_strcat(str, "0");
		i++;
	}
	ft_strcat(str, &type[j]);
	return (str);
}

void	val_width(t_format format , int *width)
{
	//format.flags == '0' ? *width = 0 : 0;
	if (format.flags == '0' && format.precision == NULL && format.type != 'c' && format.type != 'S' && format.type != 's')
		*width = 0;
	*width < 0 ? *width = 0 : 0;
	/*if (format.pre == '#' && (format.type == 'x' || format.type == 'X'))
		*width = *width - 2;
	if (format.pre == '#' && (format.type == 'o' || format.type == 'O'))
		*width = *width - 1;*/
}

char	*add_width(t_format format, va_list lst, wchar_t *type, int *width) // reflechir pour wchat_t // penser condition -
{
	int i;
	int lgt;
	char *str;
	char c;

	str = NULL;
	if (format.type == 'S')
		lgt = ft_wstrlen(type);
	else
		lgt = ft_strlen((char *)type);
	if (format.type == 's' && format.precision != NULL && format.precision[0] != '.' && (char *)type != '\0' && ft_atoi(format.precision) < lgt)
		lgt = ft_atoi(format.precision);
	else if (format.type == 'S' && format.precision != NULL && format.precision[0] != '.' && (char *)type != '\0' && ft_atoi(format.precision) < lgt)
		lgt = ft_wnstrlen(type, ft_atoi(format.precision));
	//else if ((format.type == 's' || format.type == 'S') && format.width != NULL && format.precision != NULL && format.precision[0] == '.')
	/*ft_putwstr(type);*/
	if (format.width == NULL)
		return ((char *)type);
	else if (format.width[0] == '*')
		*width = va_arg(lst, int) - lgt;
	else if (format.width[0] >= '0' && format.width[0] <= '9')
		*width = ft_atoi(format.width) - lgt;
	else
		return ((char *)type);
	//ft_putchar(format.flags);
	if (no_print(format, (char *)type) == 1)
		(*width)++;
	if (format.precision == NULL || format.precision[0] == '.')
		format.flags == '0' ? str = fill_zero(format,(char *)type, *width) : 0;
	/*ft_putnbr(*width);
	ft_putchar('\n');*/
	val_width(format, width);
	/*format.flags == '0' ? *width = 0 : 0;
	*width < 0 ? *width = 0 : 0;*/
	//}
	/*ft_putchar('\n');
	ft_putstr("width : ");
	ft_putnbr(*width);
	ft_putchar('\n');*/
	//ft_putendl("here");
	if (str != NULL && format.type != 'c' && format.type != 's' && format.type != 'S')
		return (str);
	i = 0;
	if ((format.type == 'c' || format.type == 's' || format.type == 'S') && format.flags == '0')
		c = '0';
	else
		c = ' ';
	//ft_putnbr(*width);
	while (i < *width && *width > 0)
	{
		ft_putchar(c);
		i++;
	}
	return ((char *)type);
}

static char	*add_precision(t_format format, va_list lst, char *type, int *prcsn) // reflechir pour wchat_t // penser condition -
{
	int i;
	char *str;

	str = NULL;
	if (format.precision == NULL)
		return (type);
	else if (format.precision[0] == '*')
		*prcsn = va_arg(lst, int) - ft_strlen(type);
	else if (format.precision[0] >= '0' && format.precision[0] <= '9')
		*prcsn = ft_atoi(format.precision) - ft_strlen(type);
	else
		return (type);
	if (type != NULL && (type[0] == '-' || type[0] == '+'))
		(*prcsn)++;
	/*ft_putnbr(*prcsn);
	ft_putendl("here");*/
	str = fill_zero(format, type, *prcsn);
	if (str != NULL)
		return (str);
	return (type);
}

int	is_unsigned(char str)
{
	if (str == 'u' || str == 'U' || str == 'x' || str == 'X')
		return (1);
	else if (str == 'o' || str == 'O' || str == 'p')
		return (1);
	return (0);
}

static char	*add_prenbr(t_format format, char *nbr)
{
	char *pre;
	char *str;

	pre = NULL;
	if (format.pre == '#' && ft_strcmp(nbr, "0") != 0)
	{
		format.type == 'x' ? (pre = "0x") : 0;
		format.type == 'X' ? (pre = "0X") : 0;
	}
	if (format.pre == '#' && (format.type == 'o' || format.type == 'O'))
		nbr[0] != '0' ? (pre = "0") : 0;
	if (format.sign == ' ' && nbr[0] != '-' && is_unsigned(format.type) == 0)
		pre = " ";
	else if (format.type == 'd' || format.type == 'D' || format.type == 'i')
	{
		if (format.sign == '+' && nbr[0] != '-')
			pre = "+";
	}
	if (pre != NULL)
	{
		str = nbr;
		nbr = ft_strjoin(pre, str);
		free(str);
	}
	return (nbr);
}

char	*ft_strjoinfree(char *s1, char *s2)
{
	char *str;

	
	str = s2;
	str = ft_strjoin(s1, s2);
	//free(s2);
	return (str);
}

int		write_nbr(t_format format, va_list lst, long long nbr)
{
	char *word;
	int width;
	int b;

	word = NULL;
	width = 0;
	if (format.type == 'x' || format.type == 'p')
		word = ft_lltoah(nbr, 1);
	else if (format.type == 'X')
		word = ft_lltoah(nbr, 2);
	else if (format.type == 'o' || format.type == 'O')
		word = ft_lltoao(nbr);
	else if (format.type == 'u' || format.type == 'U')
		word = ft_ulltoa((unsigned long long)nbr);
	else
		word = ft_lltoa(nbr);
	b = no_print(format, word);
	/*if (format.type == 'p' && ft_strncmp(word, "7fff", 4) != 0)
		ft_strcmp(word, "0") != 0 ? (word = ft_strjoinfree("7fff", word)) : 0; // 0x ou 0x10 ?*/
	if (format.type == 'p' && ft_strcmp(word, "0") == 0 && b == 1)
	{
		word = ft_strjoinfree(word, "x");
		b = 0;
	}
	word = add_precision(format, lst, word, &width);
	//format.type == 'p' ? (word = ft_strjoinfree("0x", word)) : 0;
	if (format.type == 'p' && ft_strcmp(word, "0x") != 0)
		word = ft_strjoinfree("0x", word);
	width = 0;
	word = add_prenbr(format, word);
	if (format.flags != '-')
		word = add_width(format, lst, (wchar_t *)word, &width);
	//word = add_prenbr(format, word);
	//format.type == 'p' ? (word = ft_strjoinfree("0x", word)) : 0; // 0x ou 0x10 ?
	if (b == 0)
		ft_putstr(word);
	/*else if (b == 1 && format.type == 'p')
		ft_putnstr(word, 2);*/
	if (format.flags == '-')
		add_width(format, lst, (wchar_t *)word, &width);
	/*if (word == NULL)
		return (0);*/
	/*ft_putstr("width : ");
	ft_putnbr(width);
	ft_putchar('\n');*/
	/*ft_putstr("word : ");
	ft_putnbr(ft_strlen(word));
	ft_putchar('\n');*/
	b == 0 ? (width = width + ft_strlen(word)) : 0;
	/*if (b == 0)
		(width = width + ft_strlen(word));*/
	if (b == 1 && width == 0)
		width = -1;
	/*ft_putendl("haha nelson");
	ft_putnbr(width);*/
	word == NULL ? width = 0 : 0;
	return (width);
}
