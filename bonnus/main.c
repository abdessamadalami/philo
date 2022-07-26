/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:16:57 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/22 11:19:58 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}

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

int	main(int ac, char *av[])
{
	t_phil	**philo;
	t_par	*arg;

	arg = 0;
	if (ac == 5 || ac == 6)
	{
		arg = check(ac, av, 1);
		if (arg == NULL)
		{
			printf(" error\n");
			return (1);
		}
		if (arg->n_t_eat == 0 || arg->n_philo == 0)
			return (1);
	}
	else
	{
		printf("error\n");
		return (0);
	}
	philo = malloc(sizeof(t_phil) * arg->n_philo);
	sem_unlink("/forks");
	sem_unlink("/message");
	creat_philos(philo, arg);
}
