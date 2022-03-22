/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: deelliot <deelliot@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:31:46 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/17 14:17:50 by deelliot         ###   ########.fr       */
=======
/*   By: trnguyen <trnguyen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 16:31:46 by deelliot          #+#    #+#             */
/*   Updated: 2022/03/21 12:22:20 by trnguyen         ###   ########.fr       */
>>>>>>> e3d9b7e172bf12407f56705be3e00770450c9787
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_array(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
<<<<<<< HEAD
	{
		ft_putendl(array[i]);
		i++;
	}
=======
		ft_putendl(array[i++]);
>>>>>>> e3d9b7e172bf12407f56705be3e00770450c9787
}
