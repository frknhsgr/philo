/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhosgor <fhosgor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 13:36:13 by fhosgor           #+#    #+#             */
/*   Updated: 2024/10/07 16:24:30 by fhosgor          ###   ########.fr       */
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
	if (!argument_checker(av))
		return (0);
	p = ft_init(ac, av);
	if (!p)
		return (0);
	ft_init_mutex(p);
	if (thread_creater(p))
		return (ft_close(p));
	ft_close(p);
}
