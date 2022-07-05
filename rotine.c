/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:56:04 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/05 15:30:50 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void ft_usleep(long time)
{
    long sleep;

    sleep = get_time();
    while (get_time() - sleep < time)
        usleep(200);
}

void    *rotin(void   *ptr)
{
    t_phil *philo;

    philo = (t_phil *)ptr;
    while (1)
    {
        pthread_mutex_lock(&philo->forks[philo->left]);
        print_mess(philo->left,'l', philo);
        pthread_mutex_lock(&philo->forks[philo->right]);
        print_mess(philo->right,'r', philo);
        print_mess(12, 'e', philo);
        philo->last_eat = get_time();
        ft_usleep(philo -> t_eat);
        if (philo->n_t_eat != -1)
                philo->n_t_eat--;
        // usleep(philo->t_eat * 1000);
        pthread_mutex_unlock(&philo->forks[philo->right]);
        pthread_mutex_unlock(&philo->forks[philo->left]);
        print_mess(12, 's', philo);
        //usleep(philo -> t_sleep * 1000);
        ft_usleep(philo->t_sleep);
        print_mess(12, 't', philo);
    }
   // printf("the id of %d in routing function \n", philo->id);
    return (NULL);
}