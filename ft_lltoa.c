/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 11:54:54 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/02 22:05:35 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static long	long ft_dizaine(char **str, long long n)
{
	int			nbr;
	int			i;
	long long	dizaine;

	nbr = n;
	dizaine = 1;
	i = 1;
	while (nbr > 9 || nbr < -9)
	{
		nbr = nbr / 10;
		i++;
		dizaine = dizaine * 10;
	}
	if (n < 0)
		i++;
	*str = (char*)malloc(sizeof(char) * (i + 1));
	return (dizaine);
}

char static	*ft_fill(char *str, long long nbr, long long dizaine, int *i)
{
	int s;

	s = 0;
	while (dizaine > 9)
	{
		s = s + (str[*i] - '0') * dizaine;
		dizaine = dizaine / 10;
		(*i)++;
		str[*i] = (nbr - s) / dizaine + '0';
	}
	return (str);
}

char		*ft_lltoa(long long n)
{
	char	*str;
	long long	dizaine;
	int		i;
	long long	nbr;

	i = 0;
	str = NULL;
	nbr = (long long)n;
	dizaine = ft_dizaine(&str, nbr);
	if (str == NULL)
		return (NULL);
	if (nbr < 0)
	{
		str[i] = '-';
		i++;
		nbr = nbr * (-1);
	}
	str[i] = '0' + (nbr / dizaine);
	str = ft_fill(str, nbr, dizaine, &i);
	str[i + 1] = '\0';
	return (str);
}
