/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 14:49:15 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/07/01 11:29:59 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_check_arguments(int argc, char **argv)
{
	int	i;

	if (argc > 6 || argc < 5)
		return (1);
	i = 0;
	while (++i < argc)
		if (ft_atoi(argv[i]) <= 0)
			return (1);
	return (0);
}

void	ft_create_mutex_forks(t_data *data, int num)
{
	int	i;

	data->mutex_forks = malloc(num * sizeof(pthread_mutex_t));
	i = 1;
	while (i <= num)
	{
		pthread_mutex_init(&data->mutex_forks[i], 0);
		i++;
	}
}

int	ft_init_data(t_data **data, int argc, char **argv)
{
	if (ft_check_arguments(argc, argv))
		return (1);
	*data = malloc(sizeof(t_data));
	(*data)->quantity = ft_atoi(argv[1]);
	(*data)->time_to_die = ft_atoi(argv[2]);
	(*data)->time_to_eat = ft_atoi(argv[3]);
	(*data)->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		(*data)->optional_arg = ft_atoi(argv[5]);
	else
		(*data)->optional_arg = 0;
	pthread_mutex_init(&((*data)->mutex_stdout), 0);
	ft_create_mutex_forks(*data, (*data)->quantity);
	return (0);
}

void	ft_init_philo(t_philo	*philos, t_data *data, int num)
{
	int	i;

	i = 1;
	while (i <= num)
	{
		if (i == 1)
			philos[i].left_fork = num;
		else
			philos[i].left_fork = i - 1;
		philos[i].right_fork = i + 1;
		philos[i].num = i;
		philos[i].data = data;
		i++;
	}
}
