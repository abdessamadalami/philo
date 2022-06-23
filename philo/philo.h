#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct s_shared
{
    int time_life;
    int n;
    int start;
    pthread_t *philoserfers;
    pthread_mutex_t *forks;
    
}   t_shared;

typedef struct s_phil
{
    int id;
    int last_to_eat;
    int last_to_sleep;
    t_shared shared;
}	t_phil;

