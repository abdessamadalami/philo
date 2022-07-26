/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:16:57 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/22 10:54:28 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_time(void)
{
	struct timeval	current;
	long long		tiem;

	gettimeofday(&current, NULL);
	tiem = current.tv_sec * 1000 + current.tv_usec / 1000;
	return (tiem);
}

int	check_n(t_phil **philo, int n_p, int n_eat)
{
	int	index;

	index = 0;
	while (index < n_p)
	{
		if (philo[index]->n_t_eat != n_eat)
			return (0);
		index++;
	}
	return (1);
}

int	check_die(t_phil **philo, t_par *arg)
{
	int	index;

	while (1)
	{
		index = 0;
		while (philo[index] && index < arg->n_philo)
		{
			pthread_mutex_lock(&philo[index]->m);
			if (get_time() - philo[index]->last_eat >= philo[index]->t_die)
			{
				pthread_mutex_lock(&philo[index]->message);
				printf("%lld ms philo %d died\n",
					get_time() - philo[index]->start, philo[index]->id);
				return (1);
			}
			pthread_mutex_unlock(&philo[index]->m);
			if (arg->n_t_eat != -1
				&& check_n(philo, arg->n_philo, arg->n_t_eat))
				return (1);
			index++;
		}
	}
	return (0);
}

static	int	check_check(int ac, char **av, t_par	**arg)
{
	if (ac == 5 || ac == 6)
	{
		*arg = check(ac, av);
		if (arg == NULL)
		{
			printf(" error\n");
			return (0);
		}
		if ((*arg)->n_t_eat == 0 || (*arg)->n_philo == 0)
			return (0);
	}
	else
	{
		printf("error\n");
		return (0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_phil		**philo;
	t_par		*arg;
	pthread_t	*threads;

	arg = 0;
	check_check(ac, av, &arg);
	if (arg == NULL)
		return (0);
	philo = ph(arg->n_philo);
	threads = th(arg->n_philo);
	creat_philos(threads, philo, arg);
	if (check_die(philo, arg))
		return (0);
}
