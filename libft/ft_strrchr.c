/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:57:47 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:57:48 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	The strrchr() function returns a pointer to the last occurrence 
	of the character c in the string s. 
*/

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occ;
	size_t		i;

	last_occ = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] == (unsigned char)c)
			last_occ = &str[i];
		++i;
	}
	if (str[i] == (unsigned char)c)
		last_occ = &str[i];
	return ((char *)last_occ);
}
