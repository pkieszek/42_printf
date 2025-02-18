/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:46:41 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 18:46:45 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* 
** ft_print_int - Converts an integer to string and prints it
** @num: The integer to be printed
**
** This function takes an integer, converts it to a string using ft_itoa,
** prints the string to standard output (file descriptor 1), and returns
** the number of characters printed.
**
** Return: The number of characters printed, or 0 if memory allocation fails
*/
static int	ft_print_int(int num)
{
	char	*str;  /* Will hold the string representation of num */
	int		len;   /* Will store the length of the string */

	/* Convert int to string using ft_itoa from libft */
	str = ft_itoa(num);
	
	/* Check if memory allocation failed */
	if (!str)
		return (0);
	
	/* Calculate string length using ft_strlen from libft */
	len = ft_strlen(str);
	
	/* Print the string to stdout (fd 1) using ft_putstr_fd from libft */
	ft_putstr_fd(str, 1);
	
	/* Free allocated memory to prevent memory leaks */
	free(str);
	
	/* Return the number of characters printed */
	return (len);
}