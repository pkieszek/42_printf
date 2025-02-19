/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 10:53:41 by pkieszek          #+#    #+#             */
/*   Updated: 2024/12/17 10:53:42 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
isalnum() checks for an alphanumeric character; 
it is equivalent to (isalpha(c) || isdigit(c)). 
*/

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
