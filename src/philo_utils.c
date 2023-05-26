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
		i += 2;
	}
	usleep(25 * philo->utils->n_philo);
	thread_create_unpair(philo, time);
	return (0);
}

/*
create the threads for the od pair of philos, 
it is going to recive the time from the previous 
function that create all the odd philos
i used the pair and even thecnique becouse if 
every philosopher starts at the same time
everyone is going to try to get the left fork and 
no one is going to eat
*/
int	thread_create_unpair(t_philo *philo, long time)
{
	int	i;

	i = 1;
	while (i < philo->utils->n_philo)
	{
		philo[i].start = time;
		if (pthread_create(&philo[i].thread, NULL, &routine, &philo[i]) != 0)
			return (1);
		if (pthread_detach(philo[i].thread) != 0)
			return (1);
		i += 2;
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
		if (utils->loop == utils->n_philo && utils->meals != -1)
			return (EXIT);
		i++;
	}
	return (1);
}
