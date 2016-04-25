/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/25 22:15:56 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
// appliquer modificateur de longueur puis largeur du champs puis precision puis attribut
/*
void	ft_truc()
{
	if (str == 'd' || str == 'i')
		ft_putnbr(va_arg(lst, int));
	if (str == 'D')
		ft_putnbr(va_arg(lst, long int));
	if (str == 'o')
		ft_putstr(ft_itoao(va_arg(lst, unsigned int)));
	if (str == 'O')
		ft_putstr(ft_itoao(va_arg(lst, unsigned long)));
	if (str == 'u')
		ft_putnbr(va_arg(lst, unsigned int));
	if (str == 'U')
		ft_putnbr(va_arg(lst, unsigned long));
	if (str == 'x')
		ft_putstr(ft_itoah(va_arg(lst, int), 1));
	if (str == 'X')
		ft_putstr(ft_itoah(va_arg(lst, unsigned int), 2));
}

void	ft_truc2()
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

char	*add_wp(t_format format, va_list lst, char *type) // reflechir pour wchat_t // penser condition -
{
	int width;
	int i;
	char *str;
	char *str2;

	width = 0;
	str = type;
	if (format.width == NULL)
		return (type);
	else if (format.width[0] == '*')
		width = va_arg(lst, int) - ft_strlen(type);
	else if (format.width[0] >= '0' && format.width[0] <= '9')
		width = ft_atoi(format.width) - ft_strlen(type);
	else
		return (type);
	i = 0;
	if (format.flags != NULL && format.flags[0] == '0' && width > 0)
	{
		while (i < width)
		{
			str2 = str;
			str = ft_strjoin("0", str2);
			free(str2);
			i++;
		}
		return (str);
	}
	else
	{
		while (i < width && width > 0)
		{
			ft_putchar(' ');
			i++;
		}
	}
	return (type);
}

int	ft_type(t_format format, va_list lst, char str)
{
	char *type;

	if (str == 's')
		ft_putstr(va_arg(lst, char *));
	else if (str == 'S')
		ft_putwstr(va_arg(lst, wchar_t *));
	else if (str == 'p')
	{
		ft_putstr("0x"); //ptet ajouter un 10
		ft_putstr(ft_itoah(va_arg(lst, int), 1));
	}
	else if (str == 'd' || str == 'i')
	{
		type = ft_itoa(va_arg(lst, int));
		//nbr = ft_strjoin("00", nbr); // pense a free use fonction rempli 0 et strlen
		type = add_wp(format, lst, type);
		ft_putstr(type);
		//ft_putnbr(va_arg(lst, int));
	}
	else if (str == 'D')
		ft_putnbr(va_arg(lst, long int));
	else if (str == 'o')
		ft_putstr(ft_itoao(va_arg(lst, unsigned int)));
	else if (str == 'O')
		ft_putstr(ft_itoao(va_arg(lst, unsigned long)));
	else if (str == 'u')
		ft_putnbr(va_arg(lst, unsigned int));
	else if (str == 'U')
		ft_putnbr(va_arg(lst, unsigned long));
	else if (str == 'x')
		ft_putstr(ft_itoah(va_arg(lst, int), 1));
	else if (str == 'X')
		ft_putstr(ft_itoah(va_arg(lst, unsigned int), 2));
	else if (str == 'c')
		ft_putchar((char)va_arg(lst, int));
	else if (str == 'C')
		ft_putwchar(va_arg(lst, wchar_t));
	else if (str == 'b')				// bonus pas integrer
		ft_putstr(ft_itoab(va_arg(lst, unsigned int)));
	else
		return (0);
	return (1);
}
