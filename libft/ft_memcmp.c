/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:54:30 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:54:31 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	memcmp() function compares the first n bytes 
	(each interpreted as unsigned char) of the memory areas s1 and s2.
	It returns 0 if the two strings are identical, 
 	otherwise returns the difference between the first two differing bytes.
*/

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		++i;
	}
	return (0);
}
