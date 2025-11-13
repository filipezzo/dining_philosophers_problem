/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 14:01:51 by fsousa            #+#    #+#             */
/*   Updated: 2025/11/13 17:50:30 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <stdlib.h>
#include <limits.h>

typedef pthread_mutex_t t_mtx;

typedef enum s_state
{
	CREATE,
	INIT,
	LOCK,
	UNLOCK,
	DESTROY,
}	t_state;

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
void *safe_malloc(size_t bytes);
void safe_mutex_state(t_mtx *mutex, t_state state);
