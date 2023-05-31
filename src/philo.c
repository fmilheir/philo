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

int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_ph_utils	*utils;

	if (argc == 5 || argc == 6)
	{
		utils = malloc(sizeof(t_ph_utils));
		if (param_init(&philo, utils, argc, argv) == 1)
			return (printf("Invalid arg type/range\n"));
		thread_create_pair(philo);
		while (1)
		{
			if (monitoring(philo, utils) == EXIT){
				return (0);
			}
		}
	}
	return (printf("Invalid number of args\n"));
}
