/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 08:16:57 by ael-oual          #+#    #+#             */
/*   Updated: 2022/06/22 09:29:54 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <pthread.h>

typedef struct s_phil
{
    int n_of_phil;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
}	t_phil;

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

void    *thread_function(void   *ptr)
{
    int id = (int *)ptr;
    printf(" the id of this thread is  %d \n",id);
    return (void *)ptr;
}

void create_thread(t_phil philo, int *id_philo)
{
    pthread_t   thread;
    void        *return_status;
    int index = 0;
    
    while (philo.n_of_phil)
    {
        printf("index %d \n", index);
       pthread_create(&thread, NULL, &thread_function, id_philo[index]);
       index++;
    }
    
    
    // Error Handling
    pthread_join(thread, &return_status);
    printf("Thread returned %d\n", (int)return_status);
    
}

int main(int ac, char *av[])
{
    
    t_phil philo;
    int *id_philo;
    int index;
    index = 0;
    if (av[1] == NULL)
    {
        printf("error");
        return 0;
    }
    philo.n_of_phil =  ft_atoi(av[1]);
    id_philo = malloc(philo.n_of_phil * 4);
    while (index < philo.n_of_phil)
    {
        id_philo[index] = index + 1;
        index++;
    }
    printf(" nbr of philoserfer %d\n",philo.n_of_phil);
    create_thread(philo, id_philo);
 
}