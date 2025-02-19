/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:54:18 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:54:19 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Allocates (with malloc(3)) and returns a string representing the integer 
	received as an argument. Negative numbers must be handled.
	It returns the string representing the integer 
	or NULL if the allocation fails.
*/

#include "libft.h"

static long	number_len(long n)
{
	long	size;

	size = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		size++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static int	is_negative(int n)
{
	return (n < 0);
}

char	*ft_itoa(int n)
{
	long	n_long;
	long	len;
	char	*value;

	n_long = n;
	len = number_len(n_long);
	value = malloc(len + 1);
	if (value == NULL)
		return (NULL);
	value[len] = '\0';
	len--;
	if (n_long < 0)
		n_long = -n_long;
	while (len >= 0)
	{
		value[len] = (n_long % 10) + '0';
		len--;
		n_long /= 10;
	}
	if (is_negative(n) == 1)
		value[0] = '-';
	return (value);
}
