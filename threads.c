/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:57:00 by fhosgor           #+#    #+#             */
/*   Updated: 2024/07/11 16:26:05 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	thread_creater(t_program *p)
{
	int	i;

	i = 0;
	p->start_time = get_current_time();
	while (i < p->philo_count)
	{
		pthread_create(&p->threads[i], NULL, &philo_life, &p->philosophers[i]);
		i++;
		usleep (100);
	}
	while (1)
	{
		if (investigation(p->philosophers))
			break ;
	}
	i = 0;
	while (i < p->philo_count)
	{
		pthread_join(p->threads[i], NULL);
		i++;
	}
	return (0);
}
