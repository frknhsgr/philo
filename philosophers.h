/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:37:49 by fhosgor           #+#    #+#             */
/*   Updated: 2024/07/10 15:37:04 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philosopher
{
	int					id;
	int					meal_count;
	int					right_fork;
	int					front_fork;
	long long			last_meal_t;
	struct s_program	*p;
}	t_philosopher;

typedef struct s_program
{
	pthread_t		*threads;
	pthread_t		investigator;
	pthread_mutex_t	*forks;
	pthread_mutex_t	eating;
	pthread_mutex_t	exit;
	t_philosopher	*philosophers;
	int				philo_count;
	int				eating_time;
	int				sleeping_time;
	int				dying_time;
	int				dead_philo_c;
	int				max_food;
	int				needed_meal_c;
	long long		start_time;
}	t_program;

int				ft_strcmp(char *s1, char *s2);
int				ft_atoi(char *str);
void			argument_checker(char **av);
long long		get_current_time(void);
int				ft_timer(long long finish, t_philosopher *philo);
void			ft_init_mutex(t_program *p);
void			philo_regulater(int ac, char **av, t_program *p);
t_program		*ft_init(int ac, char **av);
t_philosopher	ft_set_philo_p(t_program *x);
int				thread_creater(t_program *p);
int				investigation(t_philosopher *philo);
void			status_information(t_philosopher *philo, char *str);
void			eating(t_philosopher *philo);
void			sleeping(t_philosopher *philo);
void			*philo_life(void *p);
int				ft_close(t_program *p);

#endif