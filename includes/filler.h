/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: midoubih <midoubih@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/01/22 12:27:57 by midoubih          #+#    #+#             */
/*   Updated: 2014/01/23 13:47:49 by midoubih         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "../libft/includes/libft.h"

# define BUFF_SIZE 64

typedef struct		s_board
{
	char		**field;
	int			length;
	int			width;
}					t_board;

typedef struct		s_board t_piece;

/*
**		ft_gnl.c (Get_Next_Line)
*/
int				ft_gnl(int const fd, char **line);

/*
**		get_fct.c
*/
t_board			*get_board();
t_piece			*get_piece();

/*
**		is_fct.c
*/
int				is_shape(char c);
int				is_dot(char c);
int				is_piece(char c);

#endif /* !FILLER_H */
