/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 20:01:12 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/19 02:17:35 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/*
 * Converts an unsigned integer to a string.
 */
char	*ft_utoa(unsigned int num)
{
	char	buffer[20];
	int		i;

	i = 19;
	buffer[i] = '\0';
	while (num >= 10)
	{
		buffer[--i] = (num % 10) + '0';
		num /= 10;
	}
	buffer[--i] = num + '0';
	return (ft_strdup(&buffer[i]));
}

/*
 * Prints an unsigned integer and returns its length.
 */
int	ft_print_unsigned(unsigned int num)
{
	char	*str;
	int		len;

	str = ft_utoa(num);
	len = ft_strlen(str);
	ft_putstr_fd(str, 1);
	free(str);
	return (len);
}
