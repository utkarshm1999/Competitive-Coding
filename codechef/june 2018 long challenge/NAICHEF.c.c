#include<stdio.h>
#include<stdlib.h>


int main(){
    int N,T,A,B;
    int * dice;
    scanf("%d",&T);
    int i;
    for(i=0;i<T;i++){
        scanf("%d %d %d",&N,&A,&B);
        int j;
       
        dice=(int *) malloc(sizeof(int)*N);
         for(j=0;j<N;j++){
            scanf("%d",dice[j]);
        }
        int counter1;
        int countA,countB;
        countA=countB=0;
        for(counter1=0;counter1<N;counter1++){
            if(dice[counter1]==A){
                countA++;
                
            }
            if(dice[counter1]==B){
                countB++;
                
            }
        }
        
        float prob= (float)(countA*countB)/(N*N);
        printf("%f\n",prob);
    }
}