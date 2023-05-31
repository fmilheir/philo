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
//create te threads for the even pairs of philos
int	thread_create_pair(t_philo *philo)
{
	int		i;
	long	time;

	time = get_time(0);
	i = 0;
	while (i < philo->utils->n_philo)
	{
		philo[i].start = time;
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (1);
		if (pthread_detach(philo[i].thread) != 0)
			return (1);
		i ++;
	}
	return (0);
}

int	monitoring(t_philo *philo, t_ph_utils *utils)
{
	int		i;
	long	time;

	i = 0;
	while (i < philo->utils->n_philo)
	{
		pthread_mutex_lock(&philo->utils->time);
		time = get_time(philo[i].start + philo[i].last_eaten);
		pthread_mutex_unlock(&philo->utils->time);
		if (time >= philo[i].utils->time_to_die)
			return (prompt_death(&philo[i]));
		pthread_mutex_lock(&philo->utils->looper);
		if (utils->loop == utils->n_philo && utils->meals != -1)
			return (EXIT);
		pthread_mutex_unlock(&philo->utils->looper);
		i++;
	}
	return (1);
}
