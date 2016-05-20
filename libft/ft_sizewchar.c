/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sizewchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhssi <mmouhssi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 16:56:14 by mmouhssi          #+#    #+#             */
/*   Updated: 2016/05/20 18:56:39 by mmouhssi         ###   ########.fr       */
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
