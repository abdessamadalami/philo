/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sultan <sultan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:16:57 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/22 20:52:51 by sultan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


// long long get_time(long long int curnt)
// {
//     struct timeval current;

//     gettimeofday(&current, NULL);
//     long long tiem = current.tv_sec * 1000 + current.tv_usec / 1000;
//     return (tiem - curnt);
// }

static int	index_fun(const char *nbr, int *s)
{
	int	i;

	i = 0;
	while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\v'
		|| nbr[i] == '\n' || nbr[i] == '\f' || nbr[i] == '\r')
		i++;
	if (nbr[i] == '+' || nbr[i] == '-' )
	{
		if (nbr[i] == '-')
			(*s) *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nbr)
{
	int	i;
	int	nb;
	int	s;

	nb = 0;
	s = 1;
	i = index_fun(nbr, &s);
	while (nbr[i] >= '0' && nbr[i] <= '9' )
	{			
		nb = nb * 10 + nbr[i] - '0';
		i++;
	}
	return (nb * s);
}

// void ft_forks(t_phil *philo)
// {
//     int left = philo->id - philo->nbr_hilo % philo->nbr_hilo;
//     int right = philo->id + philo->nbr % philo->nbr_hilo;

//     pthread_mutex_lock(&philo->forks[left]);
//     pthread_mutex_lock(&philo->forks[right]);
//     pthread_mutex_lock
//     printf("%lld %d\n", ft_getime(philo->start),philo->id);
//     ft_usleep(philo->time_eat);
// }

// void ft_muetx(t_philo *philo)
// {
//     int i = 0;
//     pthread_mutex_t vsr;
    
//     vsr = malloc(sizeof(pthread_mutex_t) * philo->shared.n);
//     while (i <= philo->shared.n)
//     {
//         pthread_mutex_init(philo->shared.forks[i], NULL);
//         i++;
//     }
// }


// void    *rotin(void   *ptr)
// {
//     t_phil philo;
//     philo = *(t_phil *)ptr;
    
//     printf("i am philoserfer id   %d \n",philo.id);
//     // while (true)
//     // {
        
//     // }
//     //! eating with LEFT FORK id + N - 1 and right for with id + 1 % n
//     return (void *)ptr;
// }

void odd_philo(t_phil *philo)
{
    int index;
    
    index = 1;
    //ft_muetx(philo);
    printf("i am    philoserfers");
    while (index <= philo->shared->n)
    {
       philo-> id = index;
       pthread_create(&philo->shared->philoserfers[index], NULL, &rotin, &philo);
       sleep(1);
       index+=2;
    }
}

int main(int ac, char *av[])
{
    
    t_phil  philo;
    int     index;

  //  philo.shared->start = ft_getime(0);
    
    index = 0;
    philo.shared.n = ft_atoi(av[1]);
    printf("index\n");
    exit(0);
    philo.shared.philoserfers = malloc(philo.shared.n * sizeof(pthread_t));
    odd_philo(&philo);
    //pintf(" nbr of philoserfer %d \n",philo.n_of_phil);
    //create_thread(philo, id_philo);
}