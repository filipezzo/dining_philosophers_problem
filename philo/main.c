#include "philo.h"

int main(int ac, char **av)
{
    t_data data;
    //./philo 5 800 200 200 [5]
    if (ac == 5 || ac == 6)
    {
        parse_input(&data, av);
        data_init(&data);
        start_dinner(&data);
        clean(&data);
    }
    else
        exit_error("Your program must have 5 or 6 arguments.");
    return (0);
}