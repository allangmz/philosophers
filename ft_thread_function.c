/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 12:20:27 by aguemazi          #+#    #+#             */
/*   Updated: 2022/11/02 13:36:17 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_printf_mutex(char *message, t_philosopher *philosopher, int time)
{
	char	*buffer;
	char	*number;

	pthread_mutex_lock(philosopher->mutex_print);
	buffer = ft_strjoin("", "");
	number = ft_itoa(time);
	usleep(5);
	buffer = ft_strjoin(number, " ");
	number = ft_itoa(philosopher->number);
	buffer = ft_strjoin(buffer, number);
	buffer = ft_strjoin(buffer, " ");
	buffer = ft_strjoin(buffer, message);
	write(1, buffer, ft_strlen(buffer));
	free(buffer);
	pthread_mutex_unlock(philosopher->mutex_print);
	return ;
}

int	eat(t_philosopher *philosopher)
{
	if (!pthread_mutex_lock(&philosopher->mutex_fork))
	{
		ft_printf_mutex("has taken a fork right\n", philosopher, get_time()
			- philosopher->begin_time);
		pthread_mutex_lock(&philosopher->left_philosopher->mutex_fork);
		ft_printf_mutex("has taken a fork left\n", philosopher, get_time()
			- philosopher->begin_time);
		usleep(5);
		ft_printf_mutex("is eating\n", philosopher, get_time()
			- philosopher->begin_time);
		ft_usleep(philosopher->time_to_eat);
		pthread_mutex_unlock(&philosopher->mutex_fork);
		pthread_mutex_unlock(&philosopher->left_philosopher->mutex_fork);
		usleep(5);
		philosopher->time_last_eat = get_time();
	}
	return (0);
}

int	routine_philospher(t_philosopher *philosopher)
{
	int				eat_counter;
	struct timeval	timeval;

	eat_counter = 0;
	gettimeofday(&timeval, NULL);
	philosopher->time_last_eat = get_time();
	while (eat(philosopher) != 2)
	{
		eat_counter ++;
		if (philosopher->number_of_times_each_philosopher_must_eat
			== eat_counter)
			break ;
		ft_printf_mutex("is sleeping\n", philosopher, (get_time()
				- philosopher->begin_time));
		ft_usleep(philosopher->time_to_sleep);
		ft_printf_mutex("is thinking\n", philosopher, (get_time()
				- philosopher->begin_time));
	}
	philosopher->stop = 1;
	(*philosopher->finished_eating)++;
	pthread_mutex_destroy(&philosopher->mutex_fork);
	return (0);
}

void	*threadfunction(t_philosopher *philosopher)
{
	if (philosopher->number % 2 == 0)
	{
		ft_usleep(150);
	}
	routine_philospher(philosopher);
	return (NULL);
}
