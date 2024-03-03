/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_function.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:48:46 by aguemazi          #+#    #+#             */
/*   Updated: 2022/11/02 13:41:32 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_philosopher	init_struct_philo(char **argv, int number
	, int *finished_eating, long long int begin)
{
	t_philosopher	philosopher;

	philosopher.number = number;
	philosopher.number_of_philosophers = ft_atoi(argv[1]);
	philosopher.time_to_die = ft_atoi(argv[2]);
	philosopher.time_last_eat = begin;
	philosopher.time_to_eat = ft_atoi(argv[3]) * 1000;
	philosopher.time_to_sleep = ft_atoi(argv[4]) * 1000;
	philosopher.finished_eating = finished_eating;
	philosopher.begin_time = begin;
	philosopher.stop = 0;
	return (philosopher);
}

t_philosopher	*init_tab_philo(int argc, char **argv
	, t_philosopher *tab_philo, int *finished_eating)
{
	struct timeval	timeval;
	int				i;
	long long int	begin;

	gettimeofday(&timeval, NULL);
	i = 0;
	begin = get_time();
	while (i < ft_atoi(argv[1]))
	{
		tab_philo[i] = init_struct_philo(argv, i, finished_eating, begin);
		if (argc == 6)
			tab_philo[i].number_of_times_each_philosopher_must_eat
				= ft_atoi(argv[5]);
		if (i == 0)
			tab_philo[i].left_philosopher = &tab_philo[ft_atoi(argv[1]) - 1];
		else
			tab_philo[i].left_philosopher = &tab_philo[i - 1];
		pthread_mutex_init(&tab_philo[i].mutex_fork, NULL);
		if (pthread_create(&tab_philo[i].thread_philospher, NULL
				, (void *)threadfunction, &tab_philo[i]) == -1)
			return (NULL);
		i++;
	}
	return (tab_philo);
}

int	gestion_life(t_philosopher *tab_philo, int *finished_eating
	, int number_of_philosophers)
{
	struct timeval	timeval;
	int				i;

	while (*finished_eating < number_of_philosophers)
	{
		if (i >= number_of_philosophers)
			i = 0;
		gettimeofday(&timeval, NULL);
		if ((timeval.tv_sec * 1000 + timeval.tv_usec / 1000
				- tab_philo[i].time_last_eat) > 0
			&& ((timeval.tv_sec * 1000 + timeval.tv_usec / 1000)
				- tab_philo[i].time_last_eat)
			> tab_philo[i].time_to_die && tab_philo[i].stop == 0)
		{
			printf("%lld %d die\n", timeval.tv_sec * 1000 + timeval.tv_usec
				/ 1000 - tab_philo[i].begin_time, tab_philo[i].number);
			return (0);
		}
		i++;
	}
	return (0);
}

void	add_mutex_print(t_philosopher *tab_philo, pthread_mutex_t *mutex_print,
					int number_of_philosophers)
{
	int	i;

	i = 0;
	usleep(10);
	while (i < number_of_philosophers)
	{
		tab_philo[i].mutex_print = mutex_print;
		i++;
	}
	return ;
}

t_philosopher	*init(int argc, char **argv, int *finished_eating,
	int *number_of_philosophers)
{
	t_philosopher	*tab_philo;
	pthread_mutex_t	mutex_print;

	if (!(argc == 5 || argc == 6))
	{
		printf("error : argument\n");
		return (NULL);
	}
	pthread_mutex_init(&mutex_print, NULL);
	*number_of_philosophers = ft_atoi(argv[1]);
	tab_philo = malloc(sizeof(t_philosopher) * *number_of_philosophers);
	if (tab_philo == NULL)
	{
		printf("error : malloc tab_philo\n");
		return (NULL);
	}
	add_mutex_print(tab_philo, &mutex_print, *number_of_philosophers);
	*finished_eating = 0;
	tab_philo = init_tab_philo(argc, argv, tab_philo, finished_eating);
	if (tab_philo == NULL)
	{
		printf("error : thread not create\n");
		return (NULL);
	}
	return (tab_philo);
}
