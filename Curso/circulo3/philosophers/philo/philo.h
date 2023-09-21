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

typedef struct s_philo
{
	int				id;
	int				num_meals;
	useconds_t		last_meal;
	pthread_mutex_t	wait;
	pthread_mutex_t	fork;
	struct s_philo	*right;
	void			*table;
}	t_philo;

typedef struct s_list
{
	pthread_t		thread;
	t_philo			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_data
{
	int				num_philos;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				num_meals;
	int				complete_meals;
	useconds_t		init_time;		
	pthread_mutex_t	wr_stdout;
	pthread_mutex_t	dead;
	t_list			*philos;
}	t_data;

int			check_arg(char *arg);
int			ft_atoi(const char *str);
useconds_t	get_time_in_ms(void);
void		ft_usleep(long long time);

t_list		*ft_lstnew(t_philo *content);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstclear(t_list **lst, int num_nodes, void (*del)(void *));
void		ft_lstiter(t_list *lst, int num_nodes, void (*f)(void *));
t_list		*ft_lstlast(t_list *lst, int num_nodes);

void		*exist(void *p);
void		init_philos(t_data *data);
void		free_philo(void *p);

#endif