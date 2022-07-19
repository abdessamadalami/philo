/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:56:04 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/19 13:25:57 by sultan           ###   ########.fr       */
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
void kill_process(t_phil *philo)
{
    int index;
    index = 0;
    while(index < philo->n_philo)
    {
        kill(philo->pid[index], SIGTERM);
        index++;
        printf(" ssss %d \n",philo->pid[index]);
         kill(0, SIGKILL);
    }
   
}
void *check_die(void *ptr)
{
    int index;
    
    t_phil *philo = (t_phil *)ptr;
    while (1)
    {
    //    printf("%lld \n",get_time() - philo->last_eat);
            if (get_time() - philo->last_eat >= philo->t_die )
            {
                sem_wait(philo->message);
                printf("%lld ms philo %d died\n", get_time() - philo->start, philo->id);
                // sem_close(philo->forks);
                // sem_unlink("/forks");
                // sem_close(philo->message);
                // sem_unlink("/message");
                kill(0, SIGKILL);
                //exit(0);
               // kill_process(philo);
                //kill(0, SIGKILL);
                return 0;
            }
            usleep(200);
           // pthread_mutex_unlock(&philo[index]->m);
    }
    return (0);
}

void    *rotin(t_phil   *philo)
{
   
    pthread_t   *thred_d;
    int index;

    index = 0;
    thred_d = malloc(sizeof(pthread_t));
    pthread_create(thred_d, NULL, check_die, (void *)philo);
    while (index != philo->n_t_eat)
    {
        sem_wait(philo->forks);
        print_mess("has taken fork", philo);
        sem_wait(philo->forks);
        print_mess("has taken fork", philo);
        print_mess("is eating", philo);
        philo->last_eat = get_time();
        ft_usleep(philo->t_eat);
        if(philo->n_t_eat != -1)
            philo->n_t_eat++;
        sem_post(philo->forks);
        sem_post(philo->forks);
        print_mess("is sleeping", philo);
        ft_usleep(philo->t_sleep);
        print_mess("is thinking", philo);
        index++;
    }
    return (NULL);
}