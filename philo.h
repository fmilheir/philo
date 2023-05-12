#ifndef PHILO_H
# define PHILO_H

#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>


typedef	struct s_rules
{

	int		phi;
	int		t_die;
	int		t_eat;
	int		t_sleep;
	int		m_eat;
	long int	time;
	int		f_eat;

	//thenho de ver que tipo the mutex eq vou por aqui deforma a que isto continue eficient e rapido
	//
}	t_rules;

typedef	struct	s_philo
{
	t_rules		rules;
	int			test;

}	t_philo;


//utils
int		atoi(char   *value);

//init
int		init_rules(char **argc, t_rules rules);


#endif