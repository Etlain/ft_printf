/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoao.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/03 23:05:39 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/06/01 19:50:14 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void					ft_max(unsigned long long s, int *i, int *h)
{
	if (*i > 20 && s == 0)
	{
		*i = 21;
		*h = 1;
	}
}

static unsigned long long	ft_less(unsigned long long nbr, int *i, int *h)
{
	unsigned long long s;

	s = 0;
	while (s < nbr)
	{
		s = ft_power(8, *i) * *h;
		if (s == 0)
			break ;
		(*i)++;
	}
	ft_max(s, i, h);
	s == nbr ? *h = 1 : 0;
	s >= nbr ? (*i)-- : 0;
	while (s > nbr || (s == 0 && nbr != 0))
	{
		*h < 1 ? (*i)-- : 0;
		*h < 1 ? *h = 7 : 0;
		s = ft_power(8, *i) * *h;
		s > nbr ? (*h)-- : 0;
		s <= 0 ? (*h)-- : 0;
	}
	return (s);
}

static char					*init_str(int i)
{
	char *str;

	str = (char *)malloc(sizeof(char) * (i + 1));
	ft_init_str(str, '0', i + 1);
	str[i + 1] = '\0';
	return (str);
}

char						*ft_lltoao(unsigned long long nbr)
{
	unsigned long long	l;
	char				*str;
	int					i;
	int					h;
	int					max;

	if (nbr == 0)
	{
		str = (char *)ft_memalloc(2);
		strcat(str, "0");
		return (str);
	}
	i = 0;
	h = 7;
	l = ft_less(nbr, &i, &h);
	max = i;
	str = init_str(i);
	i = max;
	while (i >= 0 && nbr != 0)
	{
		nbr = nbr - l;
		str[max - i] = h + '0';
		l = ft_less(nbr, &i, &h);
	}
	return (str);
}
