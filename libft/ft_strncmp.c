/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:57:35 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:57:36 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	The strcmp() function compares the two strings s1 and s2.  
	The locale is not taken into account (for a locale-aware comparison, 
	see strcoll(3)). The comparison is done using un‐signed characters.

       strcmp() returns an integer indicating the result of the comparison, 
	   as follows:

       •  0, if the s1 and s2 are equal;
       •  a negative value if s1 is less than s2;
       •  a positive value if s1 is greater than s2.

       The strncmp() function is similar, except it compares only 
	   the first (at most) n bytes of s1 and s2.
 */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((i < (n - 1)) && s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
