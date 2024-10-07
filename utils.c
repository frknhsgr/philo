/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:56:20 by fhosgor           #+#    #+#             */
/*   Updated: 2024/10/07 16:25:47 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	num;

	i = 0;
	sign = 1;
	num = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num *= 10;
		num += str[i] - '0';
		i++;
	}
	if (str[i])
		return (0);
	return (num * sign);
}

int	argument_checker(char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		if (ft_atoi(av[i]) <= 0)
		{
			printf("%d. argument is worng!", i);
			return (0);
		}
		i++;
	}
	return (1);
}

long long	get_current_time(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	status_information(t_philosopher *philo, char *str)
{
	pthread_mutex_lock(&philo->p->exit);
	if (!philo->p->dead_philo_c && !philo->p->max_food)
		printf("%lld\t%i %s\n", get_current_time() - philo->p->start_time, \
		philo->id + 1, str);
	if (!ft_strcmp(str, "died."))
		philo->p->dead_philo_c += 1;
	pthread_mutex_unlock(&philo->p->exit);
}
