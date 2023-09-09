#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct s_param
{
	int id;
}	t_param;

void *func(void *p)
{
	t_param *param;

	param = (t_param *)p;
	printf("%d\n", param->id);
}

int main()
{
	t_param		p;
	pthread_t	h;

	p.id = 1;

	pthread_create(&h, 0, func, (void *)&p);
	pthread_join(h, 0);
}