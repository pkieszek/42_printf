/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:56:04 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:56:05 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	The strchr() function returns a pointer to the first occurrence 
	of the character c in the string s. 
	IT returns a pointer to the matched character or NULL if the character 
	is not found.  The terminating null byte is considered part of the string,
    so that if c is specified as '\0', these function returns 
	a pointer to the terminator.
*/

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	unsigned char	uc;
	unsigned int	i;

	uc = (unsigned char)c;
	i = 0;
	while (str[i])
	{
		if (str[i] == uc)
			return ((char *)&str[i]);
		++i;
	}
	if (str[i] == uc)
		return ((char *)&str[i]);
	return (NULL);
}
