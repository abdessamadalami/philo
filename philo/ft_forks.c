#include "philo.h"


void ft_forks()
{
    int left = philo->id - philo->nbr_hilo % philo->nbr_hilo;
    int right = philo->id + philo->nbr % philo->nbr_hilo;

    pthread_mutex_lock(&philo->forks[left]);
    pthread_mutex_lock(&philo->forks[right]);
    pthread_mutex_lock
    printf("%lld %d\n", ft_getime(philo->start),philo->id);
    ft_usleep(philo->time_eat);
}