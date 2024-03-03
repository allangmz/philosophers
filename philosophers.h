/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aguemazi <aguemazi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/20 13:49:31 by aguemazi          #+#    #+#             */
/*   Updated: 2022/11/02 13:40:13 by aguemazi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <sys/time.h>
# include <stdarg.h>

typedef struct s_philosopher
{
	int						number;
	int						*finished_eating;
	int						number_of_philosophers;
	long long int			time_to_die;
	long long int			time_last_eat;
	long long int			time_to_eat;
	long long int			time_to_sleep;
	int						number_of_times_each_philosopher_must_eat;
	pthread_t				thread_philospher;
	pthread_mutex_t			mutex_fork;
	pthread_mutex_t			*mutex_print;
	struct s_philosopher	*left_philosopher;
	long long int			begin_time;
	int						stop;
}	t_philosopher;

long long int	get_time(void);
void			*threadfunction(t_philosopher *philosopher);
int				routine_philospher(t_philosopher *philosopher);
int				eat(t_philosopher *philosopher);
int				ft_atoi(const char *str);
int				gestion_life(t_philosopher *tab_philo,
					int *finished_eating, int number_of_philosophers);
t_philosopher	*init(int argc, char **argv, int *finished_eating,
					int *number_of_philosophers);
t_philosopher	*init_tab_philo(int argc, char **argv,
					t_philosopher *tab_philo, int *finished_eating);
void			ft_free(t_philosopher *tab_philo);
void			ft_usleep(long int time);		
int				ft_printf(const char *str, ...);
void			ft_putchar_fd(char c, int fd);
char			*ft_itoa(int n);
size_t			ft_strlen(const char *s);
void			ft_putstr_fd(const char *s, int fd);
int				ft_putnbr_fd(int n, int fd);
void			ft_bzero(void *s, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);

#endif
