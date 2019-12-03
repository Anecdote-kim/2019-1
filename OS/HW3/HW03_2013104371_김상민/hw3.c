#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

char t1[] = "t1";
char t2[] = "t2";
char t3[] = "t3";
char t4[] = "t4";

volatile int global=0, m_global=0;

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void *t_plus(void *arg){
    int i;
    for(i=0;i<10000;i++)
    global++;
    printf("thread %s execution => result : %d \n",(char*)arg,global);
}

void *t_mutex_plus(void *arg){pthread_mutex_lock(&mutex);
    int i;
    for(i=0;i<10000;i++)
    m_global++;
    printf("mutex_thread %s execution => result : %d \n",(char*)arg,m_global);
    pthread_mutex_unlock(&mutex);
}

int main(int argc, char *argv[])
{
    pthread_t th1,th2,th3,th4;
    
    void *t_result;
    pthread_create(&th1,NULL,t_plus,&t1);
    pthread_create(&th2,NULL,t_plus,&t2);
    sleep(1);
    pthread_create(&th3,NULL,t_mutex_plus,&t3);
    pthread_create(&th4,NULL,t_mutex_plus,&t4);

    pthread_join(th1,&t_result);
    pthread_join(th2,&t_result);
    pthread_join(th3,&t_result);
    pthread_join(th4,&t_result);

    printf("global: %d\nm_global: %d\n",global,m_global);

    return 0;
}

