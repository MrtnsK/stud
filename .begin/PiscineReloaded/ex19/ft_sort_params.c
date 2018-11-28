/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 12:12:15 by kemartin          #+#    #+#             */
/*   Updated: 2018/08/31 13:04:59 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	display(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		while (av[i][j] != '\0')
		{
			ft_putchar(av[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	ft_sort_params(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac - 1)
	{
		while (ft_strcmp(av[i + 1], av[i]) < 0 && i < ac)
		{
			av[ac + 1] = av[i];
			av[i] = av[i + 1];
			av[i + 1] = av[ac + 1];
			i = 0;
		}
		i++;
	}
	display(ac, av);
}

int		main(int ac, char **av)
{
	ft_sort_params(ac, av);
	return (0);
}
