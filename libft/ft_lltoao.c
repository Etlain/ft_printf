/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoao.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 22:36:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/19 18:37:25 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	val_oct(long long *nbr)
{
	long long octal;

	octal = 0;
	if (*nbr & (long long)1)
		octal = 1;
	if (*nbr & (long long)2)
		octal = octal + 2;
	if (*nbr & (long long)4)
		octal = octal + 4;
	*nbr = *nbr >> 3;
	return (octal);
}

char		*ft_lltoao(unsigned long long nbr)
{
	return (ft_base((long long)nbr, val_oct));
}
