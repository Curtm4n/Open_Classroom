/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_ou_moins.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdapurif <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 14:01:42 by cdapurif          #+#    #+#             */
/*   Updated: 2020/03/03 16:43:28 by curtman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "get_next_line.h"

long	ft_atoi(char *str)
{
	int		i;
	long	res;
	long	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(1, &str[i], 1);
}

void	ft_putnbr(long nbr)
{
	char n;

	if (nbr < 0)
	{
		write(1, "-", 1);
		nbr *= -1;
	}
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	n = (nbr % 10 + '0');
	write(1, &n, 1);
}

int		ft_error(long min, long max)
{
	if (min == max)
	{
		ft_putstr("Veuillez rentrer des nombres, differents l'un de l'autre\n");
		return (1);
	}
	if (min < 0 || max < 0)
	{
		ft_putstr("Veuillez rentrer des nombres positifs\n");
		return (1);
	}
	if (min > max)
	{
		ft_putstr("Le premier nombre rentre doit etre plus petit que le second\n");
		return (1);
	}
	if (min > 2147483647 || max > 2147483647)
	{
		ft_putstr("Votre nombre est superieur a la limite max --> 2 147 483 647\n");
		return (1);
	}
	return (0);
}

int		ft_check_input(char	*input)
{
	char	*stop;
	int i;

	stop = "exit";
	i = 0;
	while (input[i] == stop[i])
	{
		if (input[i] == '\0' && stop[i] == '\0')
		{
			ft_putstr("Vous quittez le jeu, a bientot !\n");
			exit(1);
		}
		i++;
	}
	i = -1;
	while (input[++i])
	{
		if (input[i] != ' ' && (input[i] < '0' || input[i] > '9'))
		{
			ft_putstr("Vous devez rentrer un nombre !\n\n");
			return (1);
		}
	}
	return (0);
}

int		ft_get_input(void)
{
	int		i;
	char	*input;

	i = -1;
	get_next_line(0, &input);
	while (ft_check_input(input))
	{
		ft_putstr("Quel est le nombre ? ");
		get_next_line(0, &input);
	}
	return (ft_atoi(input));
}

int		ft_replay(void)
{
	char	*input;

	while (1)
	{
		get_next_line(0, &input);
		if (input[0] == 'o' && input[1] == '\0')
		{
			ft_putstr("\nEt c'est repartit !\n\n");
			return (1);
		}
		if (input[0] == 'n' && input[1] == '\0')
		{
			ft_putstr("\nMerci d'avoir joue, a bientot !\n");
			return (0);
		}
		else
			ft_putstr("Vous devez rentrer les lettres o ou n uniquement\n");
	}
}

int		ft_loop(int myst_nbr)
{
	int		nbr_try;
	int		input;

	nbr_try = 1;
	ft_putstr("Quel est le nombre ? ");
	while ((input = ft_get_input()) != myst_nbr)
	{
		if (input < myst_nbr)
			ft_putstr("C'est plus !");
		else
			ft_putstr("C'est moins !");
		ft_putstr("\n\nQuel est le nombre ? ");
		nbr_try++;
	}
	ft_putstr("Bravo, vous avez trouve le nombre mystere en ");
	ft_putnbr(nbr_try);
	ft_putstr(" coups !\n\n");
	ft_putstr("Voulez-vous refaire une partie ?\n(Pour modifier min et max"
			" vous devez relancer le jeu ¯\\_(ツ)_/¯) o/n : ");
	return (ft_replay());
}

int		ft_pom(long min, long max)
{
	int		myst_nbr;
	if (ft_error(min, max))
		exit(1);
	ft_putstr("Bienvenue dans le jeu du plus ou moins!\n\nDans ce jeu l'objectif"
				" sera de deviner un nombre compris entre ");
	ft_putnbr(min);
	ft_putstr(" et ");
	ft_putnbr(max);
	ft_putstr(" inclus !\n\n\n");
	srand(time(NULL));
	myst_nbr = (rand() % (max - min + 1)) + min;
	return (ft_loop(myst_nbr));
}

int		main(int ac, char **av)
{
	int		replay;

	replay = 1;
	if (ac != 3)
	{
		ft_putstr("Vous devez donner en argument les nombres min et max\n");
		return (1);
	}
	while (replay)
		replay = ft_pom(ft_atoi(av[1]), ft_atoi(av[2]));
	return (0);
}
