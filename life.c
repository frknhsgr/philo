/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   life.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:56:41 by fhosgor           #+#    #+#             */
/*   Updated: 2024/07/11 16:27:06 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_timer(long long finish, t_philosopher *philo)
{
	long long	start;

	start = get_current_time();
	while ((get_current_time() - start) < finish)
	{
		if (investigation(philo))
			return (1);
		usleep (500);
	}
	return (0);
}

void	sleeping(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->p->forks[philo->front_fork]);
	pthread_mutex_unlock(&philo->p->forks[philo->right_fork]);
	if (investigation(philo))
		return ;
	status_information(philo, "is sleeping.");
	ft_timer(philo->p->sleeping_time, philo);
	if (investigation(philo))
		return ;
	status_information(philo, "is thinking.");
}

void	eating(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->p->forks[philo->front_fork]);
	pthread_mutex_lock(&philo->p->forks[philo->right_fork]);
	status_information(philo, "has taken a fork.");
	status_information(philo, "has taken a fork.");
	status_information(philo, "is eating.");
	pthread_mutex_lock(&philo->p->exit);
	philo->last_meal_t = get_current_time();
	pthread_mutex_unlock(&philo->p->exit);
	ft_timer(philo->p->eating_time, philo);
	pthread_mutex_lock(&philo->p->exit);
	philo->meal_count += 1;
	pthread_mutex_unlock(&philo->p->exit);
}

void	*philo_life(void *p)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)p;
	if (philo->p->philo_count == 1)
	{
		pthread_mutex_lock(&philo->p->forks[0]);
		status_information(philo, "has taken a fork.");
		while (!investigation(philo))
		{
		}
		pthread_mutex_unlock(&philo->p->forks[0]);
	}
	else
	{
		while (1)
		{
			if (investigation(philo))
				break ;
			eating(philo);
			sleeping(philo);
		}
	}
	return (NULL);
}
