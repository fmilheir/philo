/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:41:31 by filipe            #+#    #+#             */
/*   Updated: 2023/05/25 16:41:32 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosopher.h"

//check what the 255 do!
int	put_error(int *err)
{
	*err = 1;
	return (1);
}

int	check_edges(long long result, int sign, int *err)
{
	if (result > 2147483647 && sign == 1)
		return (put_error(err));
	else if (result == 0)
		return (put_error(err));
	return (result *= sign);
}

//the err is just the return for the fucntion param_int know if ther is a error
int	ft_atoi(const char *str, int *err)
{
	long long	result;
	int			i;

	result = 0;
	i = 0;
	while (str[i] && (str[i] == '\f' || str[i] == '\t' || str[i] == ' '
			|| str[i] == '\n' || str[i] == '\r' || str[i] == '\v'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			return (put_error(err));
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (put_error(err));
		result = (result * 10) + str[i++] - '0';
	}
	return (check_edges(result, 1, err));
}
