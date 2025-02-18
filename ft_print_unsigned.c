/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkieszek <pkieszek@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 18:47:15 by pkieszek          #+#    #+#             */
/*   Updated: 2025/02/18 18:47:22 by pkieszek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

/* 
** ft_utoa - Converts an unsigned integer to a string
** @n: The unsigned integer to convert
**
** This is a custom function similar to ft_itoa, but designed for unsigned integers.
** It calculates the number of digits needed, allocates memory for the string,
** and fills it by converting each digit to its character representation.
**
** Return: A newly allocated string representing the unsigned integer, or NULL if allocation fails
*/
static char	*ft_utoa(unsigned int n)
{
	char			*str;   /* Will hold the string representation */
	int				len;    /* Length of the resulting string */
	unsigned int	temp;   /* Temporary variable for calculating length */

	/* Calculate how many digits are in the number */
	len = 1;
	temp = n;
	while (temp >= 10)
	{
		temp /= 10;
		len++;
	}
	
	/* Allocate memory for the string (length + null terminator) */
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	
	/* Add null terminator at the end of the string */
	str[len] = '\0';
	
	/* Fill the string from right to left with digits */
	while (len > 0)
	{
		str[--len] = (n % 10) + '0';  /* Convert last digit to character */
		n /= 10;                      /* Move to the next digit */
	}
	
	return (str);
}

/* 
** ft_print_unsigned - Converts an unsigned integer to string and prints it
** @num: The unsigned integer to be printed
**
** This function uses ft_utoa to convert the unsigned integer to a string,
** prints it to standard output (file descriptor 1), and returns the number
** of characters printed.
**
** Return: The number of characters printed, or 0 if memory allocation fails
*/
static int	ft_print_unsigned(unsigned int num)
{
	char	*str;  /* Will hold the string representation of num */
	int		len;   /* Will store the length of the string */

	/* Convert unsigned int to string using our custom ft_utoa function */
	str = ft_utoa(num);
	
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