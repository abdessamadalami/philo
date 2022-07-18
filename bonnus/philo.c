/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:54:11 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/18 08:17:33 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



 
void odds_philo(pthread_t *threads, t_phil **philo)
{
    int index;
    int pid;

    index = 0;
    while (index != philo[0]->n_of_t)
    {
        pid = fork();
        if (pid == 0)
        {
           rotin((void *)philo[index]);
           exit(0);
        }
       
       index++;
    }
}

void creat_philos(pthread_t *threads, t_phil **philo, t_par *arg)
 {
    sem_t       *message;
    sem_t       *forks;
    int         i;
    long long   start;

    i = 0;
    forks = sem_open("/forks", 0644, arg->n_philo);
    forks = sem_open("/message", 0644, 1);
    long long start = get_time();
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
        philo[i]->forks = forks;
        philo[i]->last_eat = start;
        i++;   
    }
    odds_philo(threads, philo);
 }