/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:56:04 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/18 08:21:46 by ael-oual         ###   ########.fr       */
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

int check_die(t_phil **philo)
{
    int index;

    while (1)
    {
        index = 0;
        while (philo[index] && index < philo[index]->n_philo)
        {
            pthread_mutex_lock(&philo[index]->m);
            if (get_time() - philo[index]->last_eat >= philo[index]->t_die )
            {
                pthread_mutex_lock(&philo[index]->message);
                printf("%lld ms philo %d died\n", get_time() - philo[index]->start, philo[index]->id);
                return (1);
            }
            pthread_mutex_unlock(&philo[index]->m);
            index++;
        }
    }
    return (0);
}

void    *rotin(void   *ptr)
{
    t_phil      *philo;
    pthread_t   *thred_d;
    
    philo = (t_phil *)ptr;
    thred_d = malloc(sizeof(pthread_t));
    pthread_create(&thred_d, NULL, check_die, (void *)philo);
   
    
    while (1)
    {
       // pthread_mutex_lock(&philo->forks[philo->left]);
       // print_mess(philo->left,'l', philo);
      //  pthread_mutex_lock(&philo->forks[philo->right]);
     //   print_mess(philo->right, 'r', philo);
        print_mess(12, 'e', philo);
     //   pthread_mutex_lock(&philo->m);
        philo->n_t_eat++;
        // pthread_mutex_unlock(&philo->m);
        // pthread_mutex_lock(&philo->m);
        philo->last_eat = get_time();
        // pthread_mutex_unlock(&philo->m);
        ft_usleep(philo->t_eat);
        // pthread_mutex_unlock(&philo->forks[philo->right]);
        // pthread_mutex_unlock(&philo->forks[philo->left]);
        print_mess(12, 's', philo);
        ft_usleep(philo->t_sleep);
        print_mess(12, 't', philo);
    }
    return (NULL);
}