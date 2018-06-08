#include<stdio.h>
#include<stdlib.h>

int main(void){
    unsigned long long int T,A,B,nA,nB,testA,testB,i;
    scanf("%lu",&T);
    //int i;
    for(i=0;i<T;i++){
        scanf("%lu %lu",&A,&B);
        testA=A;
        testB=B-1;
        nA=nB=0;
        if(A==B){
            printf("0\n");
        }
        else if((B==1 && A!=0) || B==0){
            printf("-1\n");

        }

        else{

            while(testA!=0){
                if(testA%2==1) nA++;
                testA=testA/2;
            }

            while(testB!=0){
                if(testB%2==1)nB++;
                testB=testB/2;
            }

            if(nA<=nB){
                printf("%lu\n", nB-nA+1);
            }
            else{
                printf("2\n");
            }
        }
    }

}
