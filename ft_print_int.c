/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 12:25:24 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/05 19:23:19 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	%i/%d → liczba całkowita (base 10), signed integers
*/

#include "ft_printf.h"

void	ft_print_int(int n, size_t *counter)
{
	char	*num_str;

	num_str = ft_itoa(n);
	if (!num_str)
		return;
	ft_print_string(num_str, counter);
	free(num_str);
}
