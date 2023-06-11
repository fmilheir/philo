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
/*
int		stop(t_philo *philo)
{
	int i;

	i = -1;
	while (i++ < philo->utils->n_philo -1)
		pthread_join(philo[i].thread, NULL);
	pthread_mutex_destroy(&philo->utils->mutex_msg);
	i = -1;
	while (++i < philo->utils->n_philo)
		pthread_mutex_destroy(&philo->utils->fork[i]);
	free(philo->utils);
	return (0);
}
*/


int	main(int argc, char **argv)
{
	t_philo		*philo;
	t_ph_utils	*utils;

	if (argc == 5 || argc == 6)
	{
		utils = malloc(sizeof(t_ph_utils));
		if (param_init(&philo, utils, argc, argv) == 1)
			return (printf("Invalid arg type/range\n"));
		thread_create_thread(philo);
		while (1)
		{
			if (monitoring(philo, utils) == EXIT)
				return(0);
			usleep(50);
		}
	}
	return (printf("Invalid number of args\n"));
}
