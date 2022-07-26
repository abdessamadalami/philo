/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:54:11 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/22 11:05:21 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	odds_philo(pthread_t *threads, t_phil **philo)
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	message;
	pthread_mutex_t	m;
	int				index;

	forks = ft_muetx(philo[0]->n_philo);
	pthread_mutex_init(&message, 0);
	pthread_mutex_init(&m, 0);
	index = 0;
	while (index < philo[0]->n_philo)
	{
		philo[index]->forks = forks;
		philo[index]->message = message;
		philo[index]->m = m;
		pthread_create(&threads[index], NULL, rotin, (void *)philo[index]);
		usleep(100);
		index++;
	}
}

pthread_mutex_t	*ft_muetx(int n_philo)
{
	int				i;
	pthread_mutex_t	*vsr;

	i = 0;
	vsr = malloc(sizeof(pthread_mutex_t) * n_philo);
	while (i < n_philo)
	{
		pthread_mutex_init(&vsr[i], NULL);
		i++;
	}
	return (vsr);
}

void	creat_philos(pthread_t *threads, t_phil **philo, t_par *arg)
{
	int				i;
	long long		start;

	i = 0;
	start = get_time();
	while (i < arg->n_philo)
	{
		philo[i] = malloc(sizeof(t_phil));
		philo[i]->n_philo = arg -> n_philo;
		philo[i]->id = i + 1;
		philo[i]->t_die = arg->t_die;
		philo[i]->t_eat = arg->t_eat;
		philo[i]->t_sleep = arg->t_sleep;
		philo[i]->n_t_eat = 0;
		philo[i]->start = start;
		philo[i]->last_eat = start;
		philo[i]->left = i;
		philo[i]->right = (i + 1) % arg->n_philo;
		i++;
	}
	odds_philo(threads, philo);
}
