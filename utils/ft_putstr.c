/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:10:53 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/07 12:00:07 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Description:
// 		Outputs a string to the standard output (stdout).
// 
// Parameters:
// 		s, string to write in stdout
//
// Return value:
// 		Returns the number of characters printed, or -1 if an error occurs.

#include "../includes/ft_printf.h"

int	ft_putstr(char *s)
{
	unsigned int	i;

	if (!s)
	{
		if (write (1, "(null)", 6) < 0)
			return (-1);
		return (6);
	}
	i = 0;
	while (s[i])
		i++;
	if (write (1, s, i) < 0)
		return (-1);
	return (i);
}
