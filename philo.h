#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>

typedef pthread_mutex_t t_mtx;

typedef struct s_fork
{
    int id;
    t_mtx fork;
} t_fork;

typedef struct s_philo
{
    int id;
    long meals_count;
    long last_meal_time;
    int is_philo_full;
    t_fork *left_fork;
    t_fork *right_fork;
    pthread_t philo_id;
} t_philo;

typedef struct s_data
{
    long number_of_philos;
    long limit_of_meals;
    long time_to_die;
    long time_to_eat;
    long time_to_sleep;
    long time_start;
    long time_end;
    t_fork *forks;
    t_philo *philos;
} t_data;

void exit_error(const char *message);
void parse_input(t_data *data, char **av);