# pthread
스레드와 뮤텍스를 익혀보자

### 스레드란?
스레드는 어떤 프로그램에서 프로세스가 실행되는 흐름의 단위  
스레드는 메모리를 공유한다. data, code, file 영역을 공유한다.  
스택은 스레드마다 독립적으로 가지고 있다.  

---
### pthread_create
~~~
int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void *(*start_routine)(void*), void *arg)
~~~
man 참고.

### pthread_join
스레드를 생성한 스레드가 끝날 때까지 기다려준다.

### pthread_detach
해당 스레드를 분리하고 종료될 때 스레드의 자원을 반환한다.