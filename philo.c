/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:54:11 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/15 21:39:59 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"



void odds_philo(pthread_t *threads, t_phil **philo)
{
    int index;
    
    index = 0;
    while (index < philo[0]->n_philo)
    {
       pthread_create(&threads[index], NULL, rotin, (void *)philo[index]);
       usleep(100);
       
       index++;
    }
}


pthread_mutex_t *ft_muetx(int n_philo)
{
    int i;
    pthread_mutex_t *vsr;

    i = 0;
    vsr = malloc(sizeof(pthread_mutex_t) * n_philo);
    while (i < n_philo)
    {
        pthread_mutex_init(&vsr[i], NULL);
        i++;
    }
    return (vsr);
}

void creat_philos(pthread_t *threads, t_phil **philo, t_par *arg)
 {
    pthread_mutex_t *forks;
    pthread_mutex_t message;
    pthread_mutex_t m;
    pthread_mutex_t s;
    int i;

    i = 0;
    forks = ft_muetx(arg->n_philo);
    // message = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(&message,0);
    pthread_mutex_init(&m,0);
    pthread_mutex_init(&s,0);
    long long start = get_time();
    while (i < arg->n_philo)
    {
        philo[i] = malloc(sizeof(t_phil));
        philo[i]->n_philo = arg -> n_philo;
        philo[i]->id = i + 1;
        philo[i]->t_die = arg->t_die;
        philo[i]->t_eat = arg->t_eat;
        philo[i]->t_sleep = arg->t_sleep;
        philo[i]->n_t_eat = arg->n_t_eat;
        philo[i]->start = start;
        philo[i]->forks = forks;
        philo[i]->message = message;
        philo[i]->last_eat = start;
        philo[i]->left = i;
        philo[i]->right = (i + 1) % arg->n_philo;
        philo[i]->m = m;
        philo[i]->s = s;
        i++;   
    }
    //printf(" this is the t_die of philoserfer %d = %d \n", philo[0]->id, philo[0]->t_die);
    odds_philo(threads, philo);
    // usleep(200);
    // eveen_philo(threads, philo);
 }