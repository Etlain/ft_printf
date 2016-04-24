/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 18:45:53 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/04/25 00:00:44 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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
*/
int	ft_type(va_list lst, char str)
{
	//char *nbr;

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
		//nbr = ft_itoa(va_arg(lst, int));
		//nbr = ft_strjoin("00", nbr); // pense a free use fonction rempli 0 et strlen
		//ft_putstr(nbr);
		ft_putnbr(va_arg(lst, int));
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
	else if (str == 'b')
		ft_putstr(ft_itoab(va_arg(lst, unsigned int)));
	else
		return (0);
	return (1);
}
