#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

/*
이 프로그램은 기획의도에 따르면 main의 1-4뿐만 아니라 스레드를 새로 만들어 거기서 0부터 9까지 1초에 한번씩 출력해야 하지만, 
출력하지 않는다. 무엇이 문제이고 어떻게 해결해야 하는가?
*/

void	*thread_routine(void *arg)
{
	pthread_t	tid;
	int			i;

	tid = pthread_self();
	i = 0;
	printf("tid:%x\n", tid);
	while (i < 10)
	{
		printf("\t new thread : %d\n", i);
		i++;
		sleep(1);
	}
}

//pthread_self() : 현재 스레드 식별자 리턴
int	main()
{
	pthread_t	thread;
	int			i;

	i = 0;
	pthread_create(&thread, NULL, thread_routine, NULL);
	printf("tid: %x\n", pthread_self());
	while (i < 5)
	{
		printf("main:%d\n", i);
		i++;
		sleep(1);
	}
	pthread_join(thread, NULL);
}

//===========================================
//===  answer ===============================
//===========================================

/*
스레드 루틴에 따라 0~9까지 출력해야 하는데, main함수가 그냥 끝나버린다. main에서 sleep(2)를 해보면, 어떻게 돌아가는지 알 것이다.
그렇다면 위의 스레드가 끝나기 전 까지 메인스레드를 종료시키기 않고자 하면, 어떻게 해야할까?
/*

/*
pthread_join을 통해 대기시킬 수 있다. 어떤 스레드를 생성한 스레드가 끝날때까지 기다려준다. thread가 끝날때까지 메인이 끝나지 않는다.
int	main()
{
	pthread_t	*thread;
	int			i;

	i = 0;
	pthread_create(thread, NULL, thread_routine, NULL);
	printf("tid: %x\n", pthread_self());
	while (i < 5)
	{
		printf("main:%d\n", i);
		i++;
		sleep(1);
	}
	pthread_join(thread, NULL);
}
*/

/* tid값은 당연히 다를 것임.

tid: 1a481dc0
main:0
tid:dd0e000
         new thread : 0
main:1
         new thread : 1
main:2
         new thread : 2
         new thread : 3
main:3
         new thread : 4
main:4
         new thread : 5
         new thread : 6
         new thread : 7
         new thread : 8
         new thread : 9
*/