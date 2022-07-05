/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:51:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/04 12:44:22 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void  print_mess(int fork, char l, t_phil *philo)
{
    fork =0;
    if (l == 'l')
    {
        // usleep(5000);
        // printf("get time %lld ", get_time(0) - philo->data.start);
        // exit(1);
        pthread_mutex_lock(&philo->message);
        printf("%lld ms philo %d has taken left fork \n",get_time() - philo->start ,philo->id);
        pthread_mutex_unlock(&philo->message);
    }
    if (l == 'r')
    {
    pthread_mutex_lock(&philo->message);
        printf("%lld ms philo %d has taken right fork \n",get_time() - philo->start ,philo->id );
    pthread_mutex_unlock(&philo->message);
    }
    if (l == 'e')
    {
        pthread_mutex_lock(&philo->message);
         printf("%lld ms philo %d eating\n",get_time() - philo->start, philo->id);
        pthread_mutex_unlock(&philo->message);
    }
    if (l == 's')
    {
        pthread_mutex_lock(&philo->message);
        printf("%lld ms philo %d sleeping\n",get_time() - philo->start, philo->id);
        pthread_mutex_unlock(&philo->message);
    }
     if (l == 'd')
    {
        pthread_mutex_lock(&philo->message);
        printf("%lld ms philo %d died\n",get_time() - philo->start, philo->id);
        pthread_mutex_unlock(&philo->message);
    }
      if (l == 't')
    {
       pthread_mutex_lock(&philo->message);
        printf("%lld ms philo %d thinking\n",get_time() - philo->start, philo->id);
        pthread_mutex_unlock(&philo->message);
    }
    
}