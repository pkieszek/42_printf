/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:50:06 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 11:28:05 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	isalpha() checks  for  an  alphabetic character; in the standard "C" locale, 
	it is equivalent to (isupper(c) || islower(c)). 
	In some locales, there may be additional characters for which 
	isalpha() is true—letters which are neither uppercase nor lowercase. 
*/

int	ft_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}
