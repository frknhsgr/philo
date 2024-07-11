/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:36:13 by fhosgor           #+#    #+#             */
/*   Updated: 2024/07/11 16:21:06 by fhosgor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_program	*p;

	if (ac < 5 || ac > 6)
	{
		printf("Wrong Argument Count!");
		return (0);
	}
	argument_checker(av);
	p = ft_init(ac, av);
	if (!p)
		return (0);
	ft_init_mutex(p);
	if (thread_creater(p))
		return (ft_close(p));
	ft_close(p);
}
