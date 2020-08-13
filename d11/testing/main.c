#include "ft_list.h"
#include <stdlib.h>
#include "stdio.h"
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_push_front(t_list **begin_list, void *data);

void	print_list(t_list *list)
{
	ft_putstr(list->data);
	ft_putchar('\n');
}

void	print_all_elements(t_list *list)
{
	int i = 0;
	while (list != NULL)
	{
		print_list(list);
		list = list->next;
	}
}

void	print_last_element(t_list *begin_list)
{
	if (begin_list == NULL)
		return ;
	while (begin_list->next != NULL)
		begin_list = begin_list->next;
	print_list(begin_list);
}

t_list		*ft_list_last(t_list *begin_list)
{
	if (begin_list == 0)

	while (begin_list->next != NULL)
		begin_list = begin_list->next;
	return (begin_list);
}

int		ft_list_size(t_list *begin_list)
{
	int		i;
	t_list	*temp;


	temp = begin_list;
	i = 0;
	while (temp != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

t_list *ft_list_push_params(int ac, char **av)
{
	int 	i;
	t_list	*nl;

	i = 0;
	nl = 0;
	while (i < ac)
	{
		ft_list_push_front(&nl, av[i]);
		++i;
	}
	return (nl);
}

void ft_list_clear(t_list **begin_list)
{
	while (*begin_list && ((*begin_list)->next != NULL))
		ft_list_clear(&(*begin_list)->next);
	free(*begin_list);
	*begin_list = NULL;
}

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
	while (nbr > 0 && begin_list)
	{
		begin_list = begin_list->next;
		nbr--;
	}
	if (begin_list)
		return (begin_list);
	else
		return (0);
}

void	ft_list_reverse(t_list **begin_list)
{
	t_list	*current;
	t_list	*prev;
	t_list	*next;

	current = *begin_list;
	prev = 0;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	*begin_list = prev;
}

int		main(int argc, char **argv)
{
	int i = 1;

	t_list *list;
	t_list **ptr = &list;

	
	while (argv[i] != '\0')
	{
		ft_list_push_back(ptr, argv[i]);
		i++;
	}
	
	//*ptr = ft_list_push_params(argc, argv);
	ft_putstr("All list elements: \n-----\n");
	print_all_elements(list);
	ft_putstr("Clear: \n-----\n");
	ft_list_clear(&list);
	print_all_elements(list);
	ft_putstr("-----\n");
}
