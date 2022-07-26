/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:48:00 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/21 19:02:17 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_argv(char *argv)
{
	int	index;

	index = 0;
	while (argv[index] != '\0')
	{
		if (!ft_isdigit(argv[index]))
			return (0);
		index++;
	}
	return (1);
}

size_t	ft_strlen(const char *str)
{
	int		i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

static void	ff(int index, t_par *parm, char *str)
{
	if (index == 1)
		parm->n_philo = ft_atoi(str);
	if (index == 2)
		parm->t_die = ft_atoi(str);
	if (index == 4)
		parm->t_sleep = ft_atoi(str);
	if (index == 3)
		parm->t_eat = ft_atoi(str);
	if (index == 5)
		parm->n_t_eat = ft_atoi(str);
}

t_par	*check(int ac, char **av)
{
	int		index;
	t_par	*parm;

	index = 1;
	parm = malloc(sizeof(t_par));
	if (parm == NULL)
		return (NULL);
	parm -> n_t_eat = -1;
	while (index < ac)
	{
		if (av[index] != NULL && ft_strlen(av[index]) != 0
			&& check_argv(av[index]))
			ff(index, parm, av[index]);
		else
			return (0);
		index++;
	}
	return (parm);
}
