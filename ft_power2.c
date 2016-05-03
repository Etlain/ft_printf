/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:35:40 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/03 17:02:48 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
long long	ft_power2(int nb, int power)
{
	long long result;
	int	i;

	/*if (power > 0)
	{
		result = nb * ft_power2(nb, power - 1);
		printf("val power : %lld\n", result);
		return (result);
	}
	else if (power == 0)
	{
		return (1);
	}
	else if (power == 1)
	{
		return (nb);
	}
	else
	{
		return (0);
	}*/
	i = 0;
	result = 1;
	while (power >= 0)
	{
		result = result * nb;
		//printf("val power : %lld\n", result);
		power--;
	}
	return (result);
}
