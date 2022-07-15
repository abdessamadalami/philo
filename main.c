/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:16:57 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/15 20:07:00 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long long get_time(void)
{
    struct timeval current;

    gettimeofday(&current, NULL);
    long long tiem = current.tv_sec * 1000 + current.tv_usec / 1000;
    return (tiem);
}


 int check_n(t_phil **philo , int n_p)
 {
    
    int index = 0;
    while (index < n_p)
    {
       // pthread_mutex_lock(&philo[index]->m);
        if(philo[index]->n_t_eat != 0)
            return 0;
        index++;
       // pthread_mutex_unlock(&philo[index]->m);
    }
    return 1;
 }
 
 int check_die(t_phil **philo, t_par *arg)
 {
    int index;
    
    while (1)
    {
        index = 0;
        while (philo[index] && index < arg->n_philo )
        {
            pthread_mutex_lock(&philo[index]->m);
            if (get_time() - philo[index]->last_eat >= philo[index]->t_die )
            {
                pthread_mutex_lock(&philo[index]->message);
                printf("%lld ms philo %d died\n", get_time() - philo[index]->start, philo[index]->id);
              //   pthread_mutex_destroy(&philo[index]->m);
                return (1);
            }
           pthread_mutex_unlock(&philo[index]->m);
          // 
            if (check_n(philo,arg->n_philo))
            {
               //  pthread_mutex_destroy(&philo[index]->m);
                return (1);
            }
            pthread_mutex_destroy(&philo[index]->m);
           // pthread_mutex_unlock(&philo[index]->m);
            index++;
        }
    }
    return (0);
 }
 
int main(int ac, char *av[])
{
    
    t_phil  **philo;
    t_par   *arg;
    pthread_t *threads;

    arg = 0;
    if (ac == 5 || ac == 6)
    {
        arg = check(ac , av);
        if (arg == NULL)
        {
            printf(" error\n");
            return (1);
        }
        if (arg->n_t_eat == 0 || arg->n_philo == 0)
            return (1);
    } 
    else
    {
        printf("error\n");
        return (0);
    }
    threads = malloc(sizeof(pthread_t) * arg->n_philo);
    philo = malloc(sizeof(t_phil) * arg->n_philo);
    creat_philos(threads, philo, arg);
    if(check_die(philo, arg))
        return (0);
}