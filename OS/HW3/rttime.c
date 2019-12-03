#include <stdio.h>
#include <sys/time.h>
#define MILLION 1000000

void function_to_time();

int main()
{
    struct timeval tpstart, tpend;
    long timediff;
    int i;

    gettimeofday(&tpstart, NULL);
    function_to_time();
    gettimeofday(&tpend, NULL);

    timediff = MILLION*(tpend.tv_sec - tpstart.tv_sec) + tpend.tv_usec - tpstart.tv_usec;

    printf("It took %ld msec \n", timediff);
}

void function_to_time()
{
    long i,t,s;
    for(i=0;i=999;i++)
    {
        t=i;
    }
}