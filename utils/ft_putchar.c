/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:07:48 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/07 11:54:35 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description:
// 		Outputs a char to the standard output (stdout).
// 
// Parameters:
// 		c, char to write in stdout
//
// Return value:
// 		Returns the number of characters printed, or -1 if an error occurs.

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}
