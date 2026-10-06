/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 13:10:53 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/06 11:30:05 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		if (write (1, &s[i], 1) < 0)
			return (-1);
		else
			i++;
	}
	return (i);
}
