#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
#include <signal.h>
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
    int *pid;
    long long start;
    long long last_eat;
    int n_of_t;
    sem_t *forks;
    sem_t *message;
}	t_phil;

typedef struct arg
{
    int n_philo;
    int t_die;
    int t_sleep;
    int t_eat;
    int n_t_eat;
}   t_par;

int     ft_isdigit(int c);
size_t  ft_strlen(const char *str);
int         check_argv(char *argv);
t_par       *check(int ac, char **av);
int         ft_atoi(const char *nbr);
void        creat_philos(pthread_t *threads, t_phil **philo, t_par *arg);
void        ft_forks(t_phil *philo);
void        *rotin(t_phil   *ptr);
int         check_n(t_phil **philo , int n_p, int n_eat);
void        eveen_philo(pthread_t *threads, t_phil **philo);
void        odds_philo(pthread_t *threads, t_phil **philo);
void        ft_usleep(long time);
long long   get_time(void);
pthread_mutex_t *ft_muetx(int n_philo);
void  print_mess( char *l, t_phil *philo);
 void  *check_die(void *ptr);