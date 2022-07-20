/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:54:11 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/19 20:22:42 by sultan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



 
void odds_philo(pthread_t *threads, t_phil **philo)
{
    int index;
    int *ptr;

    index = 0;
    ptr = malloc(sizeof(int) * philo[index]->n_philo);
    while (index < philo[0]->n_philo)
    {
       // printf("%lld ms philo ",philo[index]->start);
        philo[index]->last_eat = get_time();
        ptr[index] = fork();
        if (ptr[index]== 0)
        {
           // printf("%lld ls philo \n",philo[index]->last_eat);
           rotin((void *)philo[index]);
           exit(0);
        }
       index++;
    }
    while (wait(0) != -1)
	{
	} 
}

void creat_philos(pthread_t *threads, t_phil **philo, t_par *arg)
 {
    sem_t       *message;
    sem_t       *forks;
    int         i;
    long long   start;

    i = 0;
    sem_unlink("/dforks");
    sem_unlink("/dmessage");
    forks = sem_open("/dforks", O_CREAT | O_EXCL, 0644, arg->n_philo);
    message = sem_open("/dmessage", O_CREAT | O_EXCL, 0644, 1);
    start = get_time();
    
    while (i < arg->n_philo)
    {
        philo[i] = malloc(sizeof(t_phil));
        philo[i]->n_philo = arg -> n_philo;
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
    odds_philo(threads, philo);
 }