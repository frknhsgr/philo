/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:56:30 by fhosgor           #+#    #+#             */
/*   Updated: 2024/10/07 16:27:19 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	investigation(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->p->exit);
	if (philo->meal_count == philo->p->needed_meal_c)
	{
		pthread_mutex_unlock(&philo->p->exit);
		return (1);
	}
	pthread_mutex_unlock(&philo->p->exit);
	pthread_mutex_lock(&philo->p->exit);
	if (philo->p->dead_philo_c)
	{
		pthread_mutex_unlock(&philo->p->exit);
		return (1);
	}
	pthread_mutex_unlock(&philo->p->exit);
	pthread_mutex_lock(&philo->p->exit);
	if ((get_current_time() - philo->last_meal_t) > philo->p->dying_time)
	{
		pthread_mutex_unlock(&philo->p->exit);
		status_information(philo, "died.");
		return (1);
	}
	pthread_mutex_unlock(&philo->p->exit);
	return (0);
}

int	ft_close(t_program *p)
{
	int	i;

	i = 0;
	while (i < p->philo_count)
	{
		pthread_mutex_destroy(&p->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&p->exit);
	free(p->threads);
	free(p->forks);
	free(p->philosophers);
	free(p);
	return (1);
}
