/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:03:21 by deelliot          #+#    #+#             */
/*   Updated: 2022/02/21 12:46:13 by deelliot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_max(int x, int y)
{
	if (!x && !y)
		return (0);
	if (!x)
		return (y);
	if (!y)
		return (x);
	if (x > y)
		return (x);
	else
		return (y);
}
