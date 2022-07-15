/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:56:04 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/15 21:47:10 by ael-oual         ###   ########.fr       */
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
       // printf("%p \n", philo);
    while (1)
    {
        pthread_mutex_lock(&philo->forks[philo->left]);
        print_mess(philo->left,'l', philo);
        pthread_mutex_lock(&philo->forks[philo->right]);
        print_mess(philo->right, 'r', philo);
        print_mess(12, 'e', philo);
        pthread_mutex_lock(&philo->m);
        philo->last_eat = get_time();
        pthread_mutex_unlock(&philo->m);
        ft_usleep(philo->t_eat);
      
        pthread_mutex_unlock(&philo->forks[philo->right]);
        pthread_mutex_unlock(&philo->forks[philo->left]);
        print_mess(12, 's', philo);
        ft_usleep(philo->t_sleep);
        print_mess(12, 't', philo);
      //  pthread_mutex_lock(&philo->s);
        if (philo->n_t_eat != -1)
        {
            philo->n_t_eat--;
        }
        //pthread_mutex_unlock(&philo->s);
    }
    return (NULL);
}