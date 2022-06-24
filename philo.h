#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_shared
{
    long long start;
    
}   t_shared;

typedef struct s_phil
{
    int id;
    int n_philo;
    int t_die;
    int t_sleep;
    int t_eat;
    int n_t_eat;
    long long start;
    long long last_eat;
    int left;
    int right;
    pthread_mutex_t *forks;
    pthread_mutex_t *message;
    t_shared data;
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
