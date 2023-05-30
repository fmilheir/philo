/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: filipe <filipe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 16:41:31 by filipe            #+#    #+#             */
/*   Updated: 2023/05/28 22:22:46 by filipe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//populate the struct
#include "../philosopher.h"

int	param_init(t_philo **philo, t_ph_utils *utils, int ac, char **av)
{
	int	i;
	int	err;

	err = 0;
	init_parse(ac, av, utils, &err);
	if (err == 1)
	{
		free(utils);
		return (1);
	}
	i = -1;
	*philo = malloc(sizeof(t_philo) * utils->n_philo);
	while (++i < utils->n_philo)
	{
		(*philo)[i].philo_id = i + 1;
		(*philo)[i].n_eaten = 0;
		(*philo)[i].left_fork = i;
		(*philo)[i].right_fork = i + 1;
		(*philo)[i].last_eaten = 0;
		(*philo)[i].utils = utils;
		if (i == utils->n_philo - 1)
			(*philo)[i].right_fork = 0;
		pthread_mutex_init(&utils->fork[i], NULL);
	}
	return (0);
}

void	init_parse(int ac, char **av, t_ph_utils *utils, int *err)
{		
	utils->n_philo = ft_atoi(av[1], err);
	utils->time_to_die = ft_atoi(av[2], err);
	utils->time_to_eat = ft_atoi(av[3], err);
	utils->time_to_sleep = ft_atoi(av[4], err);
	utils->loop = 0;
	if (ac == 6)
		utils->meals = ft_atoi(av[5], err);
	else
		utils->meals = -1;
	if (*err == 1)
		return ;
	pthread_mutex_init(&utils->mutex_msg, NULL);
	pthread_mutex_init(&utils->time, NULL);
	utils->fork = malloc(sizeof(pthread_mutex_t) * utils->n_philo);
}
