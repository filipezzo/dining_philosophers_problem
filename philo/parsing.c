/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsousa <fsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 13:32:18 by fsousa            #+#    #+#             */
/*   Updated: 2025/11/13 13:57:52 by fsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int is_space(char c)
{
    return ((c >= 9 && c <= 13) || c == 32);
}

static int is_digit(char c)
{
    return (c >= '0' && c <= '9');
}

static const char *valid_input(const char *str)
{
    int len;
    int i;
    const char *value; 

    len = 0;
    i = 0;
    while (is_space(str[i]))
        i++;
    if (str[i] == '-' || str[i] == '+')
    {
        if (str[i] == '-')
            exit_error("The value cannot be negative");
        i++;
    }
    if (!is_digit(str[i]))
        exit_error("The input is not a correct digit");
    value = &str[i];
    while (is_digit(str[i]))
    {
        len++;
        i++;
    }
    if (len > 10)
        exit_error("The value is too big");
    return (value);
}
static long ft_atol(char *str)
{
    long long value;
    int i;
    const char *digit_start;

    value = 0;
    i = 0;
    digit_start = valid_input(str);
    while (is_digit(digit_start[i]))
    {
        value = (value * 10) + (digit_start[i] - '0');
        i++;
    }
    if (value > INT_MAX)
        exit_error("The value is too big");
    return ((long)value);
}

void parse_input(t_data *data, char **av)
{
    data->number_of_philos = ft_atol(av[1]);
    if (data->number_of_philos == 0)
        exit_error("Must have at least one philosopher");
    data->time_to_die = ft_atol(av[2]) * 1e3;
    if (data->time_to_die == 0)
        exit_error("Time to die cannot be 0");
    data->time_to_eat = ft_atol(av[3]) * 1e3;
    if (data->time_to_eat == 0)
        exit_error("Time to eat cannot be 0");
    data->time_to_sleep = ft_atol(av[4]) * 1e3;
    if (data->time_to_sleep == 0)
        exit_error("Time to sleep cannot be 0");
    if (data->time_to_die < 6e4 || data->time_to_eat < 6e4 || data->time_to_sleep < 6e4)
        exit_error("Timestamp must be grather than 60ms");
    if (av[5])
    {
        data->limit_of_meals = ft_atol(av[5]);
        if (data->limit_of_meals == 0)
            exit_error("Limit os meals cannot be 0");
    }
    else
        data->limit_of_meals = -1;
}