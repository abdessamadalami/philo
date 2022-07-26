/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:56:04 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/22 07:24:12 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(long time)
{
	long long	sleep;

	sleep = get_time();
	while (get_time() - sleep < time)
		usleep(200);
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

void	*rotin(void *ptr)
{
	t_phil	*philo;

	philo = (t_phil *)ptr;
	while (1)
	{
		pthread_mutex_lock(&philo->forks[philo->left]);
		print_mess("has taken fork", philo);
		pthread_mutex_lock(&philo->forks[philo->right]);
		print_mess("has taken fork", philo);
		print_mess("is eating", philo);
		pthread_mutex_lock(&philo->message);
		philo->n_t_eat++;
		pthread_mutex_unlock(&philo->message);
		pthread_mutex_lock(&philo->message);
		philo->last_eat = get_time();
		pthread_mutex_unlock(&philo->message);
		ft_usleep(philo->t_eat);
		pthread_mutex_unlock(&philo->forks[philo->right]);
		pthread_mutex_unlock(&philo->forks[philo->left]);
		print_mess("is sleeping", philo);
		ft_usleep(philo->t_sleep);
		print_mess("is thinking", philo);
	}
	return (NULL);
}
