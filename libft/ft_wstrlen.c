/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:56:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/20 18:58:01 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sizewchar(long n)
{
	int size;

	size = ft_sizebyte(n);
	if (size < 8)
		return (1);
	else if (size < 12)
		return (2);
	else if (size < 17)
		return (3);
	else if (size < 22)
		return (4);
	return (0);
}

int	ft_wstrlen(wchar_t *str)
{
	int len;
	int i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		len = len + ft_sizewchar((long)str[i]);
		i++;
	}
	return (len);
}
