/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 15:48:00 by ael-oual          #+#    #+#             */
/*   Updated: 2022/07/15 22:20:59 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	index_fun(const char *nbr, int *s)
{
	int	i;

	i = 0;
	while (nbr[i] == ' ' || nbr[i] == '\t' || nbr[i] == '\v'
		|| nbr[i] == '\n' || nbr[i] == '\f' || nbr[i] == '\r')
		i++;
	if (nbr[i] == '+' || nbr[i] == '-' )
	{
		if (nbr[i] == '-')
			(*s) *= -1;
		i++;
	}
	return (i);
}

int	ft_atoi(const char *nbr)
{
	int	i;
	int	nb;
	int	s;

	nb = 0;
	s = 1;
	i = index_fun(nbr, &s);
	while (nbr[i] >= '0' && nbr[i] <= '9' )
	{			
		nb = nb * 10 + nbr[i] - '0';
		i++;
	}
	return (nb * s);
}

int	ft_isdigit(int c)
{
	if (c <= '9' && c >= '0')
		return (1);
	return (0);
}
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

t_par *check(int ac, char **av)
{
    int index;
    
    t_par *parm;
    index = 1;
    parm = malloc(sizeof(t_par));
    parm -> n_t_eat = -1;
    while (index < ac)
    {
       if (av[index] != NULL && ft_strlen(av[index]) != 0 && check_argv(av[index]))
        {
            if (index == 1)
                parm->n_philo= ft_atoi(av[index]);
            if (index == 2)
                parm->t_die = ft_atoi(av[index]);
            if (index == 4)
                parm->t_sleep = ft_atoi(av[index]);
            if (index == 3)
                parm->t_eat = ft_atoi(av[index]);
            if (index == 5)
			{
			
                parm->n_t_eat = ft_atoi(av[index]);
			}
        }
        else
            return 0;
        index++;
    }
    return parm;
}