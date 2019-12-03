#include <stdio.h>
void matrix_multiply(){
    int A[2][2]={{1,2},{3,4}};
    int B[2][2]={{5,6},{7,8}};
    int S[2][2];

    int i,j,k;
    int sum;

    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            sum=0;
            for(k=0; k<2; k++){
                sum+=A[i][k]*B[k][j];
            }
            S[i][j]=sum;
        }
    }

    for(i=0; i<2; i++){
        for(j=0; j<2; j++){
            printf("%d ",S[i][j]);
        }
        printf("\n");
    }

}

int main(void){
    matrix_multiply();
    return 0;
}