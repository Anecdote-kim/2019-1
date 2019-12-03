#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <pthread.h>
#define MILLION 1000000

int size, num_threads;
double **mat1, **mat2, **mat3 **mat4, **mat5, **mat6;

double ** allocate_mat(int size)
{
    double * vals = (double *) malloc(size*size*sizeof(double));
    double **ptrs = (double**) malloc(size*sizeof(double));
    int i;
    for(i=0;i<size;++i){
        ptrs[i]=&vals[i*size];
    }
    return ptrs;
}

void init_mat(double **mat, int size)
{
    int i,j;
    for(i=0;i<size;++i){
        for(j=0;j<size;++j){
            mat[i][j]=1.0;
        }
    }
}

void print_mat(double **mat, int size)
{
    int i,j;
    for(i=0;i<size;++i){
        for(j=0;j<size-1;++j){
            printf("%lf,",mat[i][j]);
        }
        printf("%lf",mat[i][j]);
        putchar('\n');
    }
}

void *worker(void *arg)
{
    int i,j,k,tid, portion_size, row_start, row_end;
    double sum;

    tid=*(int*)(arg);
    portion_size = size/num_threads;
    row_start = tid*portion_size;
    row_end = (tid+1)*portion_size;
    for(i=row_start;i<row_end;++i){
        for(j=0;j<size;++j){
            sum=0;
            for(k=0;k<size;++k){
                sum+=mat1[i][j]*mat2[k][j];
            }
            mat3[i][j]=sum;
        }
    }
}

int main(int argc, char *argv[])
{
    struct timeval tpstart,tpend;
    double timediff;
    int i;
    pthread_t * threads;

    if(argc !=3){
        fprintf( stderr, "%s <matrix size> <number of threads>\n", argv[0]);
        return -1;
    }

    size = atoi(argv[1]);
    num_threads=atoi( argv[2]);

    if (size%num_threads !=0){
        fprintf(stderr, "size %d must be a multiple of num of threads %d\n",size,num_threads);
        return -1;
    }

    threads = (pthread_t*) malloc(num_threads*sizeof(pthread_t));

    mat1=allocate_mat(size);
    mat2=allocate_mat(size);
    mat3=allocate_mat(size);

    init_mat(mat1,size);
    init_mat(mat2,size);

    if(size<=10){
        printf("Matrix 1:\n");
        print_mat(mat1,size);
        printf("Matrix 2:\n");
        print_mat(mat2,size);
    }

    gettimeofday(&tpstart,NULL);
    for(i=0;i<num_threads;i++)
    {
        int *tid;
        tid=(int*)malloc(sizeof(int));
        *tid=i;
        pthread_create(&threads[i], NULL, worker, (void*)tid);
    }
    
    for(i=0;i<num_threads;++i){
        pthread_join(threads[i],NULL);
    }
    gettimeofday(&tpend,NULL);

    if(size<=10){
        printf("Matrix 3:\n");
        print_mat(mat3,size);
    }
    
    timediff = MILLION*(tpend.tv_sec-tpstart.tv_sec)+tpend.tv_usec-tpstart.tv_usec;

    printf("It took %f msec in thread matrix \n",timediff);

    
    return 0;
}

