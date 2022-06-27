#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// 쓰레드 함수
// 1초를 기다린후 ^2 리턴한다.
void *t_function(void *data)
{
    int num = *((int *)data);
	printf("스레드 시작\n");
	printf("tid: %x\n", pthread_self());
    sleep(3);
	printf("스레드 종료\n");
}

int main()
{
    pthread_t p_thread;
    int thr_id;
    int status;
    int a = 100;

    printf("프로그램 시작\n"); 
	printf("main: %x\n", pthread_self());
    thr_id = pthread_create(&p_thread, NULL, t_function, (void *)&a);

    // 식별번호 p_thread 를 가지는 쓰레드를 detach 
 	//그러니까 스레드를 생성한 후 detach시켜준다. 종료된 후 자원을 반환한다.
    //pthread_detach(p_thread); 
	//프로세스 점유를 확인해야 하는데, 맥에선 왜 안되냐
	pause();
    return 0;
}