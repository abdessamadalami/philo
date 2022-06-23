/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:16:57 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/23 17:14:28 by ael-oual         ###   ########.fr       */
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

void ft_forks(t_phil *philo)
{
    int left;
    int right;

    left = (philo->id + philo->n_philo) % philo->n_philo;
    right =( philo->id + philo->n_philo) % philo->n_philo;
   // pthread_mutex_lock(&philo->forks[left]);
    printf("philo %d has taken left %d ", philo->id, left);
   // pthread_mutex_lock(&philo->forks[right]);
    printf("and right %d forks \n", right);
    //pthread_mutex_lock
    usleep(philo->t_eat);
   // printf(" this philo id %d eating\n", philo->id);
    // pthread_mutex_unlock(&philo->forks[left]);
    // pthread_mutex_unlock(&philo->forks[right]);
   // printf("philo %d  left fork %d \n", philo->id, left);
   // printf("%lld %d\n", ft_getime(philo->start),philo->id);
}

 pthread_mutex_t *ft_muetx(int n_philo)
{
    int i = 0;
    pthread_mutex_t *vsr;
    
    vsr = malloc(sizeof(pthread_mutex_t) * n_philo);
    while (i <= n_philo)
    {
        pthread_mutex_init(&vsr[i], NULL);
        i++;
    }
    return (vsr);
}

void    *rotin(void   *ptr)
{
    t_phil *philo;

    philo = (t_phil *)ptr;
    ft_forks(philo);
    printf("the id of %d in routing function \n", philo->id);
    return (NULL);
}

void odds_philo(pthread_t *threads, t_phil **philo)
{
    int index;
    
    index = 0;
    while (index < philo[0]->n_philo)
    {
       pthread_create(&threads[index], NULL, rotin, (void *)philo[index]);
       index+=2;
    }
}

void eveen_philo(pthread_t *threads, t_phil **philo)
{
    int index;
    
    index = 1;
   // printf("%d  n philo. \n",philo[1]->n_philo );
    while (index < philo[0]->n_philo)
    {
       pthread_create(&threads[index], NULL, rotin, (void *)philo[index]);
       index+=2;
    }
}

 void creat_philos(pthread_t *threads, t_phil **philo, t_par *arg)
 {
    int index;
    pthread_mutex_t *forks;
    int i;

    i = 0;
    forks = ft_muetx(arg->n_philo);
    while (i < arg->n_philo)
    {
        philo[i] = malloc(sizeof(t_phil));
        philo[i]->n_philo = arg -> n_philo;
        philo[i]->id = i + 1;
        philo[i]->t_die = arg-> t_die;
        philo[i]->t_eat = arg-> t_eat;
        philo[i]->t_sleep = arg-> t_sleep;
        philo[i]->n_t_eat = arg-> n_t_eat;
        philo[i]->start = 0;
        philo[i]->forks = forks; 
        //pthread_create(&threads[i], NULL, rotin , (void * )philo[i]);
        i++;   
    }
    //printf(" this is the t_die of philoserfer %d = %d \n", philo[0]->id, philo[0]->t_die);
     odds_philo(threads, philo);
    //  usleep(500);
    //  eveen_philo(threads, philo);
 }
       
int main(int ac, char *av[])
{
    
    t_phil  **philo;
    int     index;
    t_par   *arg;
    pthread_t *threads;

    // philo.shared.philoserfers = malloc(philo.shared.n * sizeof(pthread_t));
    if (ac == 5 || ac == 6)
    {
        arg = check(ac , av);
        if (arg == NULL)
        {
            printf(" error\n");
            return 1;
        }
        // printf(" %d\n %d\n %d\n %d\n %d\n", arg->n_philo, arg->t_die, arg->t_sleep ,arg->t_eat , arg->n_t_eat);     
    }
     else
        printf(" error\n");

    threads = malloc(sizeof(pthread_t) * arg->n_philo);
    philo = malloc(sizeof(t_phil *) * arg->n_philo);
    creat_philos(threads, philo, arg);
  //  philo.shared->start = ft_getime(0);
    // philo.shared.n = ft_atoi(av[1]);
    // philo.shared.philoserfers = malloc(philo.shared.n * sizeof(pthread_t));
    //odd_philo(&philo);
    //pintf(" nbr of philoserfer %d \n",philo.n_of_phil);
    //create_thread(philo, id_philo);
}