/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:36:49 by aguemazi          #+#    #+#             */
/*   Updated: 2022/11/02 13:41:17 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosophers.h>

int	main(int argc, char **argv)
{
	int				finished_eating;
	int				number_of_philosophers;
	t_philosopher	*tab_philo;

	tab_philo = init(argc, argv, &finished_eating, &number_of_philosophers);
	if (tab_philo == NULL)
		return (-2);
	gestion_life(tab_philo, &finished_eating, number_of_philosophers);
	ft_usleep(100);
	printf("done.\n");
	return (0);
}
