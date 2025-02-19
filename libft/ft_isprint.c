/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:54:11 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:54:12 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	isprint() checks for any printable character 
	including space (ASCII 32 - 126). 
*/

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}
