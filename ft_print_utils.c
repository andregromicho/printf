/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrandao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 14:31:48 by abrandao          #+#    #+#             */
/*   Updated: 2026/05/06 14:31:50 by abrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_print_char(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_print_str(char *str)
{
    int count;

    count = 0;
    if (!str)
        str = "(null)";
    while (str[count])
    {
        write(1, &str[count], 1);
        count++;
    }
    return (count);
}

int ft_print_nbr(int n)
{
    int count;

    count = 0;
    if (n == -2147483648)
        return (ft_print_str("-2147483648"));
    if (n < 0)
    {
        count += ft_print_char('-');
        n = -n;
    }
    if (n >= 10)
        count += ft_print_nbr(n / 10);
    count += ft_print_char((n % 10) + '0');
    return (count);
}

int ft_print_unbr(unsigned int n)
{
    int count;

    count = 0;
    if (n >= 10)
        count += ft_print_unbr(n / 10);
    count += ft_print_char((n % 10) + '0');
    return (count);
}
// unsigned int porque o número pode ser maior que um int, e não tem sinal, então não precisa se preocupar com números negativos.