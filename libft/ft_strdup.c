/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:56:25 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:56:26 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The  strdup()  function  returns  a  pointer to  a  new string which is 
	a duplicate of the string s.  Memory for the new string is obtained with 
	malloc(3), and can be freed with free(3).
*/

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*ptr;
	int		n;
	int		l;

	l = ft_strlen(s);
	n = 0;
	ptr = malloc(sizeof(char) * l + 1);
	if (ptr == NULL)
		return (NULL);
	while (s[n])
	{
		ptr[n] = s[n];
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}
