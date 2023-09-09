/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   philo.h											:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: dcerrato <dcerrato@student.42madrid.es>	+#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/09/08 18:37:26 by dcerrato		  #+#	#+#			 */
/*   Updated: 2023/09/08 18:53:45 by dcerrato		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>

typedef struct s_fork
{
	int				in_use;
	pthread_mutex_t	hold;
}	t_fork;

typedef struct s_philo
{
	int		id;
	int		live;
	void	*table;
	t_fork	*left;
	t_fork	*right;
}	t_philo;

typedef struct s_list
{
	pthread_t		thread;
	t_philo			*content;
	struct s_list	*next;
	struct s_list	*prev;
}	t_list;

typedef struct s_data
{
	int				num_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_meals;
	pthread_mutex_t	wr_stdout;
	t_list			*philos;
}	t_data;

int		ft_atoi(const char *str);

t_list	*ft_lstnew(t_philo *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_lstclear(t_list **lst, int num_nodes, void (*del)(void *));
void	ft_lstiter(t_list *lst, int num_nodes, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst, int num_nodes);

void	live(void *p);
void	init_philos(t_data *data);
void	free_philo(void *p);

#endif