/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:56:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/20 18:23:02 by mmouhssi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_wstrlen(wchar_t *str)
{
	int len;
	int size;
	int i;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		size = ft_sizebyte((long)str[i]);
		if (size < 8)
			len = len + 1;
		else if (size < 12)
			len = len + 2;
		else if (size < 17)
			len = len + 3;
		else if (size < 22)
			len = len + 4;
		i++;
	}
	return (len);
}
