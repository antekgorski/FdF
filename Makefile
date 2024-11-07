# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agorski <agorski@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/06 14:35:59 by agorski           #+#    #+#              #
#    Updated: 2024/11/07 18:22:17 by agorski          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

gcc main.c -L minilibx-linux -lmlx -lX11 -lXext
gcc main.c -L minilibx-linux -lmlx -lX11 -lXext -g -L libft++ -lft++