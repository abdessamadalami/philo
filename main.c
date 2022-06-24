/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:16:57 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/24 15:43:01 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


long long get_time(long long int curnt)
{
    struct timeval current;

    gettimeofday(&current, NULL);
    long long tiem = current.tv_sec * 1000 + current.tv_usec / 1000;
    return (tiem - curnt);
}

void ft_usleep(long time)
{
    long sleep;

    sleep = get_time(0);
    while (get_time(0) - sleep < time)
        usleep(50);
}

void  print_mess(int fork, char l, t_phil *philo)
{
    if (l == 'l')
    {
        // usleep(5000);
        // printf("get time %lld ", get_time(0) - philo->data.start);
        // exit(1);
        pthread_mutex_lock(philo->message);
        printf("%lld ms philo %d has taken left fork \n",get_time(0) - philo->start ,philo->id);
        pthread_mutex_unlock(philo->message);
    }
    if (l == 'r')
    {
    pthread_mutex_lock(philo->message);
        printf("%lld ms philo %d has taken right fork \n",get_time(0) - philo->start ,philo->id );
    pthread_mutex_unlock(philo->message);
    }
    if (l == 'e')
    {
        pthread_mutex_lock(philo->message);
         printf("%lld ms philo %d eating\n",get_time(0) - philo->start, philo->id);
        pthread_mutex_unlock(philo->message);
    }
    if (l == 's')
    {
        pthread_mutex_lock(philo->message);
        printf("%lld ms philo %d sleeping\n",get_time(0) - philo->start, philo->id);
        pthread_mutex_unlock(philo->message);
    }
     if (l == 'd')
    {
       pthread_mutex_lock(philo->message);
        printf("%lld ms philo %d died\n",get_time(0) - philo->start, philo->id);
    pthread_mutex_unlock(philo->message);
    }
      if (l == 't')
    {
       pthread_mutex_lock(philo->message);
        printf("%lld ms philo %d thinking\n",get_time(0) - philo->start, philo->id);
        pthread_mutex_unlock(philo->message);
    }
    
}

void ft_forks(t_phil *philo)
{
    // int left;
    // int right;
    int last_meal;

    // left = philo->id;
    // right =(philo->id + 1) % philo->n_philo;
   
    pthread_mutex_lock(&philo->forks[philo->left]);
    print_mess(philo->left,'l', philo);
    pthread_mutex_lock(&philo->forks[philo->right]);
    print_mess(philo->right,'r', philo);
    print_mess(12, 'e', philo);
    philo->last_eat = get_time(0);
     //ft_usleep(philo -> t_eat * 1000);
    usleep(200 * 1000);
    pthread_mutex_unlock(&philo->forks[philo->right]);
    pthread_mutex_unlock(&philo->forks[philo->left]);
    print_mess(12, 's', philo);
     usleep(200 * 1000);
    //ft_usleep(philo -> t_sleep * 1000);
    // print_mess(12, 't', philo);
   // printf("philo %d  left fork %d \n", philo->id, left);
   // printf("%lld %d\n", ft_getime(philo->start),philo->id);
}

 pthread_mutex_t *ft_muetx(int n_philo)
{
    int i;
    pthread_mutex_t *vsr;

    i = 0;
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
    while (1)
    {
        ft_forks(philo);
        //ft_usleep(50 * 1000);
    }
   // printf("the id of %d in routing function \n", philo->id);
    return (NULL);
}

void odds_philo(pthread_t *threads, t_phil **philo)
{
    int index;
    
    index = 0;
    while (index < philo[0]->n_philo)
    //    philo[index] 
    {
       pthread_create(&threads[index], NULL, rotin, (void *)philo[index]);
       index+=2;
    }
    //usleep(200);
}

void eveen_philo(pthread_t *threads, t_phil **philo)
{
    int index;
    
    index = 1;
   // printf("%d  n philo. \n",philo[1]->n_philo );
    while (index < philo[0]->n_philo)
    {
       pthread_create(&threads[index], NULL, rotin, (void *)philo[index]);
       index +=2;
    }
}

 void creat_philos(pthread_t *threads, t_phil **philo, t_par *arg)
 {
    int index;
    pthread_mutex_t *forks;
    pthread_mutex_t *message;
    
    int i;

    i = 0;
    forks = ft_muetx(arg->n_philo);
    message = malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(message,0);
    long long start = get_time(0);
    while (i < arg->n_philo)
    {
        philo[i] = malloc(sizeof(t_phil));
        philo[i]->n_philo = arg -> n_philo;
        philo[i]->id = i + 1;
        philo[i]->t_die = arg-> t_die;
        philo[i]->t_eat = arg-> t_eat;
        philo[i]->t_sleep = arg-> t_sleep;
        philo[i]->n_t_eat = arg-> n_t_eat;
        philo[i]->start = start;
        philo[i]->forks = forks;
        philo[i]->message = message;
        philo[i]->last_eat = get_time(0);
        philo[i]->left = i;
        philo[i]->right = (i + 1) % arg->n_philo;
        i++;   
    }
    //printf(" this is the t_die of philoserfer %d = %d \n", philo[0]->id, philo[0]->t_die);
    odds_philo(threads, philo);
    usleep(500);
    eveen_philo(threads, philo);
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
    philo = malloc(sizeof(t_phil) * arg->n_philo);
    creat_philos(threads, philo, arg);
    while (1)
    {
        index = 0;
        while (philo[index] && index < arg->n_philo )
        {
            if (get_time(0) - philo[index]->last_eat > philo[index]->t_die)
            {
                printf("%lld ms philo %d died\n",get_time(0) - philo[index]->start, philo[index]->id);
                return (0);
            }
            index++;
        }
    }
  //  philo.shared->start = ft_getime(0);
    // philo.shared.n = ft_atoi(av[1]);
    // philo.shared.philoserfers = malloc(philo.shared.n * sizeof(pthread_t));
    //odd_philo(&philo);
    //pintf(" nbr of philoserfer %d \n",philo.n_of_phil);
    //create_thread(philo, id_philo);
}