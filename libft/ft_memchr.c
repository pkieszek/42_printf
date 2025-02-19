/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:54:24 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:54:25 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The  memchr()  function scans the initial n bytes of the memory area 
	pointed to by s for the first instance of c.  
	Both c and the bytes of the memory area pointed to by s 
	are interpreted as unsigned char.
	It returns a pointer to the matching byte or NULL 
	if the character does not occur in the given memory area.
*/

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	uc;

	i = 0;
	str = (unsigned char *)s;
	uc = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == uc)
			return ((void *)&str[i]);
		++i;
	}
	return (NULL);
}
