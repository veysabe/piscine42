/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssandman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 15:37:43 by ssandman          #+#    #+#             */
/*   Updated: 2020/08/12 23:02:59 by eellie           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_list.h"

int		g_lines = 0;
char	g_empty = 0;
char	g_obstacle = 0;
char	g_fill = 0;

int		handle1line(t_list **firstline, int **matrix, char **output)
{
	int		j;
	int		flag;
	t_list	*tmp;

	tmp = *firstline;
	j = 0;
	flag = 0;
	while (tmp)
	{
		if (tmp->data == g_obstacle)
			flag += 1;
		if (tmp->data == g_empty || tmp->data == g_obstacle)
		{
			output[0][j] = tmp->data;
			matrix[0][j] = flag;
		}
		else
			return (0);
		j++;
		tmp = tmp->next;
	}
	ft_list_clear(firstline);
	return (1);
}

void	line_iterator(int *vals)
{
	vals[0] += 1;
	vals[1] = -1;
	vals[2] = 0;
}

int		handleotherlines(int file, int len, int **matrix, char **output)
{
	char	buf[1];
	int		vals[3];

	vals[0] = 1;
	vals[1] = -1;
	vals[2] = 0;
	while (read(file, buf, 1))
	{
		vals[1] += 1;
		if (buf[0] == g_obstacle)
			vals[2] += 1;
		if (buf[0] == g_empty || buf[0] == g_obstacle)
		{
			matrix[vals[0]][vals[1]] = matrix[vals[0] - 1][vals[1]] + vals[2];
			output[vals[0]][vals[1]] = buf[0];
		}
		else if (buf[0] == '\n' && vals[1] == len)
			line_iterator(vals);
		else if (vals[1] < len || vals[1] > len
				|| buf[0] != g_obstacle || buf[0] != g_empty)
			return (0);
	}
	return (1);
}

void	look_around(int *val, int **matrix, int *r)
{
	val[0] = matrix[r[1]][r[2]];
	val[1] = (r[2] - r[0] >= 0) ? matrix[r[1]][r[2] - r[0]] : 0;
	val[2] = (r[1] - r[0] >= 0) ? matrix[r[1] - r[0]][r[2]] : 0;
	val[3] = (r[1] - r[0] >= 0 && r[2] - r[0] >= 0) ?
		matrix[r[1] - r[0]][r[2] - r[0]] : 0;
}

void	r_definer(int *r)
{
	r[0] = 1;
	r[1] = 0;
	r[2] = 0;
}

void	r_iterator(int *r)
{
	r[1] += 1;
	r[2] = 0;
}

void	map_printer(char **output, int *bsq)
{
	int i;
	int j;

	i = 0;
	j = 0;
	printf("size - %d i%d j%d\n", bsq[0], bsq[1], bsq[2]);
	while (i < g_lines)
	{
		j = 0;
		while (output[i][j])
		{
			if ((j > bsq[2] - bsq[0] && j <= bsq[2])
					&& (i > bsq[1] - bsq[0] && i <= bsq[1]) &&
					output[i][j] != g_obstacle)
				printf("%c ", g_fill);
			else
				printf("%c ", output[i][j]);
			j++;
		}
		i++;
		printf("\n");
	}
}

void	solver(int **matrix, int len, int *bsq, char **output)
{
	int val[4];
	int r[3];

	r_definer(r);
	while (r[1] < g_lines)
	{
		look_around(val, matrix, r);
		if ((val[0] - val[1] - val[2] + val[3]) < 1 && r[2] >= r[0])
		{
			bsq[0] = r[0];
			bsq[1] = r[1];
			bsq[2] = r[2];
			r_iterator(r);
			if (r[2] >= len)
				r[2] = r[0] - 1;
			r[0] += 1;
		}
		else
		{
			r[2] += 1;
			if (r[2] >= len)
				r_iterator(r);
		}
	}
	map_printer(output, bsq);
}

int		**arr_bldr(t_list **firstline, int len, int file)
{
	int		**matrix;
	char	**output;
	int		bsq[3];

	matrix = arr_mallocer(len);
	output = char_mallocer(len);
	if (!handle1line(firstline, matrix, output)
			|| !handleotherlines(file, len, matrix, output))
	{
		write(2, "Map error\n", 10);
		return (0);
	}
	solver(matrix, len, bsq, output);
	return (matrix);
}

void	make_globals(int file)
{
	char	content[1];

	while (read(file, content, 1) && content[0] != '\n')
	{
		if (content[0] >= '0' && content[0] <= '9')
		{
			g_lines *= 10;
			g_lines += (content[0] - '0');
		}
		else
		{
			g_empty = content[0];
			read(file, &g_obstacle, 1);
			read(file, &g_fill, 1);
		}
	}
}

int		make_first_line(t_list **firstline, int file)
{
	int		len;
	char	content[0];

	len = 0;
	while (content[0] != '\n')
	{
		ft_push_back(firstline, content[0]);
		read(file, content, 1);
		len++;
	}
	return (len);
}

int		reader(t_list **firstline, int file)
{
	char	content[0];
	int		len;

	len = 0;
	if (file == -1)
		return (0);
	else
		make_globals(file);
	read(file, content, 1);
	while (content[0] != '\n')
	{
		ft_push_back(firstline, content[0]);
		read(file, content, 1);
		len++;
	}
	return (len);
}

void	read_file(char *av)
{
	int		file;
	t_list	*firstline[1];
	int		len;

	len = 0;
	firstline[0] = NULL;
	if (av)
	{
		file = open(av, O_RDONLY);
		len = reader(firstline, file);
		if (len == 0)
		{
			write(2, "Read error\n", 11);
			return ;
		}
		arr_bldr(firstline, len, file);
		close(file);
	}
}

int		main(int ac, char **av)
{
	int i;

	i = ac;
	g_lines = 0;
	read_file(av[1]);
	printf("lines detected: %d\n", g_lines);
	printf("empty         : %c\n", g_empty);
	printf("obstacles     : %c\n", g_obstacle);
	printf("draw by       : %c\n", g_fill);
	return (0);
}
