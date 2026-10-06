/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmunoz-j <jmunoz-j@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/02 09:59:11 by jmunoz-j          #+#    #+#             */
/*   Updated: 2026/10/06 12:36:30 by jmunoz-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h> //Quitar!!! Esto es solo para pruebas con printf!!!!!!!!

int	ft_putchar(char c);
int	ft_putstr(char *s);
int	ft_putnbr_hex(unsigned long int nb, char c);
int	ft_putptr(void *ptr);
int	ft_putnbr(int nbr);
int	ft_putnbr_unsigned(unsigned int nbr);
int	ft_printf(char const *format, ...);


#endif