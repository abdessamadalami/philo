/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:51:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/19 11:38:19 by sultan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void  print_mess(char *l, t_phil *philo)
{

   
        // usleep(5000);
        // printf("get time %lld ", get_time(0) - philo->data.start);
        // exit(1);
        sem_wait(philo->message);
        printf("%lld ms philo %d %s \n",get_time() - philo->start ,philo->id, l);
        sem_post(philo->message);
    // if (l == 'r')
    // {
    //    // sem_wait(philo->message);
    //     printf("%lld ms philo %d has taken fork \n",get_time() - philo->start ,philo->id );
    //    // sem_post(philo->message);
    // }
    // if (l == 'e')
    // {
    //     //sem_wait(philo->message);
    //     printf("%lld ms philo %d eating\n",get_time() - philo->start, philo->id);
    //   //  sem_post(philo->message);
    // }
    // if (l == 's')
    // {
    //   //  sem_wait(philo->message);
    //     printf("%lld ms philo %d sleeping\n",get_time() - philo->start, philo->id);
    // //    sem_post(philo->message);
    // }
    //  if (l == 'd')
    //  {
    //    // sem_wait(philo->message);
    //     printf("%lld ms philo %d died\n",get_time() - philo->start, philo->id);
    //   //  sem_post(philo->message);
    //  }
    //   if (l == 't')
    // {
    //    // sem_wait(philo->message);
    //     printf("%lld ms philo %d thinking\n",get_time() - philo->start, philo->id);
    //  //   sem_post(philo->message);
    // }
    
}