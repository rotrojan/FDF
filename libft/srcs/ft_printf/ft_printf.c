/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 03:58:20 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/22 16:39:03 by bigo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** This function uses a t_printf structure containing all the informations
** needed to produce the correct output and return value (see the ft_printf.h
** header file for more informations).
** If no '%' flag is encountered, the ft_printf function will put all the
** characters of the "format" format string in the "pf.buf" buffer.
** If a '%' flag is encountered, ft_printf call the ft_conversion function (see
** the conversion.c file for further explainations).
** When "format" is fully parsed, the "pf.buf" buffer is fully printed, and the
** index of "pf.buf" (hence the number of printed characters) plus the number of
** "pf.already_written" (in case of a fullfilled buffer) is returned.
*/

int	ft_vdprintf(int fd, char const *format, va_list args)
{
	t_printf	pf;

	ft_bzero(&pf, sizeof(pf));
	pf.fmt = (char *)format;
	while (pf.fmt[pf.i_fmt])
	{
		if (pf.fmt[pf.i_fmt] != '%')
		{
			pf.buf[pf.i_buf++] = pf.fmt[pf.i_fmt++];
			if (pf.i_buf == BUFFER_SIZE)
				print_buff_and_clear(&pf);
		}
		else
		{
			conversion(&pf, args);
			pf.i_fmt++;
		}
	}
	va_end(args);
	write(fd, pf.buf, pf.i_buf);
	return (pf.i_buf + pf.already_written);
}

int	ft_dprintf(int fd, char const *format, ...)
{
	va_list		args;

	va_start(args, format);
	return (ft_vdprintf(fd, format, args));
}

int	ft_printf(char const *format, ...)
{
	va_list		args;

	va_start(args, format);
	return (ft_vdprintf(STDOUT_FILENO, format, args));
}
