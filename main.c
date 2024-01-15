/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sekilinc <sekilinc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 17:45:24 by ahkalama          #+#    #+#             */
/*   Updated: 2024/01/10 19:58:40 by sekilinc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/cub3d.h"
#include <string.h>
#include <stdbool.h>

int myFunc(t_mlx *data)
{

	data->dmethod(data);
	return (0);
}

int main()
{
	t_mlx emerald;
	int a = 0;
	int b = 0;

	real_girl_mlx(a, b, &emerald);
	emerald.dmethod = &get_dialog;
	mlx_loop_hook(emerald.mlx_ptr, myFunc, &emerald);
	mlx_loop(emerald.mlx_ptr);
	return 0;
}
