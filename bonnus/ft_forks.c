/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_forks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 12:38:55 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/04 12:38:56 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"


void ft_forks()
{
    int left = philo->id - philo->nbr_hilo % philo->nbr_hilo;
    int right = philo->id + philo->nbr % philo->nbr_hilo;

    pthread_mutex_lock(&philo->forks[left]);
    pthread_mutex_lock(&philo->forks[right]);
    pthread_mutex_lock
    printf("%lld %d\n", ft_getime(philo->start),philo->id);
    ft_usleep(philo->time_eat);
}