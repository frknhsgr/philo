/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initializing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 16:37:53 by fhosgor           #+#    #+#             */
/*   Updated: 2024/07/09 16:04:34 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_init_mutex(t_program *p)
{
	int	i;

	i = 0;
	pthread_mutex_init(&p->exit, NULL);
	while (i < p->philo_count)
	{
		pthread_mutex_init(&p->forks[i], NULL);
		i++;
	}
}

t_philosopher	ft_set_philo_p(t_program *x)
{
	t_philosopher	philo;

	philo.p = x;
	return (philo);
}

void	philo_regulater(int ac, char **av, t_program *p)
{
	int	i;

	p->dying_time = ft_atoi(av[2]);
	p->eating_time = ft_atoi(av[3]);
	p->sleeping_time = ft_atoi(av[4]);
	if (ac == 6)
		p->needed_meal_c = ft_atoi(av[5]);
	else
		p->needed_meal_c = -1;
	i = 0;
	while (i < p->philo_count)
	{
		p->philosophers[i] = ft_set_philo_p(p);
		p->philosophers[i].id = i;
		p->philosophers[i].meal_count = 0;
		p->philosophers[i].last_meal_t = get_current_time();
		p->philosophers[i].front_fork = i;
		p->philosophers[i].right_fork = (i + 1) % p->philo_count;
		i++;
	}
}

t_program	*ft_init(int ac, char **av)
{
	t_program	*p;

	if (ft_atoi(av[1]) > 200)
	{
		printf("Invalid philosopher count!\n");
		exit(1);
	}
	p = (t_program *)malloc(sizeof(t_program));
	if (!p)
		return (NULL);
	p->philo_count = ft_atoi(av[1]);
	p->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * \
		p->philo_count);
	if (!p->philosophers)
		return (NULL);
	philo_regulater(ac, av, p);
	p->threads = malloc(sizeof(pthread_t) * p->philo_count);
	if (!p->threads)
		return (NULL);
	p->forks = malloc(sizeof(pthread_mutex_t) * p->philo_count);
	if (!p->forks)
		return (NULL);
	return (p);
}
