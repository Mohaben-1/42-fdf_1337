/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohaben- <mohaben-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 13:21:41 by mohaben-          #+#    #+#             */
/*   Updated: 2025/02/03 11:45:45 by mohaben-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_atoi(char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str++ - '0');
		if (res * sign > INT_MAX)
			return (20000);
		if (res * sign < INT_MIN)
			return (-20000);
	}
	return (res * sign);
}

void	ft_atoi_hex_helper(long *res, char c)
{
	if (c >= '0' && c <= '9')
		*res = *res * 16 + (c - '0');
	else if (c >= 'a' && c <= 'f')
		*res = *res * 16 + (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		*res = *res * 16 + (c - 'A' + 10);
}

int	ft_atoi_hex(char *str)
{
	int		sign;
	long	res;

	sign = 1;
	res = 0;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	if (*str == '0' && (*(str + 1) == 'x' || *(str + 1) == 'X'))
		str += 2;
	while ((*str >= '0' && *str <= '9') || 
		(*str >= 'a' && *str <= 'f') || (*str >= 'A' && *str <= 'F'))
	{
		ft_atoi_hex_helper(&res, *str);
		str++;
	}
	return (res * sign);
}
