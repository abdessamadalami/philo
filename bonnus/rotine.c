/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:56:04 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/21 16:05:22 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time)
{
	long	sleep;

	sleep = get_time();
	while (get_time() - sleep < time)
		usleep(200);
}

void	print_mess(char *l, t_phil *philo)
{
	sem_wait(philo->message);
	printf("%lld ms philo %d %s \n", get_time() - philo->start, philo->id, l);
	sem_post(philo->message);
}

void	*check_die(void *ptr)
{
	t_phil	*philo;

	philo = (t_phil *)ptr;
	while (1)
	{
		if (get_time() - philo->last_eat >= philo->t_die)
		{
			sem_wait(philo->message);
			printf("%lld ms philo %d died\n",
				get_time() - philo->start, philo->id);
			exit(1);
		}
	}
	return (0);
}

int	rotin(t_phil	*philo)
{
	pthread_t	*thred_d;
	int			index;

	index = 0;
	thred_d = malloc(sizeof(pthread_t));
	if (pthread_create(thred_d, NULL, check_die, (void *)philo))
		return (1);
	while (index != philo->n_t_eat)
	{
		sem_wait(philo->forks);
		print_mess("has taken fork", philo);
		sem_wait(philo->forks);
		print_mess("has taken fork", philo);
		print_mess("is eating", philo);
		philo->last_eat = get_time();
		ft_usleep(philo->t_eat);
		sem_post(philo->forks);
		sem_post(philo->forks);
		print_mess("is sleeping", philo);
		ft_usleep(philo->t_sleep);
		print_mess("is thinking", philo);
		index++;
	}
	return (0);
}
