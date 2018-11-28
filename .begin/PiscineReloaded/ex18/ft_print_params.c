/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kemartin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/31 11:46:42 by kemartin          #+#    #+#             */
/*   Updated: 2018/08/31 13:02:52 by kemartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

void	ft_print_params(int ac, char **av)
{
	int i;
	int j;

	i = 1;
	while (i < ac)
	{
		j = -1;
		while (av[i][++j] != '\0')
			ft_putchar(av[i][j]);
		ft_putchar('\n');
		i++;
	}
}

int		main(int ac, char **av)
{
	ft_print_params(ac, av);
	return (0);
}
