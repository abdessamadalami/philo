/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 10:55:17 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/21 11:54:10 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <string.h>
# include <pthread.h>
# include <unistd.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>           /* For O_* constants */
# include <sys/stat.h>        /* For mode constants */
# include <semaphore.h>
# include <signal.h>

typedef struct s_phil
{
	long long	start;
	long long	last_eat;
	int			n_of_t;
	sem_t		*forks;
	sem_t		*message;
	int			id;
	int			n_philo;
	int			t_die;
	int			t_sleep;
	int			t_eat;
	int			n_t_eat;
	int			*pid;
}		t_phil;

typedef struct arg
{
	int	n_philo;
	int	t_die;
	int	t_sleep;
	int	t_eat;
	int	n_t_eat;
}		t_par;

long long	get_time(void);
void		whait_pro(int *ptr, int n);
void		kill_process(int *ptr, int n);
int			ft_isdigit(int c);
size_t		ft_strlen(const char *str);
int			check_argv(char *argv);
t_par		*check(int ac, char **av, int index);
int			ft_atoi(const char *nbr);
void		ft_forks(t_phil *philo);
int			rotin(t_phil *ptr);
int			check_n(t_phil **philo, int n_p, int n_eat);
void		eveen_philo(pthread_t *threads, t_phil **philo);
void		odds_philo(pthread_t *threads, t_phil **philo);
void		ft_usleep(long time);
void		print_mess( char *l, t_phil *philo);
void		*check_die(void *ptr);
void		creat_philos(t_phil **philo, t_par *arg);
#endif