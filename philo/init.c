/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:55:47 by fsousa            #+#    #+#             */
/*   Updated: 2025/11/13 18:30:09 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


static philo_int(t_data *data)
{
	int i;
	t_philo *philo;

	i = 0;
	while(i < data->number_of_philos)
	{
		philo = data->philos + i;
		philo->id = i + 1;
		philo->is_philo_full = 0;
		philo->last_meal_time = 0;
		philo->meals_count = 0;
		i++;
	}
	assign_philos_forks(philo); //todo
}

void data_init(t_data *data)
{
	int i;

	i = 0;
	data->time_end = 0;
	data->philos = safe_malloc(sizeof(t_philo)* data->number_of_philos);
	data->forks = safe_malloc(sizeof(t_fork) * data->number_of_philos);
	while(i < data->number_of_philos)
	{
		safe_mutex_state(&data->forks[i].fork, INIT);
		data->forks[i].id = i;
		i++;
	}
}