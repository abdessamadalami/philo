#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_shared
{
    int time_to_die;
    int n;
    int start;
    pthread_t *philoserfers;
    pthread_mutex_t *forks;
    
}   t_shared;

typedef struct s_phil
{
    int id;
    int n_philo;
    int t_die;
    int t_sleep;
    int t_eat;
    int n_t_eat;
    int start;
    pthread_mutex_t *forks;
}	t_phil;

typedef struct arg
{
    int n_philo;
    int t_die;
    int t_sleep;
    int t_eat;
    int n_t_eat;
}   t_par;

int	ft_isdigit(int c);
size_t	ft_strlen(const char *str);
int	check_argv(char *argv);
t_par *check(int ac, char **av);
int	ft_atoi(const char *nbr);
