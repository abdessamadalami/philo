/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   message.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:51:10 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/18 08:19:17 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void  print_mess(int fork, char l, t_phil *philo)
{
    fork = 0;
    if (l == 'l')
    {
        // usleep(5000);
        // printf("get time %lld ", get_time(0) - philo->data.start);
        // exit(1);
        printf("%lld ms philo %d has taken left fork \n",get_time() - philo->start ,philo->id);
    }
    if (l == 'r')
    {
        printf("%lld ms philo %d has taken right fork \n",get_time() - philo->start ,philo->id );
    }
    if (l == 'e')
    {
         printf("%lld ms philo %d eating\n",get_time() - philo->start, philo->id);
    }
    if (l == 's')
    {

        printf("%lld ms philo %d sleeping\n",get_time() - philo->start, philo->id);
    }
     if (l == 'd')
        printf("%lld ms philo %d died\n",get_time() - philo->start, philo->id);
      if (l == 't')
        printf("%lld ms philo %d thinking\n",get_time() - philo->start, philo->id);
    
}