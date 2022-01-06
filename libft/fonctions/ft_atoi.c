/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajung <ajung@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:31:48 by ajung             #+#    #+#             */
/*   Updated: 2021/11/25 18:36:45 by ajung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *nptr)
{
	int				i;
	long long		output;
	int				sign;

	i = 0;
	output = 0;
	sign = 1;
	while (((9 <= nptr[i]) && (nptr[i] <= 13)) || (nptr[i] == ' '))
		i++;
	if ((nptr[i] == '-') || (nptr[i] == '+'))
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (('0' <= nptr[i]) && (nptr[i] <= '9'))
	{
		output = nptr[i] - '0' + (output * 10);
		i++;
		if (output * sign > 2147483647)
			return (-1);
		else if (output * sign < -2147483648)
			return (0);
	}
	return (output * sign);
}
