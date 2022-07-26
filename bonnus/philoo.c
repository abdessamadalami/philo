/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philoo.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:54:11 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/22 11:19:38 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_process(int *ptr, int n)
{
	int	index;

	index = 0;
	while (index < n)
	{
		kill(ptr[index], SIGKILL);
		index++;
	}
	free(ptr);
}

void	whait_pro(int *ptr, int n)
{
	int	index;
	int	exit_status;

	index = 0;
	while (index < n)
	{
		waitpid(-1, &exit_status, 0);
		if (WIFEXITED(exit_status) == 1)
			kill_process(ptr, n);
		index++;
	}
}

void	philo_rotine(t_phil **philo)
{
	int	index;
	int	*ptr;

	index = 0;
	ptr = malloc(sizeof(int) * philo[0]->n_philo);
	if (ptr == NULL)
		return ;
	while (index < philo[0]->n_philo)
	{
		philo[index]->last_eat = get_time();
		ptr[index] = fork();
		if (ptr[index] == 0)
		{
			if (philo[index]->id % 2 == 0)
				usleep(200);
			if (rotin((void *)philo[index]))
			{
				printf("error");
				exit(1);
			}
			exit(0);
		}
		index++;
	}
	whait_pro(ptr, philo[0]-> n_philo);
}

void	creat_philos(t_phil **philo, t_par *arg)
{
	int			i;
	long long	start;
	sem_t		*forks;
	sem_t		*message;

	i = 0;
	forks = sem_open("/forks", O_CREAT | O_EXCL, 0644, arg->n_philo);
	message = sem_open("/message", O_CREAT | O_EXCL, 0644, 1);
	start = get_time();
	while (i < arg->n_philo)
	{
		philo[i] = malloc(sizeof(t_phil));
		philo[i]->n_philo = arg->n_philo;
		philo[i]->id = i + 1;
		philo[i]->t_die = arg->t_die;
		philo[i]->t_eat = arg->t_eat;
		philo[i]->t_sleep = arg->t_sleep;
		philo[i]->forks = forks;
		philo[i]->message = message;
		philo[i]->start = start;
		philo[i]->n_t_eat = arg->n_t_eat;
		i++;
	}
	philo_rotine(philo);
}
