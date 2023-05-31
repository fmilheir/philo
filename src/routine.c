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

//print status of the philos
void	mini_print(t_philo *philo, char *str, long time)
{
	pthread_mutex_lock(&philo->utils->mutex_msg);
	printf("%04ld ms : Philo %d %s", time, philo->philo_id, str);
	pthread_mutex_unlock(&philo->utils->mutex_msg);
}

void	routine2(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&philo->utils->fork[philo->left_fork]);
		mini_print(philo, "has taken a fork\n", get_time(philo->start));
		pthread_mutex_lock(&philo->utils->fork[philo->right_fork]);
		mini_print(philo, "has taken a fork\n", get_time(philo->start));
		pthread_mutex_lock(&philo->utils->time);
		philo->last_eaten = get_time(philo->start);
		pthread_mutex_unlock(&philo->utils->time);
		mini_print(philo, "is eating\n", get_time(philo->start));
		sleeper(philo->utils->time_to_eat);
		pthread_mutex_unlock(&philo->utils->fork[philo->left_fork]);
		pthread_mutex_unlock(&philo->utils->fork[philo->right_fork]);
	}
	else {
		pthread_mutex_lock(&philo->utils->fork[philo->right_fork]);
		mini_print(philo, "has taken a fork\n", get_time(philo->start));
		pthread_mutex_lock(&philo->utils->fork[philo->left_fork]);
		mini_print(philo, "has taken a fork\n", get_time(philo->start));
		pthread_mutex_lock(&philo->utils->time);
		philo->last_eaten = get_time(philo->start);
		pthread_mutex_unlock(&philo->utils->time);
		mini_print(philo, "is eating\n", get_time(philo->start));
		sleeper(philo->utils->time_to_eat);
		pthread_mutex_unlock(&philo->utils->fork[philo->left_fork]);
		pthread_mutex_unlock(&philo->utils->fork[philo->right_fork]);
	}
	philo->n_eaten++;
	pthread_mutex_lock(&philo->utils->looper);
	if (philo->n_eaten == philo->utils->meals && philo->utils->meals != -1)
		philo->utils->loop++;
	pthread_mutex_unlock(&philo->utils->looper);
	mini_print(philo, "is sleeping\n", get_time(philo->start));
	sleeper(philo->utils->time_to_sleep);
	mini_print(philo, "is thinking\n", get_time(philo->start));
}

int	prompt_death(t_philo *philo)
{
	mini_print(philo, "died\n", get_time(philo->start));
	return (EXIT);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	while (1)
	{
		routine2(philo);
	}
}
