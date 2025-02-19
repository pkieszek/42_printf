/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:54:51 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:54:52 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	The memset() function fills the first n bytes of the memory area 
	pointed to by s with the constant byte c. 
*/

#include "libft.h"

void	*ft_memset(void *ptr, int value, size_t num)
{
	size_t			i;
	unsigned char	*s;

	i = 0;
	s = ptr;
	while (i < num)
	{
		s[i] = (unsigned char)value;
		++i;
	}
	return (ptr);
}
