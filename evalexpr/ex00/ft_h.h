/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_h.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eellie <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/17 17:02:05 by eellie            #+#    #+#             */
/*   Updated: 2020/08/08 16:21:00 by eellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H_H
# define FT_H_H

void	ft_putchar(char c);
void	ft_putnbr(int nb);
void	ft_putstr(char *str);
void	ft_plus(int a, int b);
void	ft_minus(int a, int b);
void	ft_div(int a, int b);
void	ft_mod(int a, int b);
void	ft_mul(int a, int b);
int		ft_atoi(char *str);
int		ft_strcmp(char *s1, char *s2);
int		do_op(int a, char *op, int b);
int		eval_expr(char *str);

typedef struct		s_btree
{
	struct s_btree	*left;
	struct s_btree	*right;
	void			*item;
}					t_btree;

t_btree	*btree_create_node(void *item);

#endif
