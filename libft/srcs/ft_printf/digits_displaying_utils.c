/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_displaying_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rotrojan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 13:30:49 by rotrojan          #+#    #+#             */
/*   Updated: 2021/06/21 17:37:12 by rotrojan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** The "get_len_digit" function return the number of characters that will be
** printed according to the corresponding type and base. It allows to perform
** the right padded outputs.
*/

static int	get_len_signed(unsigned long int d, int base)
{
	int			len;
	long int	tmp;

	len = 1;
	tmp = (int)d;
	while (tmp)
	{
		len++;
		tmp /= base;
	}
	return (len);
}

int	get_len_digit(unsigned long int d, int base, t_spec *spec)
{
	int			len;

	if (!d)
		return (1);
	if (spec->conv == 'd' || spec->conv == 'i')
		len = get_len_signed(d, base);
	else if (spec->conv == 'u' || spec->conv == 'x'
		|| spec->conv == 'X' || spec->conv == 'p')
	{
		len = 1;
		if (spec->conv != 'p')
			d = (unsigned int)d;
		while (d)
		{
			len++;
			d /= base;
		}
	}
	else
		return (-1);
	return (len);
}

/*
** The "put_nbr_buffer" function will perform about the same than the ft_putnbr
** function, but the number will be printed in the pf->buff buffer instead of
** the standard output. The "put_hexa_buffer" function does the same, but in a
** specified hexadecimal base.
*/

void	put_nbr_buffer(int nbr, t_printf *pf, t_spec *spec)
{
	long int	nb;

	nb = nbr;
	if (spec->conv == 'i' || spec->conv == 'd')
	{
		if (nb < 0)
			nb = -nb;
	}
	else
		nb = (unsigned int)nbr;
	if (nb >= 10)
	{
		put_nbr_buffer(nb / 10, pf, spec);
		write_in_buff_and_increment(pf, spec, (nb % 10) + '0');
	}
	else
		write_in_buff_and_increment(pf, spec, nb + '0');
}

void	put_hexa_buffer(uintmax_t nb, t_printf *pf, t_spec *spec, char base[16])
{
	if (nb >= 16)
	{
		put_hexa_buffer(nb / 16, pf, spec, base);
		write_in_buff_and_increment(pf, spec, base[nb % 16]);
	}
	else
		write_in_buff_and_increment(pf, spec, base[nb]);
}
