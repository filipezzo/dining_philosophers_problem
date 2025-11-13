/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:48:34 by fsousa            #+#    #+#             */
/*   Updated: 2025/11/13 17:50:23 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void *safe_malloc(size_t bytes)
{
	void *data;
	
	data = malloc(bytes);
	if(!data)
		exit_error("Error with malloc");
	return data;
}

static void handle_mutex_error(int status)
{
	if (status == 0)
		return ;
	exit_error("Error handling with mutex");
}

void safe_mutex_state(t_mtx *mutex, t_state state)
{
	if(state == INIT)
		handle_mutex_error(pthread_mutex_init(mutex, NULL));
	if(state == LOCK)
		handle_mutex_error(pthread_mutex_lock(mutex));
	else if (state == UNLOCK)
		handle_mutex_error(pthread_mutex_unlock(mutex));
	else if (state == DESTROY)
		handle_mutex_error(pthread_mutex_destroy(mutex));
	else
		exit_error("Wrong state for mutex");
}