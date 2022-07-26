/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:51:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/22 10:46:57 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	print_mess(char *str, t_phil *philo)
{
	pthread_mutex_lock(&philo->message);
	printf("%lld ms philo %d %s \n",
		get_time() - philo->start, philo->id, str);
	pthread_mutex_unlock(&philo->message);
}

pthread_t	*th(int n)
{
	pthread_t	*threads;

	threads = malloc(sizeof(pthread_t) * n);
	if (threads == NULL)
		return (0);
	return (threads);
}

t_phil	**ph(int n)
{
	t_phil		**philo;

	philo = malloc(sizeof(t_phil) * n);
	if (philo == NULL)
		return (0);
	return (philo);
}

static int	index_fun(const char *nbr, int *s)
{
	int	i;

	i = 0;
	while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\v'
		|| nbr[i] == '\n' || nbr[i] == '\f' || nbr[i] == '\r')
		i++;
	if (nbr[i] == '+' || nbr[i] == '-' )
	{
		if (nbr[i] == '-')
			(*s) *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nbr)
{
	int	i;
	int	nb;
	int	s;

	nb = 0;
	s = 1;
	i = index_fun(nbr, &s);
	while (nbr[i] >= '0' && nbr[i] <= '9' )
	{			
		nb = nb * 10 + nbr[i] - '0';
		i++;
	}
	return (nb * s);
}
