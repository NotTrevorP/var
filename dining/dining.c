#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
#include<unistd.h>

sem_t room;
sem_t c[5];

void * posopher(void *);
void eat(int);
int main()
{
	int i,a[5];
	pthread_t tid[5];
	
	sem_init(&room,0,4);
	
	for(i=0;i<5;i++)
		sem_init(&c[i],0,1);
		
	for(i=0;i<5;i++){
		a[i]=i;
		pthread_create(&tid[i],NULL,posopher,(void *)&a[i]);
	}
	for(i=0;i<5;i++)
		pthread_join(tid[i],NULL);
}

void * posopher(void * num)
{
	int p=*(int *)num;

	sem_wait(&room);
	printf("\nPhilosopher %d has entered room and sat on the table",p);
	sem_wait(&c[p]);
	sem_wait(&c[(p+1)%5]);

	eat(p);
	sleep(2);
	printf("\nPhilosopher %d has finished eating and left the room",p);

	sem_post(&c[(p+1)%5]);
	sem_post(&c[p]);
	sem_post(&room);
}

void eat(int p)
{
	printf("\nPhilosopher %d is eating",p);
}