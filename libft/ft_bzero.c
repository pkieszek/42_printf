/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:53:16 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:53:17 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
The bzero() function erases the data in the n bytes of the memory 
starting at the location pointed to by s, 
by writing zeros (bytes containing '\0') to that area. 
*/

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
