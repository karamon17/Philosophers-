/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkhaishb <gkhaishb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 12:29:02 by gkhaishb          #+#    #+#             */
/*   Updated: 2023/07/05 14:13:16 by gkhaishb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (ft_init_data(&data, argc, argv))
		return (write(2, "Error in arguments\n", 19));
	ft_run(&data);
	free(data.philo);
	return (0);
}
