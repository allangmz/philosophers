/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:36:55 by aguemazi          #+#    #+#             */
/*   Updated: 2022/11/02 13:40:46 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_usleep(long int time)
{
	struct timeval	timeval;
	long int		start_time;

	gettimeofday(&timeval, NULL);
	start_time = timeval.tv_sec * 1000000 + timeval.tv_usec;
	usleep(time * 0.80);
	gettimeofday(&timeval, NULL);
	while (time > (timeval.tv_sec * 1000000 + timeval.tv_usec) - start_time)
	{
		gettimeofday(&timeval, NULL);
	}
	return ;
}
