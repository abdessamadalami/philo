/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:54:11 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/20 18:40:08 by sultan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void kill_process(int *ptr, int n)
{
    int index;

    index = 0;
    while(index < n)
   {
      kill(ptr[index], SIGKILL);
      index++;
   }
}

void whait_pro(int *ptr, int n)
{
   int index;
   int exit_status;
   
   index = 0;
   while(index < n)
   {
      waitpid(ptr[index], &exit_status, 0);
      if(WIFEXITED(exit_status))
         kill_process(ptr, n);
      index++;
   }
}
 
void  philo_rotine(t_phil **philo)
{
    int index;
    int *ptr;
    int exit_status;
    

    index = 0;
    ptr = malloc(sizeof(int) * philo[0]->n_philo);
    while (index < philo[0]->n_philo)
   {
        philo[index]->last_eat = get_time();
        ptr[index] = fork();
        if (ptr[index] == 0)
        {
           rotin((void *)philo[index]);
           exit(0);
        }
       index++;
   }
   whait_pro(ptr, philo[0]-> n_philo);
}

void creat_philos(t_phil **philo, t_par *arg)
 {
   int         i;
   long long   start;
   sem_t *forks;
   sem_t *message;
   
   i = 0;
   sem_unlink("/dforks");
   sem_unlink("/dmessage");
   forks = sem_open("/dforks", O_CREAT | O_EXCL, 0644, arg->n_philo);
   message  = sem_open("/dmessage", O_CREAT | O_EXCL, 0644, 1);
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
   
   philo_rotine(philo);
}