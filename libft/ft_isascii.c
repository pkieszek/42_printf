/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:53:54 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:53:55 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	isascii() checks whether c is a 7-bit unsigned char value 
	that fits into the ASCII character set. 
*/

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
